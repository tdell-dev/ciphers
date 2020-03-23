#include <ap_fixed.h>
#include "aes.h"

BITE SBox[16][16] = {
    {0x63, 0x7C, 0x77, 0x7B, 0xF2, 0x6B, 0x6F, 0xC5, 0x30, 0x01, 0x67, 0x2B, 0xFE, 0xD7, 0xAB, 0x76},
    {0xCA, 0x82, 0xC9, 0x7D, 0xFA, 0x59, 0x47, 0xF0, 0xAD, 0xD4, 0xA2, 0xAF, 0x9C, 0xA4, 0x72, 0xC0},
    {0xB7, 0xFD, 0x93, 0x26, 0x36, 0x3F, 0xF7, 0xCC, 0x34, 0xA5, 0xE5, 0xF1, 0x71, 0xD8, 0x31, 0x15},
    {0x04, 0xC7, 0x23, 0xC3, 0x18, 0x96, 0x05, 0x9A, 0x07, 0x12, 0x80, 0xE2, 0xEB, 0x27, 0xB2, 0x75},
    {0x09, 0x83, 0x2C, 0x1A, 0x1B, 0x6E, 0x5A, 0xA0, 0x52, 0x3B, 0xD6, 0xB3, 0x29, 0xE3, 0x2F, 0x84},
    {0x53, 0xD1, 0x00, 0xED, 0x20, 0xFC, 0xB1, 0x5B, 0x6A, 0xCB, 0xBE, 0x39, 0x4A, 0x4C, 0x58, 0xCF},
    {0xD0, 0xEF, 0xAA, 0xFB, 0x43, 0x4D, 0x33, 0x85, 0x45, 0xF9, 0x02, 0x7F, 0x50, 0x3C, 0x9F, 0xA8},
    {0x51, 0xA3, 0x40, 0x8F, 0x92, 0x9D, 0x38, 0xF5, 0xBC, 0xB6, 0xDA, 0x21, 0x10, 0xFF, 0xF3, 0xD2},
    {0xCD, 0x0C, 0x13, 0xEC, 0x5F, 0x97, 0x44, 0x17, 0xC4, 0xA7, 0x7E, 0x3D, 0x64, 0x5D, 0x19, 0x73},
    {0x60, 0x81, 0x4F, 0xDC, 0x22, 0x2A, 0x90, 0x88, 0x46, 0xEE, 0xB8, 0x14, 0xDE, 0x5E, 0x0B, 0xDB},
    {0xE0, 0x32, 0x3A, 0x0A, 0x49, 0x06, 0x24, 0x5C, 0xC2, 0xD3, 0xAC, 0x62, 0x91, 0x95, 0xE4, 0x79},
    {0xE7, 0xC8, 0x37, 0x6D, 0x8D, 0xD5, 0x4E, 0xA9, 0x6C, 0x56, 0xF4, 0xEA, 0x65, 0x7A, 0xAE, 0x08},
    {0xBA, 0x78, 0x25, 0x2E, 0x1C, 0xA6, 0xB4, 0xC6, 0xE8, 0xDD, 0x74, 0x1F, 0x4B, 0xBD, 0x8B, 0x8A},
    {0x70, 0x3E, 0xB5, 0x66, 0x48, 0x03, 0xF6, 0x0E, 0x61, 0x35, 0x57, 0xB9, 0x86, 0xC1, 0x1D, 0x9E},
    {0xE1, 0xF8, 0x98, 0x11, 0x69, 0xD9, 0x8E, 0x94, 0x9B, 0x1E, 0x87, 0xE9, 0xCE, 0x55, 0x28, 0xDF},
    {0x8C, 0xA1, 0x89, 0x0D, 0xBF, 0xE6, 0x42, 0x68, 0x41, 0x99, 0x2D, 0x0F, 0xB0, 0x54, 0xBB, 0x16}
 };

