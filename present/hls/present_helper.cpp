#include "present.h"


/*
void circ_shift_left2(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 2) | (in0 >> 14);
}

void circ_shift_left3(WORD64 in0, WORD64* shifted) {
	*shifted = (in0 << 3) | (in0 >> 61);
}

void circ_shift_left7(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 7) | (in0 >> 9);
}

void circ_shift_left8(WORD64 in0, WORD64* shifted) {
	*shifted = (in0 << 8) | (in0 >> 56);
}


void circ_shift_right2(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 14) | (in0 >> 2);
}

void circ_shift_right3(WORD64 in0, WORD64* shifted){
	*shifted = (in0 << 61) | (in0 >> 3);
}

void circ_shift_right7(WORD in0, WORD* shifted)	  {
	*shifted = (in0 << 9) | (in0 >> 7);
}

void circ_shift_right8(WORD64 in0, WORD64* shifted){
	*shifted = (in0 << 56) | (in0 >> 8);
}
*/

NIBBLE sBox[] = { 0xC, 0x5, 0x6, 0xb, 0x9, 0x0, 0xa, 0xd ,
				  0x3, 0xe, 0xf, 0x8, 0x4, 0x7, 0x1, 0x2 };

INDEX pBox[]  = { 0, 16, 32, 48,  1, 17, 33, 49,  2, 18, 34,
				 50,  3, 19, 35, 51,  4, 20, 36, 52,  5, 21,
				 37, 53,  6, 22, 38, 54,  7, 23, 39, 55,  8,
				 24, 40, 56,  9, 25, 41, 57, 10, 26, 42, 58,
				 11, 27, 43, 59, 12, 28, 44, 60, 13, 29, 45,
				 61, 14, 30, 46, 62, 15, 31, 47, 63 };

void add_round_key(WORD64 input, WORD64 subkey, WORD64* output){
	*output = input ^ subkey;
}

void apply_sBox( WORD64 input, WORD64 *output) {
	NIBBLE lookup15;	NIBBLE lookup14;
	NIBBLE lookup13;	NIBBLE lookup12;
	NIBBLE lookup11;	NIBBLE lookup10;
	NIBBLE lookup9;		NIBBLE lookup8;
	NIBBLE lookup7;		NIBBLE lookup6;
	NIBBLE lookup5;		NIBBLE lookup4;
	NIBBLE lookup3;		NIBBLE lookup2;
	NIBBLE lookup1;		NIBBLE lookup0;

	lookup15 = input >> 15*4 -1; lookup14 = input >> 14*4 -1;
	lookup13 = input >> 13*4 -1; lookup12 = input >> 12*4 -1;
	lookup11 = input >> 11*4 -1; lookup10 = input >> 10*4 -1;
	lookup9  = input >> 9*4 - 1; lookup8  = input >> 8*4 - 1;
	lookup7  = input >> 7*4 - 1; lookup6  = input >> 6*4 - 1;
	lookup5  = input >> 5*4 - 1; lookup4  = input >> 4*4 - 1;
	lookup3  = input >> 3*4 - 1; lookup2  = input >> 2*4 - 1;
	lookup1  = input >> 1*4 - 1; lookup0  = input >> 0*4;

	*output = (sBox[lookup15] << 15*4) | (sBox[lookup14] << 14*4) | \
			  (sBox[lookup13] << 13*4) | (sBox[lookup12] << 12*4) | \
			  (sBox[lookup11] << 11*4) | (sBox[lookup10] << 10*4) | \
			  (sBox[lookup9] << 9*4)   | (sBox[lookup8] << 8*4)   | \
			  (sBox[lookup7] << 7*4)   | (sBox[lookup6] << 6*4)   | \
			  (sBox[lookup5] << 5*4)   | (sBox[lookup4] << 4*4)   | \
			  (sBox[lookup3] << 3*4)   | (sBox[lookup2] << 2*4)   | \
			  (sBox[lookup1] << 1*4)   | (sBox[lookup0] << 0) ; 

}

