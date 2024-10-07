# File Encryption/Decryption Tool

This is a file encryption and decryption tool written in C. It uses XOR encryption to securely encode and decode files.

## Description

This project is a simple command-line application designed to facilitate the encryption and decryption of files. Users can choose to encrypt or decrypt specific text files by providing the necessary input and output file paths.

The tool is cross-platform and works on both **Linux/macOS** and **Windows**, thanks to platform-specific handling in the code.

## Features

- Encrypt a file using XOR encryption
- Decrypt a file using XOR decryption (same operation)
- Unit tests to validate encryption and decryption functionality

## Build and Run

### Prerequisites
- C compiler (e.g., `gcc`)

### Build with `Makefile`

To build the project, run:

```bash
make
```
This will compile the source files and generate the encryption_tool executable in the build/ directory.

## Run the Program
After building the project, you can run the encryption tool as follows:

```bash
./build/encryption_tool
```

You will be prompted to enter an input file path and an output file path for encryption or decryption.

## Test the Project
Unit tests have been added to verify the functionality of encryption and decryption. To compile and run the tests, run:

```bash
make test
```
This will build the test executable (test_encryption_tool) and run the unit tests to ensure the encryption and decryption functions work as expected.

## Clean Up
To clean up the build artifacts (e.g., object files and executables), run:

```bash
make clean
```
This will remove the compiled object files and binaries from the build/ directory.