void subkey_gen( BITE origKey[NUM_KEY_BYTES],  
				 BITE subKey0[NUM_DATA_BYTES],  BITE subKey1[NUM_DATA_BYTES],
				 BITE subKey2[NUM_DATA_BYTES],  BITE subKey3[NUM_DATA_BYTES],  
				 BITE subKey4[NUM_DATA_BYTES],  BITE subKey5[NUM_DATA_BYTES],  
				 BITE subKey6[NUM_DATA_BYTES],  BITE subKey7[NUM_DATA_BYTES],  
				 BITE subKey8[NUM_DATA_BYTES],  BITE subKey9[NUM_DATA_BYTES], 
				 BITE subKey10[NUM_DATA_BYTES], BITE subKey11[NUM_DATA_BYTES], 
				 BITE subKey12[NUM_DATA_BYTES], BITE subKey13[NUM_DATA_BYTES],
				 BITE subKey14[NUM_DATA_BYTES], BITE subKey15[NUM_DATA_BYTES]
				 ){

	subKey0[0]  = origKey[0];
	subKey0[1]  = origKey[1];
	subKey0[2]  = origKey[2];
	subKey0[3]  = origKey[3];
	subKey0[4]  = origKey[4];
	subKey0[5]  = origKey[5];
	subKey0[6]  = origKey[6];
	subKey0[7]  = origKey[7];
	subKey0[8]  = origKey[8];
	subKey0[9]  = origKey[9];
	subKey0[10] = origKey[10];
	subKey0[11] = origKey[11];
	subKey0[12] = origKey[12];
	subKey0[13] = origKey[13];
	subKey0[14] = origKey[14];
	subKey0[15] = origKey[15];

	subKey1[0]  = origKey[16];
	subKey1[1]  = origKey[17];
	subKey1[2]  = origKey[18];
	subKey1[3]  = origKey[19];
	subKey1[4]  = origKey[20];
	subKey1[5]  = origKey[21];
	subKey1[6]  = origKey[22];
	subKey1[7]  = origKey[23];
	subKey1[8]  = origKey[24];
	subKey1[9]  = origKey[25];
	subKey1[10] = origKey[26];
	subKey1[11] = origKey[27];
	subKey1[12] = origKey[28];
	subKey1[13] = origKey[29];
	subKey1[14] = origKey[30];
	subKey1[15] = origKey[31];
	
	createTwo256Keys( subKey2,  subKey3,  subKey0, subKey1,   (BITE) 1  );
	createTwo256Keys( subKey4,  subKey5,  subKey2, subKey3,   (BITE) 2  );
	createTwo256Keys( subKey6,  subKey7,  subKey4, subKey5,   (BITE) 4  );
	createTwo256Keys( subKey8,  subKey9,  subKey6, subKey7,   (BITE) 8  );
	createTwo256Keys( subKey10, subKey11, subKey8, subKey9,   (BITE) 16 );
	createTwo256Keys( subKey12, subKey13, subKey10, subKey11, (BITE) 32 );
	createTwo256Keys( subKey14, subKey15, subKey12, subKey13, (BITE) 64 );
}


