// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace Hyperlight.Generated
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct HostFunctionDetails : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_24_3_25(); }
  public static HostFunctionDetails GetRootAsHostFunctionDetails(ByteBuffer _bb) { return GetRootAsHostFunctionDetails(_bb, new HostFunctionDetails()); }
  public static HostFunctionDetails GetRootAsHostFunctionDetails(ByteBuffer _bb, HostFunctionDetails obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public static bool VerifyHostFunctionDetails(ByteBuffer _bb) {Google.FlatBuffers.Verifier verifier = new Google.FlatBuffers.Verifier(_bb); return verifier.VerifyBuffer("", false, HostFunctionDetailsVerify.Verify); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public HostFunctionDetails __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public Hyperlight.Generated.HostFunctionDefinition? Functions(int j) { int o = __p.__offset(4); return o != 0 ? (Hyperlight.Generated.HostFunctionDefinition?)(new Hyperlight.Generated.HostFunctionDefinition()).__assign(__p.__indirect(__p.__vector(o) + j * 4), __p.bb) : null; }
  public int FunctionsLength { get { int o = __p.__offset(4); return o != 0 ? __p.__vector_len(o) : 0; } }
  public Hyperlight.Generated.HostFunctionDefinition? FunctionsByKey(string key) { int o = __p.__offset(4); return o != 0 ? Hyperlight.Generated.HostFunctionDefinition.__lookup_by_key(__p.__vector(o), key, __p.bb) : null; }

  public static Offset<Hyperlight.Generated.HostFunctionDetails> CreateHostFunctionDetails(FlatBufferBuilder builder,
      VectorOffset functionsOffset = default(VectorOffset)) {
    builder.StartTable(1);
    HostFunctionDetails.AddFunctions(builder, functionsOffset);
    return HostFunctionDetails.EndHostFunctionDetails(builder);
  }

  public static void StartHostFunctionDetails(FlatBufferBuilder builder) { builder.StartTable(1); }
  public static void AddFunctions(FlatBufferBuilder builder, VectorOffset functionsOffset) { builder.AddOffset(0, functionsOffset.Value, 0); }
  public static VectorOffset CreateFunctionsVector(FlatBufferBuilder builder, Offset<Hyperlight.Generated.HostFunctionDefinition>[] data) { builder.StartVector(4, data.Length, 4); for (int i = data.Length - 1; i >= 0; i--) builder.AddOffset(data[i].Value); return builder.EndVector(); }
  public static VectorOffset CreateFunctionsVectorBlock(FlatBufferBuilder builder, Offset<Hyperlight.Generated.HostFunctionDefinition>[] data) { builder.StartVector(4, data.Length, 4); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateFunctionsVectorBlock(FlatBufferBuilder builder, ArraySegment<Offset<Hyperlight.Generated.HostFunctionDefinition>> data) { builder.StartVector(4, data.Count, 4); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateFunctionsVectorBlock(FlatBufferBuilder builder, IntPtr dataPtr, int sizeInBytes) { builder.StartVector(1, sizeInBytes, 1); builder.Add<Offset<Hyperlight.Generated.HostFunctionDefinition>>(dataPtr, sizeInBytes); return builder.EndVector(); }
  public static void StartFunctionsVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(4, numElems, 4); }
  public static Offset<Hyperlight.Generated.HostFunctionDetails> EndHostFunctionDetails(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<Hyperlight.Generated.HostFunctionDetails>(o);
  }
  public static void FinishHostFunctionDetailsBuffer(FlatBufferBuilder builder, Offset<Hyperlight.Generated.HostFunctionDetails> offset) { builder.Finish(offset.Value); }
  public static void FinishSizePrefixedHostFunctionDetailsBuffer(FlatBufferBuilder builder, Offset<Hyperlight.Generated.HostFunctionDetails> offset) { builder.FinishSizePrefixed(offset.Value); }
  public HostFunctionDetailsT UnPack() {
    var _o = new HostFunctionDetailsT();
    this.UnPackTo(_o);
    return _o;
  }
  public void UnPackTo(HostFunctionDetailsT _o) {
    _o.Functions = new List<Hyperlight.Generated.HostFunctionDefinitionT>();
    for (var _j = 0; _j < this.FunctionsLength; ++_j) {_o.Functions.Add(this.Functions(_j).HasValue ? this.Functions(_j).Value.UnPack() : null);}
  }
  public static Offset<Hyperlight.Generated.HostFunctionDetails> Pack(FlatBufferBuilder builder, HostFunctionDetailsT _o) {
    if (_o == null) return default(Offset<Hyperlight.Generated.HostFunctionDetails>);
    var _functions = default(VectorOffset);
    if (_o.Functions != null) {
      var __functions = new Offset<Hyperlight.Generated.HostFunctionDefinition>[_o.Functions.Count];
      for (var _j = 0; _j < __functions.Length; ++_j) { __functions[_j] = Hyperlight.Generated.HostFunctionDefinition.Pack(builder, _o.Functions[_j]); }
      _functions = CreateFunctionsVector(builder, __functions);
    }
    return CreateHostFunctionDetails(
      builder,
      _functions);
  }
}

public class HostFunctionDetailsT
{
  public List<Hyperlight.Generated.HostFunctionDefinitionT> Functions { get; set; }

  public HostFunctionDetailsT() {
    this.Functions = null;
  }
  public static HostFunctionDetailsT DeserializeFromBinary(byte[] fbBuffer) {
    return HostFunctionDetails.GetRootAsHostFunctionDetails(new ByteBuffer(fbBuffer)).UnPack();
  }
  public byte[] SerializeToBinary() {
    var fbb = new FlatBufferBuilder(0x10000);
    HostFunctionDetails.FinishHostFunctionDetailsBuffer(fbb, HostFunctionDetails.Pack(fbb, this));
    return fbb.DataBuffer.ToSizedArray();
  }
}


static public class HostFunctionDetailsVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyVectorOfTables(tablePos, 4 /*Functions*/, Hyperlight.Generated.HostFunctionDefinitionVerify.Verify, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}

}
