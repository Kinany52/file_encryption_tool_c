#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include "encryption.h"
#include <sys/stat.h>
#include <sys/types.h>

// Helper function to read a file's content into a buffer
char* read_file(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        perror("Failed to open file for reading");
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char* buffer = (char*)malloc(file_size + 1);  // Allocate memory for the file contents
    if (!buffer) {
        perror("Memory allocation failed");
        fclose(file);
        return NULL;
    }

    fread(buffer, 1, file_size, file);
    buffer[file_size] = '\0'; // Null-terminate the buffer

    fclose(file);
    return buffer;
}

// Helper function to write content to a file
void write_file(const char* filename, const char* content) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        perror("Failed to open file for writing");
        return;
    }

    fwrite(content, sizeof(char), strlen(content), file);
    fclose(file);
}

// Test case for encryption and decryption
int test_encryption_and_decryption(const char* input_filename, const char* encrypted_filename, const char* decrypted_filename) {
    // Step 1: Encrypt the input file
    encryptFile(input_filename, encrypted_filename);

    // Step 2: Decrypt the encrypted file
    decryptFile(encrypted_filename, decrypted_filename);

    // Step 3: Compare the decrypted file with the original input file
    char* original_content = read_file(input_filename);
    char* decrypted_content = read_file(decrypted_filename);

    if (original_content && decrypted_content) {
        if (strcmp(original_content, decrypted_content) == 0) {
            printf("Test passed: Decrypted content matches the original content!\n");
            free(original_content);   // Free memory allocated by read_file
            free(decrypted_content);  // Free memory allocated by read_file
            return 0;
        } else {
            printf("Test failed: Decrypted content does NOT match the original content!\n");
        }
    }

    free(original_content);   // Free memory allocated by read_file
    free(decrypted_content);  // Free memory allocated by read_file
    return 1; // Indicate test failure
}

// Function to create a directory if it doesn't exist
void create_output_directory() {
    struct stat st = {0};

    if (stat("output", &st) == -1) {
        if (mkdir("output", 0700) != 0) {
            perror("Failed to create output directory");
            exit(EXIT_FAILURE);
        }
    }
}

int main() {
    // Ensure output directory exists
    create_output_directory();

    // Use the output/ directory for test files
    const char* input_filename = "output/test_input.txt";
    const char* encrypted_filename = "output/test_encrypted.txt";
    const char* decrypted_filename = "output/test_decrypted.txt";

    // Create a test input file
    write_file(input_filename, "This is a test for encryption!");

    // Run the test
    int result = test_encryption_and_decryption(input_filename, encrypted_filename, decrypted_filename);

    if (result == 0) {
        printf("All tests passed!\n");
    } else {
        printf("Some tests failed.\n");
    }

    return result;
}