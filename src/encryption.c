#include "encryption.h"
#include <stdio.h>

void encryptFile(const char* inputFile, const char* outputFile) {
    FILE *inFile = fopen(inputFile, "rb");
    if (!inFile) {
        fprintf(stderr, "Error: Could not open input file: %s\n", inputFile);
        return;
    }

    FILE *outFile = fopen(outputFile, "wb");
    if (!outFile) {
        fprintf(stderr, "Error: Could not open output file: %s\n", outputFile);
        fclose(inFile);
        return;
    }

    char ch;

    while ((ch = fgetc(inFile)) != EOF) {
        ch = ch ^ 0xAA; // XOR encryption
        fputc(ch, outFile);
    }

    fclose(inFile);
    fclose(outFile);
}

void decryptFile(const char* inputFile, const char* outputFile) {
    encryptFile(inputFile, outputFile); //XOR decryption is the same as encryption but reversed
}
