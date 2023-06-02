#include <stdio.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000

void encrypt(char *plaintext, int shift);
void decrypt(char *ciphertext, int shift);

int main() {
    char plaintext[MAX_TEXT_SIZE];
    char ciphertext[MAX_TEXT_SIZE];
    int key;

    // Get plaintext input from user
    printf("Enter plaintext: ");
    fgets(plaintext, MAX_TEXT_SIZE, stdin);

    // Get key value from user
    printf("Enter key value (1-25): ");
    scanf("%d", &key);

    // Encrypt plaintext
    encrypt(plaintext, key);
    printf("Ciphertext: %s\n", plaintext);

    // Decrypt ciphertext
    decrypt(plaintext, key);
    printf("Decrypted text: %s\n", plaintext);

    return 0;
}

void encrypt(char *plaintext, int key) {
    int i = 0;
    while (plaintext[i] != '\0') {
        // key only alphabetic characters
        if (isalpha(plaintext[i])) {
            // Convert to lowercase for simplicity
            char c = tolower(plaintext[i]);
            // Apply key
            c = 'a' + (c - 'a' + key) % 26;
            // Convert back to original case
            if (isupper(plaintext[i])) {
                c = toupper(c);
            }
            plaintext[i] = c;
        }
        i++;
    }
}

void decrypt(char *ciphertext, int shift) {
    // Decryption is just encryption with negative shift
    encrypt(ciphertext, 26 - shift);
}