void createTwo256Keys( BITE outKey0[NUM_DATA_BYTES], BITE outKey1[NUM_DATA_BYTES], BITE inKey0[NUM_DATA_BYTES], BITE inKey1[NUM_DATA_BYTES], BITE RC){

	BITE g_temp0;
	BITE g_temp1;
	BITE g_temp2;
	BITE g_temp3;
	byte_sub(inKey1[12], &g_temp0 );
	byte_sub(inKey1[13], &g_temp1 );
	byte_sub(inKey1[14], &g_temp2 );
	byte_sub(inKey1[15], &g_temp3 );		
	
	BITE g_out[4];
	g_out[0] = g_temp1 ^ RC;
	g_out[1] = g_temp2;
	g_out[2] = g_temp3;
	g_out[3] = g_temp0;

	BITE h_out[4];
	byte_sub(g_out[0] ^ inKey0[0] ^ inKey0[4] ^ inKey0[8]  ^ inKey0[12], &h_out[0] );
	byte_sub(g_out[1] ^ inKey0[1] ^ inKey0[5] ^ inKey0[9]  ^ inKey0[13], &h_out[1] );
	byte_sub(g_out[2] ^ inKey0[2] ^ inKey0[6] ^ inKey0[10] ^ inKey0[14], &h_out[2] );
	byte_sub(g_out[3] ^ inKey0[3] ^ inKey0[7] ^ inKey0[11] ^ inKey0[15], &h_out[3] );


	outKey0[0]  = g_out[0] ^ inKey0[0];
	outKey0[1]  = g_out[1] ^ inKey0[1];
	outKey0[2]  = g_out[2] ^ inKey0[2];
	outKey0[3]  = g_out[3] ^ inKey0[3];
	outKey0[4]  = g_out[0] ^ inKey0[0] ^ inKey0[4];
	outKey0[5]  = g_out[1] ^ inKey0[1] ^ inKey0[5];
	outKey0[6]  = g_out[2] ^ inKey0[2] ^ inKey0[6];
	outKey0[7]  = g_out[3] ^ inKey0[3] ^ inKey0[7];
	outKey0[8]  = g_out[0] ^ inKey0[0] ^ inKey0[4] ^ inKey0[8];
	outKey0[9]  = g_out[1] ^ inKey0[1] ^ inKey0[5] ^ inKey0[9];
	outKey0[10] = g_out[2] ^ inKey0[2] ^ inKey0[6] ^ inKey0[10];
	outKey0[11] = g_out[3] ^ inKey0[3] ^ inKey0[7] ^ inKey0[11];
	outKey0[12] = g_out[0] ^ inKey0[0] ^ inKey0[4] ^ inKey0[8]  ^ inKey0[12];
	outKey0[13] = g_out[1] ^ inKey0[1] ^ inKey0[5] ^ inKey0[9]  ^ inKey0[13];
	outKey0[14] = g_out[2] ^ inKey0[2] ^ inKey0[6] ^ inKey0[10] ^ inKey0[14];
	outKey0[15] = g_out[3] ^ inKey0[3] ^ inKey0[7] ^ inKey0[11] ^ inKey0[15];

	outKey1[0]  = h_out[0] ^ inKey1[0];
	outKey1[1]  = h_out[1] ^ inKey1[1];
	outKey1[2]  = h_out[2] ^ inKey1[2];
	outKey1[3]  = h_out[3] ^ inKey1[3];
	outKey1[4]  = h_out[0] ^ inKey1[0] ^ inKey1[4];
	outKey1[5]  = h_out[1] ^ inKey1[1] ^ inKey1[5];
	outKey1[6]  = h_out[2] ^ inKey1[2] ^ inKey1[6];
	outKey1[7]  = h_out[3] ^ inKey1[3] ^ inKey1[7];
	outKey1[8]  = h_out[0] ^ inKey1[0] ^ inKey1[4] ^ inKey1[8];
	outKey1[9]  = h_out[1] ^ inKey1[1] ^ inKey1[5] ^ inKey1[9];
	outKey1[10] = h_out[2] ^ inKey1[2] ^ inKey1[6] ^ inKey1[10];
	outKey1[11] = h_out[3] ^ inKey1[3] ^ inKey1[7] ^ inKey1[11];
	outKey1[12] = h_out[0] ^ inKey1[0] ^ inKey1[4] ^ inKey1[8]  ^ inKey1[12];
	outKey1[13] = h_out[1] ^ inKey1[1] ^ inKey1[5] ^ inKey1[9]  ^ inKey1[13];
	outKey1[14] = h_out[2] ^ inKey1[2] ^ inKey1[6] ^ inKey1[10] ^ inKey1[14];
	outKey1[15] = h_out[3] ^ inKey1[3] ^ inKey1[7] ^ inKey1[11] ^ inKey1[15];
}


