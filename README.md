# Symmetric XOR File Cipher Engine

A modular data security utility written in C that implements symmetric-key cryptography using bitwise Exclusive-OR (XOR) transformations. The project separates the encryption and decryption workflows into dedicated programs.

## How the Architecture Works
1. **Encrypt.c**: Collects a user-defined key token and a multi-word message via keyboard streams, prints the cleartext value to `data.txt`, and generates the masked ciphertext stream within `Newfile.txt`.
2. **Decrypt.c**: Targets the unmanaged byte array from `Newfile.txt`, prompts for the matching authorization key, decodes the mathematical shifts, and writes the recovered cleartext directly into `Decrypt.txt`.

## Engineering Highlights
- **Input Buffer Clearing:** Implements a stream disposal loop (`while (getchar() != '\n')`) to eliminate leftover newline characters, allowing the program to safely capture full lines of text containing spaces.
- **Defensive Pointer Validation:** Features explicit checking algorithms (`if (file == NULL)`) to gracefully stop execution and prevent runtime segmentation faults if system storage files fail to initialize.

## How to Compile & Run (Windows GCC)
To run this project locally in your terminal workspace:

```bash
# 1. Compile and run the encryption tool
gcc Encrypt.c -o encrypt
./encrypt

# 2. Compile and run the decryption tool
gcc Decrypt.c -o decrypt
./decrypt
```
