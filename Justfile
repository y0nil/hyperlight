
alias build-rust-debug := build-rust
set windows-shell := ["pwsh.exe", "-NoLogo", "-Command"]
bin-suffix := if os() == "windows" { ".bat" } else { ".sh" }
fb-cmake-option:= if os() == "windows" { "Visual Studio 10" } else { "Unix Makefiles" }
default-target:= "debug"

init:
    git submodule update --init --recursive

install-vcpkg:
    cd .. && git clone https://github.com/Microsoft/vcpkg.git || cd -
    cd ../vcpkg && ./bootstrap-vcpkg{{ bin-suffix }} && ./vcpkg integrate install || cd -

install-flatbuffers-with-vcpkg: install-vcpkg
    cd ../vcpkg && ./vcpkg install flatbuffers || cd -

update-dlmalloc:
    curl -Lv -o src/HyperlightGuest/third_party/dlmalloc/malloc.h https://gee.cs.oswego.edu/pub/misc/malloc.h
    curl -Lv -o src/HyperlightGuest/third_party/dlmalloc/malloc.c https://gee.cs.oswego.edu/pub/misc/malloc.c
    cd src/HyperlightGuest/third_party/dlmalloc && git apply --whitespace=nowarn --verbose malloc.patch || cd ../../../..

build-dotnet:
    cd src/Hyperlight && dotnet build || cd ../../
    cd src/examples/NativeHost && dotnet build || cd ../../../

build-rust target=default-target:
    cargo build --verbose --profile={{ if target == "debug" {"dev"} else { target } }}

build: build-rust build-dotnet
    echo "built all .Net and Rust projects"

test-rust:
    cargo test -- --nocapture

test-dotnet-hl:
    cd src/tests/Hyperlight.Tests && dotnet test || cd ../../../

test-dotnet-nativehost:
    cd src/examples/NativeHost && dotnet run -- -nowait || cd ../../../

test-dotnet: test-dotnet-hl test-dotnet-nativehost

test-capi target=default-target:
    cd src/hyperlight_host && just run-tests-capi {{ target }} || cd ../../

valgrind-capi target=default-target:
    cd src/hyperlight_host && just valgrind-tests-capi {{ target }} || cd ../../

test: test-rust test-dotnet valgrind-capi test-capi

check:
    cargo check
fmt-check:
    cargo fmt --all -- --check
fmt: 
    cargo fmt
clippy:
    cargo clippy --all-targets --all-features -- -D warnings

gen-all-fbs-rust-code:
    echo 
    for fbs in `find src -name "*.fbs"`; do flatc -r --rust-module-root-file --gen-all -o ./src/hyperlight_host/src/flatbuffers/ $fbs; done

gen-all-fbs-csharp-code:
    for fbs in `find src -name "*.fbs"`; do flatc -n -o ./src/Hyperlight/flatbuffers $fbs; done

gen-all-fbs-c-code:
    for fbs in `find src -name "*.fbs"`; do flatcc -a -o ./src/HyperlightGuest/include/flatbuffers/generated $fbs; done