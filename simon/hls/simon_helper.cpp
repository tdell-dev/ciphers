#include "simon.h"

void gen_subkeys( WORD subkeyAr[NUM_ARRAY], WORD key[4]){

	WORD z[64];
	z[0] = 0x0001;
	z[1] = 0x0001;
	z[2] = 0x0001;
	z[3] = 0x0001;
	z[4] = 0x0001;
	z[5] = 0x0000;
	z[6] = 0x0001;
	z[7] = 0x0000;
	z[8] = 0x0000;
	z[9] = 0x0000;
	z[10] = 0x0001;
	z[11] = 0x0000;
	z[12] = 0x0000;
	z[13] = 0x0001;
	z[14] = 0x0000;
	z[15] = 0x0001;
	z[16] = 0x0000;
	z[17] = 0x0001;
	z[18] = 0x0001;
	z[19] = 0x0000;
	z[20] = 0x0000;
	z[21] = 0x0000;
	z[22] = 0x0000;
	z[23] = 0x0001;
	z[24] = 0x0001;
	z[25] = 0x0001;
	z[26] = 0x0000;
	z[27] = 0x0000;
	z[28] = 0x0001;
	z[29] = 0x0001;
	z[30] = 0x0000;
	z[31] = 0x0001;//z = 11111010001001010110000111001101111101000100101011000011100110;
	z[32] = 0x0001;
	z[33] = 0x0001;
	z[34] = 0x0001;
	z[35] = 0x0001;
	z[36] = 0x0000;
	z[37] = 0x0001;
	z[38] = 0x0000;
	z[39] = 0x0000;
	z[40] = 0x0000;
	z[41] = 0x0001;
	z[42] = 0x0000;
	z[43] = 0x0000;
	z[44] = 0x0001;
	z[45] = 0x0000;
	z[46] = 0x0001;
	z[47] = 0x0000;
	z[48] = 0x0001;
	z[49] = 0x0001;
	z[50] = 0x0000;
	z[51] = 0x0000;
	z[52] = 0x0000;
	z[53] = 0x0000;
	z[54] = 0x0001;
	z[55] = 0x0001;
	z[56] = 0x0001;
	z[57] = 0x0000;
	z[58] = 0x0000;
	z[59] = 0x0001;
	z[60] = 0x0001;
	z[61] = 0x0000;
	z[62] = 0x0000;
	z[63] = 0x0000;
	//z = 11111010001001010110000111001101111101000100101011000011100110;
	//z = 0110 0111 0000 1101 0100 1000 1011 1110 1100 1110 0001 1010 1001 0001 0111 11 00;
	//z = 0x670d48bece1a917c;
	WORD c = 0xfffc;
	for (int i=4; i<32; i++) {
		WORD tmp;
		circ_shift_right3( subkeyAr[i-1], &tmp);

		tmp = tmp ^ subkeyAr[i-3];

		WORD tmp2;
		circ_shift_right1(tmp, &tmp2);

		tmp = tmp ^ tmp2;
		subkeyAr[i] = ~subkeyAr[i-4] ^ tmp ^ z[i-4] ^ 0x0003;
		

		//masked = ((z >> (31-(i-4)) & 0x0001));
		//circ_shift_right3( subkeyAr[i-1], &temp0);
		//temp0 = temp0 ^ subkeyAr[i-3];
		//circ_shift_right1(temp0, &temp1);
		//subkeyAr[i] = ~subkeyAr[i-4] ^ temp0 ^ z[i-4] ^ 3;

		//temp0 = temp0 ^ subkeyAr[i+1];
		//circ_shift_right1( temp0, &temp1);
		//masked = ((z>>(31-(i+4))) & 0x0001);
		//subkeyAr[i+4] = c ^ z[i] ^ subkeyAr[i] ^ temp0 ^ temp1;
	}

}


void gen_subkeys( WORD64 subkeyAr[NUM_ARRAY] ){

	WORD z[69];
	z[0] = 0x0001;
	z[1] = 0x0001;
	z[2] = 0x0000;
	z[3] = 0x0001;
	z[4] = 0x0000;
	z[5] = 0x0000;
	z[6] = 0x0000;
	z[7] = 0x0001;
	z[8] = 0x0001;
	z[9] = 0x0001;
	z[10] = 0x0001;
	z[11] = 0x0000;
	z[12] = 0x0000;
	z[13] = 0x0001;
	z[14] = 0x0001;
	z[15] = 0x0000;
	z[16] = 0x0001;
	z[17] = 0x0000;
	z[18] = 0x0001;
	z[19] = 0x0001;
	z[20] = 0x0000;
	z[21] = 0x0001;
	z[22] = 0x0001;
	z[23] = 0x0000;
	z[24] = 0x0000;
	z[25] = 0x0000;
	z[26] = 0x0001;
	z[27] = 0x0000;
	z[28] = 0x0000;
	z[29] = 0x0000;
	z[30] = 0x0000;
	z[31] = 0x0000;
	z[32] = 0x0000;
	z[33] = 0x0001;
	z[34] = 0x0000;
	z[35] = 0x0001;
	z[36] = 0x0001;
	z[37] = 0x0001;
	z[38] = 0x0000;
	z[39] = 0x0000;
	z[40] = 0x0000;
	z[41] = 0x0000;
	z[42] = 0x0001;
	z[43] = 0x0001;
	z[44] = 0x0000;
	z[45] = 0x0000;
	z[46] = 0x0001;
	z[47] = 0x0000;
	z[48] = 0x0001;
	z[49] = 0x0000;
	z[50] = 0x0000;
	z[51] = 0x0001;
	z[52] = 0x0000;
	z[53] = 0x0000;
	z[54] = 0x0001;
	z[55] = 0x0001;
	z[56] = 0x0001;
	z[57] = 0x0000;
	z[58] = 0x0001;
	z[59] = 0x0001;
	z[60] = 0x0001;
	z[61] = 0x0001;
	z[62] = 0x0001;
	z[63] = 0x0001;
	z[64] = 0x0000;
	z[65] = 0x0001;
	z[66] = 0x0000;
	z[67] = 0x0000;
	z[68] = 0x0000;
	WORD64 c = 0xfffffffffffffffc;
	
	for (int i=4; i<72; i++) {
		WORD64 tmp;
		circ_shift_right3( subkeyAr[i-1], &tmp);
		tmp = tmp ^ subkeyAr[i-3];

		WORD64 tmp2;
		circ_shift_right1(tmp, &tmp2);

		tmp = tmp ^ tmp2;
		subkeyAr[i] = ~subkeyAr[i-4] ^ tmp ^ z[i-4] ^ 0x0003;	
	}

}


