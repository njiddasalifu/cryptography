#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TEXT_SIZE 1000
#define GRID_SIZE 5

typedef struct {
    int x;
    int y;
} PlayfairPair;

void createGrid(char key[], char grid[][GRID_SIZE]) {
    int k = 0;
    int i, j;
    int used[26] = {0};
    
    // Fill in key
    for (i = 0; i < strlen(key); i++) {
        char c = tolower(key[i]);
        if (c == 'j') {
            c = 'i';
        }
        if (!used[c-'a']) {
            grid[k/GRID_SIZE][k%GRID_SIZE] = c;
            used[c-'a'] = 1;
            k++;
        }
    }
    
    // Fill in remaining letters
    for (i = 0; i < 26; i++) {
        char c = 'a' + i;
        if (c == 'j') {
            continue;
        }
        if (!used[c-'a']) {
            grid[k/GRID_SIZE][k%GRID_SIZE] = c;
            used[c-'a'] = 1;
            k++;
        }
    }
}

void encrypt(char plaintext[], char key[], char ciphertext[]) {
    char grid[GRID_SIZE][GRID_SIZE];
    createGrid(key, grid);
    
    int plaintext_len = strlen(plaintext);
    int i, j;
    int pair_count = 0;
    PlayfairPair pairs[MAX_TEXT_SIZE/2];
    
    // Generate pairs
    for (i = 0; i < plaintext_len; i++) {
        if (isalpha(plaintext[i])) {
            pairs[pair_count].x = i;
            pairs[pair_count].y = plaintext[i];
            pair_count++;
        }
    }
    if (pair_count % 2 != 0) {
        pairs[pair_count].x = plaintext_len;
        pairs[pair_count].y = 'x';
        pair_count++;
    }
    
    // Encrypt pairs
    for (i = 0; i < pair_count; i += 2) {
        int x1 = pairs[i].x;
        int x2 = pairs[i+1].x;
        char c1 = tolower(pairs[i].y);
        char c2 = tolower(pairs[i+1].y);
        int r1 = x1 / GRID_SIZE;
        int c1_ = x1 % GRID_SIZE;
        int r2 = x2 / GRID_SIZE;
        int c2_ = x2 % GRID_SIZE;
        if (c1 == 'j') {
            c1 = 'i';
        }
        if (c2 == 'j') {
            c2 = 'i';
        }
        if (r1 == r2) {
            c1_ = (c1_ + 1) % GRID_SIZE;
            c2_ = (c2_ + 1) % GRID_SIZE;
        } else if (c1_ == c2_) {
            r1 = (r1 + 1) % GRID_SIZE;
            r2 = (r2 + 1) % GRID_SIZE;
        } else {
            int tmp = c1_;
            c1_ = c2_;
            c2_ = tmp;
        }
        ciphertext[x1] = grid[r1][c1_];
        ciphertext[x2] = grid[r2][c2_];
    }
    ciphertext[plaintext_len] = '\0';
    printf("Encrypted text: %s\n", ciphertext);
}

void decrypt(char ciphertext[], char key[], char plaintext[]) {
    char grid[GRID_SIZE][GRID_SIZE];
    createGrid(key, grid);
    
    int ciphertext_len = strlen(ciphertext);
    int i, j;
    int pair_count = 0;
    PlayfairPair pairs[MAX_TEXT_SIZE/2];
    
    // Generate pairs
    for (i = 0; i < ciphertext_len; i++) {
        if (isalpha(ciphertext[i])) {
            pairs[pair_count].x = i;
            pairs[pair_count].y = ciphertext[i];
            pair_count++;
        }
    }
    if (pair_count % 2 != 0) {
        printf("Invalid ciphertext!\n");
        return;
    }
    
    // Decrypt pairs
    for (i = 0; i < pair_count; i += 2) {
        int x1 = pairs[i].x;
        int x2 = pairs[i+1].x;
        char c1 = tolower(pairs[i].y);
        char c2 = tolower(pairs[i+1].y);
        int r1 = x1 / GRID_SIZE;
        int c1_ = x1 % GRID_SIZE;
        int r2 = x2 / GRID_SIZE;
        int c2_ = x2 % GRID_SIZE;
        if (c1 == 'j') {
            c1 = 'i';
        }
        if (c2 == 'j') {
            c2 = 'i';
        }
        if (r1 == r2) {
            c1_ = (c1_ + GRID_SIZE - 1) % GRID_SIZE;
            c2_ = (c2_ + GRID_SIZE - 1) % GRID_SIZE;
        } else if (c1_ == c2_) {
            r1 = (r1 + GRID_SIZE - 1) % GRID_SIZE;
            r2 = (r2 + GRID_SIZE - 1) % GRID_SIZE;
        } else {
            int tmp = c1_;
            c1_ = c2_;
            c2_ = tmp;
        }
        plaintext[x1] = grid[r1][c1_];
        plaintext[x2] = grid[r2][c2_];
    }
    plaintext[ciphertext_len] = '\0';
    printf("Decrypted text: %s\n", plaintext);
}

int main() {
    char plaintext[MAX_TEXT_SIZE];
    char ciphertext[MAX_TEXT_SIZE];
    char key[MAX_TEXT_SIZE];
    int choice;
    
    printf("Enter 1 to encrypt or 2 to decrypt: ");
    scanf("%d", &choice);
    getchar(); // geting newline character
    
    printf("Enter the text: ");
    if (choice == 1) {
        fgets(plaintext, MAX_TEXT_SIZE, stdin);
    } else {
        fgets(ciphertext, MAX_TEXT_SIZE, stdin);
    }
    
    printf("Enter the key: ");
    fgets(key, MAX_TEXT_SIZE, stdin);
    
    // Remove newline characters from input
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