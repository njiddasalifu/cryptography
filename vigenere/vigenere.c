// caeser cypher is a substitution cypher
// caeser algorithm:  For any plaintext letter 'a', substitue
// the ciphertext letter 'B' ~
// formular B = E(a, k)mod26 = (a + k)mod26
// k =  key (k= 3 always) and a= plaintext

//c program to implement the caeset cipher
#include<stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000
#define MAX_KEY_SIZE 100
//function used to encrypt the plaintext it takes an empty ciphertext array
// to use it and store the cipher text
void encrypt(char plaintext[], char key[], char ciphertext[]) {
    int plaintext_len = strlen(plaintext);
    int key_len = strlen(key);
    int j = 0;
    for (int i = 0; i < plaintext_len; i++) {
        if (isalpha(plaintext[i])) {
            int shift = tolower(key[j % key_len]) - 'a';
            ciphertext[i] = ((tolower(plaintext[i]) - 'a' + shift) % 26) + 'a';
            j++;
        } else {
            ciphertext[i] = plaintext[i];
        }
    }
    //cipher text is genereted here
    ciphertext[plaintext_len] = '\0';
    printf("Encrypted text: %s\n", ciphertext);
}
//decrypt function which takes the ciphertext generated from the encrypt function
// a key used to encrypt and the an empty plaintext array to store the decrypted text
void decrypt(char ciphertext[], char key[], char plaintext[]) {
    int ciphertext_len = strlen(ciphertext);
    int key_len = strlen(key);
    int j = 0;
    for (int i = 0; i < ciphertext_len; i++) {
        if (isalpha(ciphertext[i])) {
            int shift = tolower(key[j % key_len]) - 'a';
            int c = tolower(ciphertext[i]) - 'a' - shift;
            if (c < 0) {
                c += 26;
            }
            plaintext[i] = c + 'a';
            j++;
        } else {
            plaintext[i] = ciphertext[i];
        }
    }
    //plaintext generated
    plaintext[ciphertext_len] = '\0';
    printf("Decrypted text: %s\n", plaintext);
}

int main() {
    char plaintext[MAX_TEXT_SIZE];
    char ciphertext[MAX_TEXT_SIZE];
    char key[MAX_KEY_SIZE];
    int choice;
    
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    getchar(); // getting the  newline character
    
    printf("Enter the text: ");
    if (choice == 1) {
        fgets(plaintext, MAX_TEXT_SIZE, stdin);
    } else {
        fgets(ciphertext, MAX_TEXT_SIZE, stdin);
    }
    
    printf("Enter the key: ");
    fgets(key, MAX_KEY_SIZE, stdin);
    
    // Removing newline characters from input
    if (choice == 1) {
        plaintext[strcspn(plaintext, "\n")] = '\0';
    } else {
        ciphertext[strcspn(ciphertext, "\n")] = '\0';
    }
    key[strcspn(key, "\n")] = '\0';
    
    if (choice == 1) {
        encrypt(plaintext, key, ciphertext);
    } else {
        decrypt(ciphertext, key, plaintext);
    }
    
    return 0;
}