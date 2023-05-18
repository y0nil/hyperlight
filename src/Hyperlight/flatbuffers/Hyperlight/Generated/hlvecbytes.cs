// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace Hyperlight.Generated
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct hlvecbytes : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_23_3_3(); }
  public static hlvecbytes GetRootAshlvecbytes(ByteBuffer _bb) { return GetRootAshlvecbytes(_bb, new hlvecbytes()); }
  public static hlvecbytes GetRootAshlvecbytes(ByteBuffer _bb, hlvecbytes obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public hlvecbytes __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public byte Value(int j) { int o = __p.__offset(4); return o != 0 ? __p.bb.Get(__p.__vector(o) + j * 1) : (byte)0; }
  public int ValueLength { get { int o = __p.__offset(4); return o != 0 ? __p.__vector_len(o) : 0; } }
#if ENABLE_SPAN_T
  public Span<byte> GetValueBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetValueBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetValueArray() { return __p.__vector_as_array<byte>(4); }

  public static Offset<Hyperlight.Generated.hlvecbytes> Createhlvecbytes(FlatBufferBuilder builder,
      VectorOffset valueOffset = default(VectorOffset)) {
    builder.StartTable(1);
    hlvecbytes.AddValue(builder, valueOffset);
    return hlvecbytes.Endhlvecbytes(builder);
  }

  public static void Starthlvecbytes(FlatBufferBuilder builder) { builder.StartTable(1); }
  public static void AddValue(FlatBufferBuilder builder, VectorOffset valueOffset) { builder.AddOffset(0, valueOffset.Value, 0); }
  public static VectorOffset CreateValueVector(FlatBufferBuilder builder, byte[] data) { builder.StartVector(1, data.Length, 1); for (int i = data.Length - 1; i >= 0; i--) builder.AddByte(data[i]); return builder.EndVector(); }
  public static VectorOffset CreateValueVectorBlock(FlatBufferBuilder builder, byte[] data) { builder.StartVector(1, data.Length, 1); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateValueVectorBlock(FlatBufferBuilder builder, ArraySegment<byte> data) { builder.StartVector(1, data.Count, 1); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateValueVectorBlock(FlatBufferBuilder builder, IntPtr dataPtr, int sizeInBytes) { builder.StartVector(1, sizeInBytes, 1); builder.Add<byte>(dataPtr, sizeInBytes); return builder.EndVector(); }
  public static void StartValueVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(1, numElems, 1); }
  public static Offset<Hyperlight.Generated.hlvecbytes> Endhlvecbytes(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<Hyperlight.Generated.hlvecbytes>(o);
  }
}


}