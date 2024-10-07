#include <stdio.h>

void main() {
    int choice;
    char inputFilePath[256], outputFilePath[256];
    //void for now
    printf("File Encryption/Decryption Tool\n");
    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file path: ");
    scanf("%s", inputFilePath);

    printf("Enter output file path: ");
    scanf("%s", outputFilePath);
    
    
}