#ifdef __FLT_EVAL_METHOD__
#define FLT_EVAL_METHOD __FLT_EVAL_METHOD__
#else
#define FLT_EVAL_METHOD 0
#endif
#ifdef _MSC_VER
#define LDBL_EPSILON 2.2204460492503131e-016
#define LDBL_MIN     2.2250738585072014e-308
#define LDBL_MAX     1.7976931348623158e+308
#define LDBL_MANT_DIG 53
#define LDBL_MIN_EXP (-1021)
#define LDBL_MAX_EXP 1024
#define LDBL_DIG 15
#define LDBL_MIN_10_EXP (-307)
#define LDBL_MAX_10_EXP 308
#else
#define LDBL_EPSILON 1.0842021724855044340e-19L
#define LDBL_MIN     3.3621031431120935063e-4932L
#define LDBL_MAX     1.1897314953572317650e+4932L
#define LDBL_MANT_DIG 64
#define LDBL_MAX_EXP 16384
#define LDBL_DIG 18
#define LDBL_MIN_10_EXP (-4931)
#define LDBL_MAX_10_EXP 4932
#endif
#define LDBL_TRUE_MIN 3.6451995318824746025e-4951L
#define DECIMAL_DIG 21