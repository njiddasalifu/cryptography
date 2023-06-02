#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TEXT_SIZE 1000
#define MAX_KEY_SIZE 100

typedef struct {
    int x;
    int y;
    char letter;
} BealeCipherWord;

void encrypt(char plaintext[], char key[], BealeCipherWord cipherWords[], int numCipherWords) {
    // Encrypt plaintext
    printf("Encrypted text: ");
    for (int i = 0; i < strlen(plaintext); i++) {
        if (plaintext[i] != ' ') {
            for (int j = 0; j < numCipherWords; j++) {
                if (plaintext[i] == cipherWords[j].letter) {
                    printf("%d%d ", cipherWords[j].x, cipherWords[j].y);
                    break;
                }
            }
        }
    }
    
    printf("\n");
}

void decrypt(char ciphertext[], char key[], BealeCipherWord cipherWords[], int numCipherWords) {
    // Decrypt ciphertext
    printf("Decrypted text: ");
    char* token = strtok(ciphertext, " ");
    while (token != NULL) {
        int x = token[0] - '0';
        int y = token[1] - '0';
        for (int j = 0; j < numCipherWords; j++) {
            if (cipherWords[j].x == x && cipherWords[j].y == y) {
                printf("%c", cipherWords[j].letter);
                break;
            }
        }
        token = strtok(NULL, " ");
    }
    
    printf("\n");
}

int main() {
    char plaintext[MAX_TEXT_SIZE];
    char ciphertext[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    BealeCipherWord cipherWords[MAX_TEXT_SIZE];
    int numCipherWords = 0;
    int choice;
    
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    getchar(); // getting the new line character newline character
    
    printf("Enter the text: ");
    if (choice == 1) {
        fgets(plaintext, MAX_TEXT_SIZE, stdin);
    } else {
        fgets(ciphertext, MAX_TEXT_SIZE, stdin);
    }
    
    printf("Enter the key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    
    // Remove newline characters from input
    if (choice == 1) {
        plaintext[strcspn(plaintext, "\n")] = '\0';
    } else {
        ciphertext[strcspn(ciphertext, "\n")] = '\0';
    }
    key[strcspn(key, "\n")] = '\0';
    
    // Create cipher words from key
    for (int i = 0; i < strlen(key); i++) {
        if (key[i] != ' ') {
            cipherWords[numCipherWords].letter = key[i];
            cipherWords[numCipherWords].x = i / 10 + 1;
            cipherWords[numCipherWords].y = i % 10 + 1;
            numCipherWords++;
        }
    }
    //cipherWords and numCipherWords parameters here are not
    // passed directly as function arguments, but are instead 
    //created and initialized in the main function before the 
    //functions are called.
    if (choice == 1) {
        encrypt(plaintext, key, cipherWords, numCipherWords);
    } else {
        decrypt(ciphertext, key, cipherWords, numCipherWords);
    }
    
    return 0;
}