void apply_pLayer( WORD64 in, WORD64* output) {
	BIT temp[64];
	for( INDEX_L g = 0; g < 64; g++) {
		BIT tempBit;
		tempBit = ((in << (63-g)) >> g);
		temp[ pBox[g] ] = tempBit;
		//temp[g] = ((in << (63-g)) >> g);
	}	
	WORD64 tempWord;
	for (INDEX_L g=0; g< 64; g++){
		tempWord = tempWord | ((temp[g]) << g);
	}

	*output = tempWord;
/*
	BIT out63; BIT out62; BIT out61; BIT out60;	BIT out59; BIT out58; BIT out57; BIT out56;
	BIT out55; BIT out54; BIT out53; BIT out52;	BIT out51; BIT out50; BIT out49; BIT out48;
	BIT out47; BIT out46; BIT out45; BIT out44;	BIT out43; BIT out42; BIT out41; BIT out40;
	BIT out39; BIT out38; BIT out37; BIT out36;	BIT out35; BIT out34; BIT out33; BIT out32;
	BIT out31; BIT out30; BIT out29; BIT out28;	BIT out27; BIT out26; BIT out25; BIT out24;
	BIT out23; BIT out22; BIT out21; BIT out20;	BIT out19; BIT out18; BIT out17; BIT out16;
	BIT out15; BIT out14; BIT out13; BIT out12;	BIT out11; BIT out10; BIT out9;  BIT out8;
	BIT out7;  BIT out6;  BIT out5;  BIT out4;	BIT out3;  BIT out2;  BIT out1;  BIT out0;

	out63 = out62 =	out61 = out60 = out59 = out58 =	out57 =	out56 = 
	out55 =	out54 =	out53 = out52 =	out51 = out50 =	out49 = out48 =
	out47 =	out46 =	out45 = out44 =	out43 = out42 = out41 = out40 =
	out39 = out38 = out37 = out36 =	out35 =	out34 = out33 = out32 =
	out31 = out30 =	out29 =	out28 =	out27 = out26 =	out25 =	out24 =
	out23 = out22 =	out21 = out20 =	out19 =	out18 =	out17 = out16 = 
	out15 =	out14 =	out13 =	out12 =	out11 =	out10 =	out9  =	out8  = 
	out7  =	out6  =	out5  =	out4  =	out3  =	out2  =	out1  =	out0  =

	*output = ( (WORD64) out63 ) << 63 | ( (WORD64) out62 ) << 62 | \
			  ( (WORD64) out61 ) << 61 | ( (WORD64) out60 ) << 60 | \
			  ( (WORD64) out59 ) << 59 | ( (WORD64) out58 ) << 58 | \
			  ( (WORD64) out57 ) << 57 | ( (WORD64) out56 ) << 56 | \
			  ( (WORD64) out55 ) << 55 | ( (WORD64) out54 ) << 54 | \
			  ( (WORD64) out53 ) << 53 | ( (WORD64) out52 ) << 52 | \
			  ( (WORD64) out51 ) << 51 | ( (WORD64) out50 ) << 50 | \
			  ( (WORD64) out49 ) << 49 | ( (WORD64) out48 ) << 48 | \
			  ( (WORD64) out47 ) << 47 | ( (WORD64) out46 ) << 46 | \
			  ( (WORD64) out45 ) << 45 | ( (WORD64) out44 ) << 44 | \
			  ( (WORD64) out43 ) << 43 | ( (WORD64) out42 ) << 42 | \
			  ( (WORD64) out41 ) << 41 | ( (WORD64) out40 ) << 40 | \
			  ( (WORD64) out39 ) << 39 | ( (WORD64) out38 ) << 38 | \
			  ( (WORD64) out37 ) << 37 | ( (WORD64) out36 ) << 36 | \
			  ( (WORD64) out35 ) << 35 | ( (WORD64) out34 ) << 34 | \
			  ( (WORD64) out33 ) << 33 | ( (WORD64) out32 ) << 32 | \
			  ( (WORD64) out31 ) << 31 | ( (WORD64) out30 ) << 30 | \
			  ( (WORD64) out29 ) << 29 | ( (WORD64) out28 ) << 28 | \
			  ( (WORD64) out27 ) << 27 | ( (WORD64) out26 ) << 26 | \
			  ( (WORD64) out25 ) << 25 | ( (WORD64) out24 ) << 24 | \
			  ( (WORD64) out23 ) << 23 | ( (WORD64) out22 ) << 22 | \
			  ( (WORD64) out21 ) << 21 | ( (WORD64) out20 ) << 20 | \
			  ( (WORD64) out19 ) << 19 | ( (WORD64) out18 ) << 18 | \
			  ( (WORD64) out17 ) << 17 | ( (WORD64) out16 ) << 16 | \
			  ( (WORD64) out15 ) << 15 | ( (WORD64) out14 ) << 14 | \
			  ( (WORD64) out13 ) << 13 | ( (WORD64) out12 ) << 12 | \
			  ( (WORD64) out11 ) << 11 | ( (WORD64) out10 ) << 10 | \
			  ( (WORD64) out9 ) << 9 |   ( (WORD64) out8 ) << 8 | \
			  ( (WORD64) out7 ) << 7 |   ( (WORD64) out6 ) << 6 | \
			  ( (WORD64) out5 ) << 5 |   ( (WORD64) out4 ) << 4 | \
			  ( (WORD64) out3 ) << 3 |   ( (WORD64) out2 ) << 2 | \
			  ( (WORD64) out1 ) << 1 |   ( (WORD64) out0 ) << 0 ;
*/

}


