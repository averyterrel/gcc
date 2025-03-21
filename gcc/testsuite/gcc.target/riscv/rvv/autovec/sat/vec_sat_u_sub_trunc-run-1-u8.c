/* { dg-do run { target { riscv_v } } } */
/* { dg-additional-options "-std=c99" } */

#include "vec_sat_arith.h"

#define OUT_T              uint8_t
#define IN_T               uint16_t
#define N                  16
#define RUN_VEC_SAT_BINARY RUN_VEC_SAT_U_SUB_TRUNC_FMT_1 

DEF_VEC_SAT_U_SUB_TRUNC_FMT_1(OUT_T, IN_T)

OUT_T expect_data[][N] = {
  {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
  },
  {
    254, 255, 4, 0,
    254, 255, 4, 0,
    254, 255, 4, 0,
    254, 255, 4, 0,
  },
  {
    23, 0, 0, 2,
    23, 0, 0, 2,
    23, 0, 0, 2,
    23, 0, 0, 2,
  },
  {
    254, 43, 0, 255,
    254, 43, 0, 255,
    254, 43, 0, 255,
    254, 43, 0, 255,
  },
};

IN_T op_1_data[][N] = {
  {
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
    0, 0, 0, 0,
  },
  {
    65535, 256, 5, 0,
    65535, 256, 5, 0,
    65535, 256, 5, 0,
    65535, 256, 5, 0,
  },
  {
    65535, 1024, 5, 65002,
    65535, 1024, 5, 65002,
    65535, 1024, 5, 65002,
    65535, 1024, 5, 65002,
  },
  {
    65535, 300, 256, 512,
    65535, 300, 256, 512,
    65535, 300, 256, 512,
    65535, 300, 256, 512,
  },
};

IN_T op_2_data[] = {
  0,
  1,
  65000,
  257,
};

#include "vec_sat_binary_vvx_run.h"
