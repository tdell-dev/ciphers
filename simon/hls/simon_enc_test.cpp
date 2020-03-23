#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simon.h"


int main()
{
	WORD gold_plaintxt0;
	WORD gold_plaintxt1;
	WORD gold_key[4];
	WORD gold_cyphertxt0;
	WORD gold_cyphertxt1;
	WORD test_cyphertxt0;
	WORD test_cyphertxt1;

	WORD* pointer0 = &test_cyphertxt0;
	WORD* pointer1 = &test_cyphertxt1;

    gold_plaintxt0 = 0x6565;
    gold_plaintxt1 = 0x6877;

    gold_key[0] = 0x1918;
    gold_key[1] = 0x1110;
    gold_key[2] = 0x0908;
    gold_key[3] = 0x0100;

    gold_cyphertxt0 = 0xc69b;
    gold_cyphertxt1 = 0xe9bb;
    
    int j=0;

    simon32s64_encrypt( gold_plaintxt0, gold_plaintxt1, gold_key, pointer0, pointer1);
   
    if (gold_cyphertxt0 != test_cyphertxt0 || gold_cyphertxt1 != test_cyphertxt1) {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "Test Pt %d: %04x, %04x\n", j, test_cyphertxt0, test_cyphertxt1);
        fprintf(stdout, "Gold Pt %d: %04x, %04x\n", j, gold_cyphertxt0, gold_cyphertxt1);
        fprintf(stdout, "*******************************************\n");
        return 1;
    } else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "Test Pt %d: %04x, %04x\n", j, test_cyphertxt0, test_cyphertxt1);
        fprintf(stdout, "Gold Pt %d: %04x, %04x\n", j, gold_cyphertxt0, gold_cyphertxt1);
        fprintf(stdout, "*******************************************\n");
         
    }
        
    fprintf(stdout, "*********************************************************\n");
    fprintf(stdout, "PASS: The 16bit Block output matches the golden output!\n");
    fprintf(stdout, "*********************************************************\n");
   
    WORD64 gold_plaintxt0_64;
    WORD64 gold_plaintxt1_64;
    WORD64 gold_key_64[4];
    WORD64 gold_cyphertxt0_64;
    WORD64 gold_cyphertxt1_64;
    WORD64 test_cyphertxt0_64;
    WORD64 test_cyphertxt1_64;

    WORD64* pointer0_64 = &test_cyphertxt0_64;
    WORD64* pointer1_64 = &test_cyphertxt1_64;

    gold_plaintxt0_64 = 0x74206e69206d6f6f;
    gold_plaintxt1_64 = 0x6d69732061207369;

    gold_key_64[0] = 0x1f1e1d1c1b1a1918;
    gold_key_64[1] = 0x1716151413121110;
    gold_key_64[2] = 0x0f0e0d0c0b0a0908;
    gold_key_64[3] = 0x0706050403020100;

    gold_cyphertxt0_64 = 0x8d2b5579afc8a3a0;
    gold_cyphertxt1_64 = 0x3bf72a87efe7b868;
    
    j=0;

    simon128s256_encrypt( gold_plaintxt0_64, gold_plaintxt1_64, gold_key_64, pointer0_64, pointer1_64);
   
    if (gold_cyphertxt0_64 != test_cyphertxt0_64 || gold_cyphertxt1_64 != test_cyphertxt1_64) {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "FAIL: Output DOES NOT match the golden output\n");
        fprintf(stdout, "Test Pt %d: %04x, %04x\n", j, test_cyphertxt0_64, test_cyphertxt1_64);
        fprintf(stdout, "Gold Pt %d: %04x, %04x\n", j, gold_cyphertxt0_64, gold_cyphertxt1_64);
        fprintf(stdout, "*******************************************\n");
        return 1;
    } else {
        fprintf(stdout, "*******************************************\n");
        fprintf(stdout, "Test Pt %d: %04x, %04x\n", j, test_cyphertxt0_64, test_cyphertxt1_64);
        fprintf(stdout, "Gold Pt %d: %04x, %04x\n", j, gold_cyphertxt0_64, gold_cyphertxt1_64);
        fprintf(stdout, "*******************************************\n");
         
    }
        
    fprintf(stdout, "*********************************************************\n");
    fprintf(stdout, "PASS: The 64-bit Block output matches the golden output!\n");
    fprintf(stdout, "*********************************************************\n");



    return 0;
    

}
