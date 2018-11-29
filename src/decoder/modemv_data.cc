/* -*-mode:c++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

/* Copyright 2013-2018 the Alfalfa authors
                       and the Massachusetts Institute of Technology

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:

      1. Redistributions of source code must retain the above copyright
         notice, this list of conditions and the following disclaimer.

      2. Redistributions in binary form must reproduce the above copyright
         notice, this list of conditions and the following disclaimer in the
         documentation and/or other materials provided with the distribution.

   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE. */

#include "modemv_data.hh"

using namespace std;

const ProbabilityArray< num_y_modes > kf_y_mode_probs = {{ 145, 156, 163, 128 }};
const ProbabilityArray< num_uv_modes > kf_uv_mode_probs = {{ 142, 114, 183 }};

const SafeArray< SafeArray< ProbabilityArray< num_intra_b_modes >,
                            num_intra_b_modes >,
                 num_intra_b_modes > kf_b_mode_probs =
{{
  {{ /* above mode 0 */
    {{ /* left mode 0 */ 231, 120,  48,  89, 115, 113, 120, 152, 112}},
    {{ /* left mode 1 */ 152, 179,  64, 126, 170, 118,  46,  70,  95}},
    {{ /* left mode 2 */ 175,  69, 143,  80,  85,  82,  72, 155, 103}},
    {{ /* left mode 3 */  56,  58,  10, 171, 218, 189,  17,  13, 152}},
    {{ /* left mode 4 */ 144,  71,  10,  38, 171, 213, 144,  34,  26}},
    {{ /* left mode 5 */ 114,  26,  17, 163,  44, 195,  21,  10, 173}},
    {{ /* left mode 6 */ 121,  24,  80, 195,  26,  62,  44,  64,  85}},
    {{ /* left mode 7 */ 170,  46,  55,  19, 136, 160,  33, 206,  71}},
    {{ /* left mode 8 */  63,  20, 8, 114, 114, 208,  12,   9, 226}},
    {{ /* left mode 9 */  81,  40,  11,  96, 182,  84,  29,  16,  36}}
  }},
  {{ /* above mode 1 */
    {{ /* left mode 0 */ 134, 183,  89, 137,  98, 101, 106, 165, 148}},
    {{ /* left mode 1 */  72, 187, 100, 130, 157, 111,  32,  75,  80}},
    {{ /* left mode 2 */  66, 102, 167,  99,  74,  62,  40, 234, 128}},
    {{ /* left mode 3 */  41,  53, 9, 178, 241, 141,  26,   8, 107}},
    {{ /* left mode 4 */ 104,  79,  12,  27, 217, 255,  87,  17,   7}},
    {{ /* left mode 5 */  74,  43,  26, 146,  73, 166,  49,  23, 157}},
    {{ /* left mode 6 */  65,  38, 105, 160,  51,  52,  31, 115, 128}},
    {{ /* left mode 7 */  87,  68,  71,  44, 114,  51,  15, 186,  23}},
    {{ /* left mode 8 */  47,  41,  14, 110, 182, 183,  21,  17, 194}},
    {{ /* left mode 9 */  66,  45,  25, 102, 197, 189,  23,  18,  22}}
  }},
  {{ /* above mode 2 */
    {{ /* left mode 0 */  88,  88, 147, 150,  42,  46,  45, 196, 205}},
    {{ /* left mode 1 */  43,  97, 183, 117,  85,  38,  35, 179,  61}},
    {{ /* left mode 2 */  39,  53, 200,  87,  26,  21,  43, 232, 171}},
    {{ /* left mode 3 */  56,  34,  51, 104, 114, 102,  29,  93,  77}},
    {{ /* left mode 4 */ 107,  54,  32,  26,  51,   1,  81,  43,  31}},
    {{ /* left mode 5 */  39,  28,  85, 171,  58, 165,  90,  98,  64}},
    {{ /* left mode 6 */  34,  22, 116, 206,  23,  34,  43, 166,  73}},
    {{ /* left mode 7 */  68,  25, 106,  22,  64, 171,  36, 225, 114}},
    {{ /* left mode 8 */  34,  19,  21, 102, 132, 188,  16,  76, 124}},
    {{ /* left mode 9 */  62,  18,  78,  95,  85,  57,  50,  48,  51}}
  }},
  {{ /* above mode 3 */
    {{ /* left mode 0 */ 193, 101,  35, 159, 215, 111,  89,  46, 111}},
    {{ /* left mode 1 */  60, 148,  31, 172, 219, 228,  21,  18, 111}},
    {{ /* left mode 2 */ 112, 113,  77,  85, 179, 255,  38, 120, 114}},
    {{ /* left mode 3 */  40,  42, 1, 196, 245, 209,  10,  25, 109}},
    {{ /* left mode 4 */ 100,  80, 8,  43, 154,   1,  51,  26,  71}},
    {{ /* left mode 5 */  88,  43,  29, 140, 166, 213,  37,  43, 154}},
    {{ /* left mode 6 */  61,  63,  30, 155,  67,  45,  68,   1, 209}},
    {{ /* left mode 7 */ 142,  78,  78,  16, 255, 128,  34, 197, 171}},
    {{ /* left mode 8 */  41,  40, 5, 102, 211, 183, 4,   1, 221}},
    {{ /* left mode 9 */  51,  50,  17, 168, 209, 192,  23,  25,  82}}
  }},
  {{ /* above mode 4 */
    {{ /* left mode 0 */ 125,  98,  42,  88, 104,  85, 117, 175,  82}},
    {{ /* left mode 1 */  95,  84,  53,  89, 128, 100, 113, 101,  45}},
    {{ /* left mode 2 */  75,  79, 123,  47,  51, 128,  81, 171,   1}},
    {{ /* left mode 3 */  57,  17, 5,  71, 102,  57,  53,  41,  49}},
    {{ /* left mode 4 */ 115,  21, 2,  10, 102, 255, 166,  23,   6}},
    {{ /* left mode 5 */  38,  33,  13, 121,  57,  73,  26,   1,  85}},
    {{ /* left mode 6 */  41,  10,  67, 138,  77, 110,  90,  47, 114}},
    {{ /* left mode 7 */ 101,  29,  16,  10,  85, 128, 101, 196,  26}},
    {{ /* left mode 8 */  57,  18,  10, 102, 102, 213,  34,  20,  43}},
    {{ /* left mode 9 */ 117,  20,  15,  36, 163, 128,  68,   1,  26}}
  }},
  {{ /* above mode 5 */
    {{ /* left mode 0 */ 138,  31,  36, 171,  27, 166,  38,  44, 229}},
    {{ /* left mode 1 */  67,  87,  58, 169,  82, 115,  26,  59, 179}},
    {{ /* left mode 2 */  63,  59,  90, 180,  59, 166,  93,  73, 154}},
    {{ /* left mode 3 */  40,  40,  21, 116, 143, 209,  34,  39, 175}},
    {{ /* left mode 4 */  57,  46,  22,  24, 128,   1,  54,  17,  37}},
    {{ /* left mode 5 */  47,  15,  16, 183,  34, 223,  49,  45, 183}},
    {{ /* left mode 6 */  46,  17,  33, 183,   6,  98,  15,  32, 183}},
    {{ /* left mode 7 */  65,  32,  73, 115,  28, 128,  23, 128, 205}},
    {{ /* left mode 8 */  40,   3, 9, 115,  51, 192,  18,   6, 223}},
    {{ /* left mode 9 */  87,  37, 9, 115,  59,  77,  64,  21,  47}}
  }},
  {{ /* above mode 6 */
    {{ /* left mode 0 */ 104,  55,  44, 218,   9,  54,  53, 130, 226}},
    {{ /* left mode 1 */  64,  90,  70, 205,  40,  41,  23,  26,  57}},
    {{ /* left mode 2 */  54,  57, 112, 184,   5,  41,  38, 166, 213}},
    {{ /* left mode 3 */  30,  34,  26, 133, 152, 116,  10,  32, 134}},
    {{ /* left mode 4 */  75,  32,  12,  51, 192, 255, 160,  43,  51}},
    {{ /* left mode 5 */  39,  19,  53, 221,  26, 114,  32,  73, 255}},
    {{ /* left mode 6 */  31,   9,  65, 234,   2,  15, 1, 118,  73}},
    {{ /* left mode 7 */  88,  31,  35,  67, 102,  85,  55, 186,  85}},
    {{ /* left mode 8 */  56,  21,  23, 111,  59, 205,  45,  37, 192}},
    {{ /* left mode 9 */  55,  38,  70, 124,  73, 102, 1,  34,  98}}
  }},
  {{ /* above mode 7 */
    {{ /* left mode 0 */ 102,  61,  71,  37,  34,  53,  31, 243, 192}},
    {{ /* left mode 1 */  69,  60,  71,  38,  73, 119,  28, 222,  37}},
    {{ /* left mode 2 */  68,  45, 128,  34,   1,  47,  11, 245, 171}},
    {{ /* left mode 3 */  62,  17,  19,  70, 146,  85,  55,  62,  70}},
    {{ /* left mode 4 */  75,  15, 9,   9,  64, 255, 184, 119,  16}},
    {{ /* left mode 5 */  37,  43,  37, 154, 100, 163,  85, 160,   1}},
    {{ /* left mode 6 */  63,   9,  92, 136,  28,  64,  32, 201,  85}},
    {{ /* left mode 7 */  86,   6,  28,   5,  64, 255,  25, 248,   1}},
    {{ /* left mode 8 */  56,   8,  17, 132, 137, 255,  55, 116, 128}},
    {{ /* left mode 9 */  58,  15,  20,  82, 135,  57,  26, 121,  40}}
  }},
  {{ /* above mode 8 */
    {{ /* left mode 0 */ 164,  50,  31, 137, 154, 133,  25,  35, 218}},
    {{ /* left mode 1 */  51, 103,  44, 131, 131, 123,  31,   6, 158}},
    {{ /* left mode 2 */  86,  40,  64, 135, 148, 224,  45, 183, 128}},
    {{ /* left mode 3 */  22,  26,  17, 131, 240, 154,  14,   1, 209}},
    {{ /* left mode 4 */  83,  12,  13,  54, 192, 255,  68,  47,  28}},
    {{ /* left mode 5 */  45,  16,  21,  91,  64, 222, 7,   1, 197}},
    {{ /* left mode 6 */  56,  21,  39, 155,  60, 138,  23, 102, 213}},
    {{ /* left mode 7 */  85,  26,  85,  85, 128, 128,  32, 146, 171}},
    {{ /* left mode 8 */  18,  11, 7,  63, 144, 171, 4,   4, 246}},
    {{ /* left mode 9 */  35,  27,  10, 146, 174, 171,  12,  26, 128}}
  }},
  {{ /* above mode 9 */
    {{ /* left mode 0 */ 190,  80,  35,  99, 180,  80, 126,  54,  45}},
    {{ /* left mode 1 */  85, 126,  47,  87, 176,  51,  41,  20,  32}},
    {{ /* left mode 2 */ 101,  75, 128, 139, 118, 146, 116, 128,  85}},
    {{ /* left mode 3 */  56,  41,  15, 176, 236,  85,  37,   9,  62}},
    {{ /* left mode 4 */ 146,  36,  19,  30, 171, 255,  97,  27,  20}},
    {{ /* left mode 5 */  71,  30,  17, 119, 118, 255,  17,  18, 138}},
    {{ /* left mode 6 */ 101,  38,  60, 138,  55,  70,  43,  26, 142}},
    {{ /* left mode 7 */ 138,  45,  61,  62, 219,   1,  81, 188,  64}},
    {{ /* left mode 8 */  32,  41,  20, 117, 151, 142,  20,  21, 163}},
    {{ /* left mode 9 */ 112,  19,  12,  61, 195, 128,  48,   4,  24}}
   }}
 }};