void circ_shift_left61( KEYWORD key, KEYWORD* outkey) {
	*outkey = (key << 61) | (key >> 19);
}

void circ_shift_left61( KEYWORD_L key, KEYWORD_L* outkey) {
	*outkey = (key << 61) | (key >> 67);
}

void gen_subkeys( KEYWORD key, WORD64 subKeyAr[] ) {
	KEYWORD tempkey_in;
	KEYWORD tempkey_out;

	tempkey_in = key;
	for( INDEX round_counter=0; round_counter < 32; round_counter++) {
		circ_shift_left61( tempkey_in, &tempkey_out );
		NIBBLE topNib; NIBBLE topNib_s;
		topNib = (tempkey_out >> 76);
		topNib_s = sBox[topNib];

		INDEX midNib; INDEX midNib_x;
		midNib = ((tempkey_out << 42) >> 57);
		midNib_x = midNib ^ round_counter;

		//put it all together
		KEYWORD final;
		final = ( tempkey_out & ((KEYWORD) 75557863725914322403327 )) \
//0000 1111 1111 1111 1111 1111 1111 1111 1111 1111 
//1111 1111 1111 1111 1111 0000 0111 1111 1111 1111
//0x0FFFFFFFFFFFFFF07FFF
				| ( ((KEYWORD) midNib_x) << 15) \
				| ( ((KEYWORD) topNib_s) << 76);

		subKeyAr[round_counter] = final >> 15;
		tempkey_in = tempkey_out;
	}
}

void gen_subkeys( KEYWORD_L key, WORD64 subKeyAr[] ) {
	KEYWORD_L tempkey_in;
	KEYWORD_L tempkey_out;

	tempkey_in = key;
	for( INDEX round_counter=0; round_counter < 32; round_counter++) {
		circ_shift_left61( tempkey_in, &tempkey_out );
		NIBBLE topNib0; 
		NIBBLE topNib0_s;
		NIBBLE topNib1; 
		NIBBLE topNib1_s;
		topNib0 = (tempkey_out >> 124);
		topNib0_s = sBox[topNib0];

		topNib1 = ( (tempkey_out << 4) >> 120);
		topNib1_s = sBox[topNib1];

		INDEX midNib; 
		INDEX midNib_x;
		midNib = ((tempkey_out << 61) >> 123);
		midNib_x = midNib ^ round_counter;

		//put it all together
		KEYWORD_L final;
		final = ( tempkey_out & ((KEYWORD_L) 1329227995784915729941540489031319551)) \
//0000 0000 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1000 
//0011 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111
//0x00FFFFFFFFFFFFFF86FFFFFFFFFFFFFFFF
				| ( ((KEYWORD_L) midNib_x) << 62) \
				| ( ((KEYWORD_L) topNib0_s) << 124) \
				| ( ((KEYWORD_L) topNib1_s) << 120);
				
		subKeyAr[round_counter] = final >> 63;
		tempkey_in = tempkey_out;
	}
}