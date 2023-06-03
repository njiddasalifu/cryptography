#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_INPUT_LENGTH 1000

int main() {
  unsigned char input[MAX_INPUT_LENGTH];
  unsigned char output[SHA256_DIGEST_LENGTH];
  int i;

  printf("Enter a string to hash (up to %d characters):\n", MAX_INPUT_LENGTH - 1);
  fgets(input, MAX_INPUT_LENGTH, stdin);
  input[strcspn(input, "\n")] = 0; // Remove trailing newline from input

//here, sha256 is just indicating that I am using the SHA-2 algorithm
  SHA256(input, strlen(input), output);

  printf("SHA-256 hash of '%s': ", input);
  for (i = 0; i < SHA256_DIGEST_LENGTH; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");

  return 0;
}