void simon_enc_round( WORD x_i, WORD y_i, WORD subkey, WORD* x_n, WORD* y_n ){
	WORD circ1;
	WORD circ2;
	WORD circ8;

	circ_shift1(x_i, &circ1);
	circ_shift2(x_i, &circ2);
	circ_shift8(x_i, &circ8);
	*x_n = y_i ^ (circ1 & circ8) ^ circ2 ^ subkey;
	*y_n = x_i;

}

void simon_enc_round( WORD64 x_i, WORD64 y_i, WORD64 subkey, WORD64* x_n, WORD64* y_n ){
	WORD64 circ1;
	WORD64 circ2;
	WORD64 circ8;

	circ_shift1(x_i, &circ1);
	circ_shift2(x_i, &circ2);
	circ_shift8(x_i, &circ8);
	*x_n = y_i ^ (circ1 & circ8) ^ circ2 ^ subkey;
	*y_n = x_i;

}

void simon_dec_round( WORD x_i, WORD y_i, WORD subkey, WORD* x_n, WORD* y_n ){
	WORD circ1;
	WORD circ2;
	WORD circ8;

	circ_shift1(y_i, &circ1);
	circ_shift2(y_i, &circ2);
	circ_shift8(y_i, &circ8);

	*x_n = y_i;
	*y_n = x_i ^ (circ1 & circ8) ^ circ2 ^ subkey;

}

void simon_dec_round( WORD64 x_i, WORD64 y_i, WORD64 subkey, WORD64* x_n, WORD64* y_n ){
	WORD64 circ1;
	WORD64 circ2;
	WORD64 circ8;

	circ_shift1(y_i, &circ1);
	circ_shift2(y_i, &circ2);
	circ_shift8(y_i, &circ8);

	*x_n = y_i;
	*y_n = x_i ^ (circ1 & circ8) ^ circ2 ^ subkey;

}


void circ_shift1( WORD in0, WORD* shifted) {
	*shifted = (in0 << 1) | (in0 >> 15);
}

void circ_shift1( WORD64 in0, WORD64* shifted) {
	*shifted = (in0 << 1) | (in0 >> 63);
}

void circ_shift2( WORD in0, WORD* shifted) {
	*shifted = (in0 << 2) | (in0 >> 14);
}

void circ_shift2( WORD64 in0, WORD64* shifted) {
	*shifted = (in0 << 2) | (in0 >> 62);
}

void circ_shift8( WORD in0, WORD* shifted) {
	*shifted = (in0 << 8) | (in0 >> 8);
}

void circ_shift8( WORD64 in0, WORD64* shifted) {
	*shifted = (in0 << 8) | (in0 >> 56);
}

void circ_shift( WORD in0, WORD* shifted, int shift) {
	*shifted = (in0 << shift) | (in0 >> (sizeof(in0) - shift));
}

void circ_shift( WORD64 in0, WORD64* shifted, int shift) {
	*shifted = (in0 << shift) | (in0 >> (sizeof(in0) - shift));
}

void circ_shift_right1( WORD in0, WORD* shifted) {
	*shifted = (in0 >> 1) | (in0 << 15);
}

void circ_shift_right1( WORD64 in0, WORD64* shifted) {
	*shifted = (in0 >> 1) | (in0 << 63);
}

void circ_shift_right2( WORD in0, WORD* shifted) {
	*shifted = (in0 >> 2) | (in0 << 14);
}

void circ_shift_right2( WORD64 in0, WORD64* shifted) {
	*shifted = (in0 >> 2) | (in0 << 62);
}

void circ_shift_right3( WORD in0, WORD* shifted) {
	*shifted = (in0 >> 3) | (in0 << 13);
}

void circ_shift_right8( WORD in0, WORD* shifted) {
	*shifted = (in0 >> 8) | (in0 << 8);
}

void circ_shift_right3( WORD64 in0, WORD64* shifted) {
	*shifted = (in0 >> 3) | (in0 << 61);
}

void circ_shift_right( WORD in0, WORD* shifted, int shift) {
	*shifted = (in0 >> shift) | (in0 << (sizeof(in0) - shift));
}

void circ_shift_right( WORD64 in0, WORD64* shifted, int shift) {
	*shifted = (in0 >> shift) | (in0 << (sizeof(in0) - shift));
}

void F( WORD* out, WORD x, WORD y){
	WORD temp;
	circ_shift_right3( x, &temp);
	*out = temp ^ y;
}

void F( WORD64* out, WORD64 x, WORD64 y){
	WORD64 temp;
	circ_shift_right3( x, &temp);
	*out = temp ^ y;
}