const TreeArray< num_y_modes > kf_y_mode_tree =
{{
  -B_PRED, 2,
  4, 6,
  -DC_PRED, -V_PRED,
  -H_PRED, -TM_PRED
}};

const TreeArray< num_y_modes > y_mode_tree =
{{
  -DC_PRED, 2,
  4, 6,
  -V_PRED, -H_PRED,
  -TM_PRED, -B_PRED
}};

const TreeArray< num_uv_modes > uv_mode_tree =
{{
  -DC_PRED, 2,
  -V_PRED, 4,
  -H_PRED, -TM_PRED
}};

const TreeArray< num_intra_b_modes > b_mode_tree =
{{
  -B_DC_PRED, 2,                 /* 0 = DC_NODE */
  -B_TM_PRED, 4,                /* 1 = TM_NODE */
  -B_VE_PRED, 6,               /* 2 = VE_NODE */
  8, 12,                  /* 3 = COM_NODE */
  -B_HE_PRED, 10,              /* 4 = HE_NODE */
  -B_RD_PRED, -B_VR_PRED,         /* 5 = RD_NODE */
  -B_LD_PRED, 14,              /* 6 = LD_NODE */
  -B_VL_PRED, 16,            /* 7 = VL_NODE */
  -B_HD_PRED, -B_HU_PRED         /* 8 = HD_NODE */
}};

