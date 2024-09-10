// <auto-generated>
//  automatically generated by the FlatBuffers compiler, do not modify
// </auto-generated>

namespace Hyperlight.Generated
{

using global::System;
using global::System.Collections.Generic;
using global::Google.FlatBuffers;

public struct hldouble : IFlatbufferObject
{
  private Table __p;
  public ByteBuffer ByteBuffer { get { return __p.bb; } }
  public static void ValidateVersion() { FlatBufferConstants.FLATBUFFERS_24_3_25(); }
  public static hldouble GetRootAshldouble(ByteBuffer _bb) { return GetRootAshldouble(_bb, new hldouble()); }
  public static hldouble GetRootAshldouble(ByteBuffer _bb, hldouble obj) { return (obj.__assign(_bb.GetInt(_bb.Position) + _bb.Position, _bb)); }
  public void __init(int _i, ByteBuffer _bb) { __p = new Table(_i, _bb); }
  public hldouble __assign(int _i, ByteBuffer _bb) { __init(_i, _bb); return this; }

  public double Value { get { int o = __p.__offset(4); return o != 0 ? __p.bb.GetDouble(o + __p.bb_pos) : (double)0.0; } }

  public static Offset<Hyperlight.Generated.hldouble> Createhldouble(FlatBufferBuilder builder,
      double value = 0.0) {
    builder.StartTable(1);
    hldouble.AddValue(builder, value);
    return hldouble.Endhldouble(builder);
  }

  public static void Starthldouble(FlatBufferBuilder builder) { builder.StartTable(1); }
  public static void AddValue(FlatBufferBuilder builder, double value) { builder.AddDouble(0, value, 0.0); }
  public static Offset<Hyperlight.Generated.hldouble> Endhldouble(FlatBufferBuilder builder) {
    int o = builder.EndTable();
    return new Offset<Hyperlight.Generated.hldouble>(o);
  }
  public hldoubleT UnPack() {
    var _o = new hldoubleT();
    this.UnPackTo(_o);
    return _o;
  }
  public void UnPackTo(hldoubleT _o) {
    _o.Value = this.Value;
  }
  public static Offset<Hyperlight.Generated.hldouble> Pack(FlatBufferBuilder builder, hldoubleT _o) {
    if (_o == null) return default(Offset<Hyperlight.Generated.hldouble>);
    return Createhldouble(
      builder,
      _o.Value);
  }
}

public class hldoubleT
{
  public double Value { get; set; }

  public hldoubleT() {
    this.Value = 0.0;
  }
}


static public class hldoubleVerify
{
  static public bool Verify(Google.FlatBuffers.Verifier verifier, uint tablePos)
  {
    return verifier.VerifyTableStart(tablePos)
      && verifier.VerifyField(tablePos, 4 /*Value*/, 8 /*double*/, 8, false)
      && verifier.VerifyTableEnd(tablePos);
  }
}

}
