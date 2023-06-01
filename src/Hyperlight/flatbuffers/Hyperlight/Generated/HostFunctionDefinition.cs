// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace Hyperlight.Generated
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct HostFunctionDefinition : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_23_5_26(); }
  public static HostFunctionDefinition GetRootAsHostFunctionDefinition(ByteBuffer _bb) { return GetRootAsHostFunctionDefinition(_bb, new HostFunctionDefinition()); }
  public static HostFunctionDefinition GetRootAsHostFunctionDefinition(ByteBuffer _bb, HostFunctionDefinition obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public static bool VerifyHostFunctionDefinition(ByteBuffer _bb) {Google.FlatBuffers.Verifier verifier = new Google.FlatBuffers.Verifier(_bb); return verifier.VerifyBuffer("", false, HostFunctionDefinitionVerify.Verify); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public HostFunctionDefinition __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public string FunctionName { get { int o = __p.__offset(4); return o != 0 ? __p.__string(o + __p.bb_pos) : null; } }
#if ENABLE_SPAN_T
  public Span<byte> GetFunctionNameBytes() { return __p.__vector_as_span<byte>(4, 1); }
#else
  public ArraySegment<byte>? GetFunctionNameBytes() { return __p.__vector_as_arraysegment(4); }
#endif
  public byte[] GetFunctionNameArray() { return __p.__vector_as_array<byte>(4); }
  public Hyperlight.Generated.ParameterType Parameters(int j) { int o = __p.__offset(6); return o != 0 ? (Hyperlight.Generated.ParameterType)__p.bb.Get(__p.__vector(o) + j * 1) : (Hyperlight.Generated.ParameterType)0; }
  public int ParametersLength { get { int o = __p.__offset(6); return o != 0 ? __p.__vector_len(o) : 0; } }
#if ENABLE_SPAN_T
  public Span<Hyperlight.Generated.ParameterType> GetParametersBytes() { return __p.__vector_as_span<Hyperlight.Generated.ParameterType>(6, 1); }
#else
  public ArraySegment<byte>? GetParametersBytes() { return __p.__vector_as_arraysegment(6); }
#endif
  public Hyperlight.Generated.ParameterType[] GetParametersArray() { int o = __p.__offset(6); if (o == 0) return null; int p = __p.__vector(o); int l = __p.__vector_len(o); Hyperlight.Generated.ParameterType[] a = new Hyperlight.Generated.ParameterType[l]; for (int i = 0; i < l; i++) { a[i] = (Hyperlight.Generated.ParameterType)__p.bb.Get(p + i * 1); } return a; }
  public Hyperlight.Generated.ReturnType ReturnType { get { int o = __p.__offset(8); return o != 0 ? (Hyperlight.Generated.ReturnType)__p.bb.Get(o + __p.bb_pos) : Hyperlight.Generated.ReturnType.hlint; } }

  public static Offset<Hyperlight.Generated.HostFunctionDefinition> CreateHostFunctionDefinition(FlatBufferBuilder builder,
      StringOffset function_nameOffset = default(StringOffset),
      VectorOffset parametersOffset = default(VectorOffset),
      Hyperlight.Generated.ReturnType return_type = Hyperlight.Generated.ReturnType.hlint) {
    builder.StartTable(3);
    HostFunctionDefinition.AddParameters(builder, parametersOffset);
    HostFunctionDefinition.AddFunctionName(builder, function_nameOffset);
    HostFunctionDefinition.AddReturnType(builder, return_type);
    return HostFunctionDefinition.EndHostFunctionDefinition(builder);
  }

  public static void StartHostFunctionDefinition(FlatBufferBuilder builder) { builder.StartTable(3); }
  public static void AddFunctionName(FlatBufferBuilder builder, StringOffset functionNameOffset) { builder.AddOffset(0, functionNameOffset.Value, 0); }
  public static void AddParameters(FlatBufferBuilder builder, VectorOffset parametersOffset) { builder.AddOffset(1, parametersOffset.Value, 0); }
  public static VectorOffset CreateParametersVector(FlatBufferBuilder builder, Hyperlight.Generated.ParameterType[] data) { builder.StartVector(1, data.Length, 1); for (int i = data.Length - 1; i >= 0; i--) builder.AddByte((byte)data[i]); return builder.EndVector(); }
  public static VectorOffset CreateParametersVectorBlock(FlatBufferBuilder builder, Hyperlight.Generated.ParameterType[] data) { builder.StartVector(1, data.Length, 1); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateParametersVectorBlock(FlatBufferBuilder builder, ArraySegment<Hyperlight.Generated.ParameterType> data) { builder.StartVector(1, data.Count, 1); builder.Add(data); return builder.EndVector(); }
  public static VectorOffset CreateParametersVectorBlock(FlatBufferBuilder builder, IntPtr dataPtr, int sizeInBytes) { builder.StartVector(1, sizeInBytes, 1); builder.Add<Hyperlight.Generated.ParameterType>(dataPtr, sizeInBytes); return builder.EndVector(); }
  public static void StartParametersVector(FlatBufferBuilder builder, int numElems) { builder.StartVector(1, numElems, 1); }
  public static void AddReturnType(FlatBufferBuilder builder, Hyperlight.Generated.ReturnType returnType) { builder.AddByte(2, (byte)returnType, 0); }
  public static Offset<Hyperlight.Generated.HostFunctionDefinition> EndHostFunctionDefinition(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    builder.Required(o, 4);  // function_name
    return new Offset<Hyperlight.Generated.HostFunctionDefinition>(o);
  }
  public static void FinishHostFunctionDefinitionBuffer(FlatBufferBuilder builder, Offset<Hyperlight.Generated.HostFunctionDefinition> offset) { builder.Finish(offset.Value); }
  public static void FinishSizePrefixedHostFunctionDefinitionBuffer(FlatBufferBuilder builder, Offset<Hyperlight.Generated.HostFunctionDefinition> offset) { builder.FinishSizePrefixed(offset.Value); }

  public static VectorOffset CreateSortedVectorOfHostFunctionDefinition(FlatBufferBuilder builder, Offset<HostFunctionDefinition>[] offsets) {
    Array.Sort(offsets,
      (Offset<HostFunctionDefinition> o1, Offset<HostFunctionDefinition> o2) =>
        new HostFunctionDefinition().__assign(builder.DataBuffer.Length - o1.Value, builder.DataBuffer).FunctionName.CompareTo(new HostFunctionDefinition().__assign(builder.DataBuffer.Length - o2.Value, builder.DataBuffer).FunctionName));
    return builder.CreateVectorOfTables(offsets);
  }

  public static HostFunctionDefinition? __lookup_by_key(int vectorLocation, string key, ByteBuffer bb) {
    HostFunctionDefinition obj_ = new HostFunctionDefinition();
    int span = bb.GetInt(vectorLocation - 4);
    int start = 0;
    while (span != 0) {
      int middle = span / 2;
      int tableOffset = Table.__indirect(vectorLocation + 4 * (start + middle), bb);
      obj_.__assign(tableOffset, bb);
      int comp = obj_.FunctionName.CompareTo(key);
      if (comp > 0) {
        span = middle;
      } else if (comp < 0) {
        middle++;
        start += middle;
        span -= middle;
      } else {
        return obj_;
      }
    }
    return null;
  }
}


static public class HostFunctionDefinitionVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyString(tablePos, 4 /*FunctionName*/, true)
      && verifier.VerifyVectorOfData(tablePos, 6 /*Parameters*/, 1 /*Hyperlight.Generated.ParameterType*/, false)
      && verifier.VerifyField(tablePos, 8 /*ReturnType*/, 1 /*Hyperlight.Generated.ReturnType*/, 1, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}

}
