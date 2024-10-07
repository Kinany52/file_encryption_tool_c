#include <stdio.h>
#include "encryption.h"

int main() {
    int choice;
    char inputFilePath[256], outputFilePath[256];

    printf("File Encryption/Decryption Tool\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file path: ");
    scanf("%s", inputFilePath);

    printf("Enter output file path: ");
    scanf("%s", outputFilePath);
    
    if (choice == 1) {
        printf("Starting encryption...\n");
        encryptFile(inputFilePath, outputFilePath);
    }
    else if (choice == 2) {
        printf("Starting decryption...\n");
        decryptFile(inputFilePath, outputFilePath);
    }
    else {
        printf("Invalid choice!\n");
    }

    return 0; //program terminated successfully
}