const TreeArray< 8 > small_mv_tree =
{{
  2, 8,
  4, 6,
  -0, -1,
  -2, -3,
  10, 12,
  -4, -5,
  -6, -7
}};

const TreeArray< num_mv_refs > mv_ref_tree =
{{
  -ZEROMV, 2,
  -NEARESTMV, 4,
  -NEARMV, 6,
  -NEWMV, -SPLITMV
}};

const TreeArray< 4 > submv_ref_tree =
{{
  -LEFT4X4, 2,
  -ABOVE4X4, 4,
  -ZERO4X4, -NEW4X4
}};

const TreeArray< 4 > split_mv_tree =
{{
  -3, 2,
  -2, 4,
  -0, -1
}};

const ProbabilityArray< num_intra_b_modes > invariant_b_mode_probs = {{ 120,  90,  79, 133,  87,  85,  80, 111, 151}};

const extern SafeArray< SafeArray< Probability, 4 >, 6 > mv_counts_to_probs =
  {{{{   7,   1,   1, 143 }},
    {{  14,  18,  14, 107 }},
    {{ 135,  64,  57,  68 }},
    {{  60,  56, 128,  65 }},
    {{ 159, 134, 128,  34 }},
    {{ 234, 188, 128,  28 }}}};

const ProbabilityArray< 4 > split_mv_probs = {{ 110, 111, 150 }};

