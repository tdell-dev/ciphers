#include <stdio.h>
#include "ap_int.h"


typedef long long int WORD64;
typedef ap_uint<1> BIT;
typedef ap_uint<4> NIBBLE;
typedef ap_uint<5> INDEX;
typedef ap_uint<6> INDEX_L;
typedef ap_uint<80> KEYWORD;
typedef ap_uint<128> KEYWORD_L;

/*typedef uint4 NIBBLE;
typedef uint6 INDEX;
typedef uint80 KEYWORD;
typedef uint128 KEYWORD_L;
*/


void present80_encrypt( WORD64 pt_0, KEYWORD key, WORD64 *ct_0 );
void present80_decrypt( WORD64 ct_0, KEYWORD key, WORD64* pt_0 );
void present128_encrypt( WORD64 pt_0, KEYWORD_L key, WORD64 *ct_0 );
void present128_decrypt( WORD64 ct_0, KEYWORD_L key, WORD64* pt_0 );
void gen_subkeys( KEYWORD key[], WORD64 subKeyAr[] );
void gen_subkeys( KEYWORD_L key[], WORD64 subKeyAr[] );
void apply_pLayer( WORD64 input, WORD64* output);
void apply_sBox( WORD64 input, WORD64 *output);
void add_round_key(WORD64 input, WORD64 subkey, WORD64* output);