void mix_cols( BITE OutData[NUM_DATA_BYTES], BITE inData[NUM_DATA_BYTES] ){

	// inData[0],  inData[1],  inData[2],  inData[3];
	// inData[4],  inData[5],  inData[6],  inData[7];
	// inData[8],  inData[9],  inData[10], inData[11];
	// inData[12], inData[13], inData[14], inData[15];

	BITE inByte0_sh; BITE inByte1_sh;
	BITE inByte2_sh; BITE inByte3_sh;
	
	BITE inByte0_mul2; BITE inByte1_mul2;
	BITE inByte2_mul2; BITE inByte3_mul2;
	
	BITE inByte0_mul3; BITE inByte1_mul3;
	BITE inByte2_mul3; BITE inByte3_mul3;

	for (int i=0; i<NUM_DATA_BYTES; i+=4){
		inByte0_sh = inData[i] << 1;
		inByte1_sh = inData[i+1] << 1;
		inByte2_sh = inData[i+2] << 1;
		inByte3_sh = inData[i+3] << 1;
		
		if( inData[i] & (BITE) 128 )  inByte0_mul2 = inByte0_sh ^ (BITE) 27;
		else inByte0_mul2 = inByte0_sh;
		if( inData[i+1] & (BITE) 128 ) inByte1_mul2 = inByte1_sh ^ (BITE) 27;
		else inByte1_mul2 = inByte1_sh;
		if( inData[i+2] & (BITE) 128 ) inByte2_mul2 = inByte2_sh ^ (BITE) 27;
		else inByte2_mul2 = inByte2_sh;
		if( inData[i+3] & (BITE) 128 ) inByte3_mul2 = inByte3_sh ^ (BITE) 27;
		else inByte3_mul2 = inByte3_sh;

		inByte0_mul3 = inByte0_mul2 ^ inData[i];
		inByte1_mul3 = inByte1_mul2 ^ inData[i+1];
		inByte2_mul3 = inByte2_mul2 ^ inData[i+2];
		inByte3_mul3 = inByte3_mul2 ^ inData[i+3];

		OutData[i]   = inByte0_mul2 ^ inByte1_mul3 ^ inData[i+2]  ^ inData[i+3];
		OutData[i+1] = inData[i] 	^ inByte1_mul2 ^ inByte2_mul3 ^ inData[i+3];
		OutData[i+2] = inData[i]    ^ inData[i+1]  ^ inByte2_mul2 ^ inByte3_mul3;
		OutData[i+3] = inByte0_mul3 ^ inData[i+1]  ^ inData[i+2]  ^ inByte3_mul2;
	}

}



void add_rnd_key( BITE OutData[NUM_DATA_BYTES], BITE inData[NUM_DATA_BYTES], BITE SubKey[NUM_DATA_BYTES] ){
	for(int i=0; i<NUM_DATA_BYTES; i++){
		OutData[i] = inData[i] ^ SubKey[i];
	}

}


void byte_sub(BITE input_byte, BITE* output_byte){
	BITE m;
	BITE n;

	m = ( input_byte >> 4 );
	n = input_byte & (BITE) 15;
	*output_byte = SBox[m][n];
}

void sub_bytes( BITE outText[NUM_DATA_BYTES], BITE inText[NUM_DATA_BYTES]) {

	for(int i=0; i<NUM_DATA_BYTES; i++) {
		byte_sub(inText[i], &outText[i]);
	}
}

void shift_rows( BITE outText[NUM_DATA_BYTES], BITE inText[NUM_DATA_BYTES]){
	outText[0]  = inText[0];
	outText[1]  = inText[5];
	outText[2]  = inText[10];
	outText[3]  = inText[15];
	outText[4]  = inText[4];
	outText[5]  = inText[9];
	outText[6]  = inText[14];
	outText[7]  = inText[3];
	outText[8]  = inText[8];
	outText[9]  = inText[13];
	outText[10] = inText[2];
	outText[11] = inText[7];
	outText[12] = inText[12];
	outText[13] = inText[1];
	outText[14] = inText[6];
	outText[15] = inText[11];
}

void pre_round_transform( BITE input[NUM_DATA_BYTES], BITE SubKey[NUM_DATA_BYTES], BITE output[NUM_DATA_BYTES]){
	add_rnd_key( output, input, SubKey );
}