const extern SafeArray< ProbabilityArray< 4 >, 5 > submv_ref_probs2 =
  {{{{ 147, 136, 18 }},
    {{ 106, 145,  1 }},
    {{ 179, 121,  1 }},
    {{ 223,   1, 34 }},
    {{ 208,   1,  1 }}}};

const extern SafeArray< vector< vector< pair< uint8_t, uint8_t > > >, 4 > mv_partitions =
  {{ { { {0,0}, {1,0}, {2,0}, {3,0},
         {0,1}, {1,1}, {2,1}, {3,1} },
       { {0,2}, {1,2}, {2,2}, {3,2},
         {0,3}, {1,3}, {2,3}, {3,3} } }, /* top, bottom */

     { { {0,0}, {1,0},
         {0,1}, {1,1},
         {0,2}, {1,2},
         {0,3}, {1,3} },
       { {2,0}, {3,0},
         {2,1}, {3,1},
         {2,2}, {3,2},
         {2,3}, {3,3} } }, /* left, right */

     { { {0,0}, {1,0},
         {0,1}, {1,1} },
       { {2,0}, {3,0},
         {2,1}, {3,1} },
       { {0,2}, {1,2},
         {0,3}, {1,3} },
       { {2,2}, {3,2},
         {2,3}, {3,3} } }, /* four quarters */

     { { {0,0} }, { {1,0} }, { {2,0} }, { {3,0} },
       { {0,1} }, { {1,1} }, { {2,1} }, { {3,1} },
       { {0,2} }, { {1,2} }, { {2,2} }, { {3,2} },
       { {0,3} }, { {1,3} }, { {2,3} }, { {3,3} } } /* each subblock gets own vector */
    }};

/* not in original modemv_data.h */
const TreeArray< num_segments > segment_id_tree = {{ 2, 4, -0, -1, -2, -3 }};
