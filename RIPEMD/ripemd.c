#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/ripemd.h>

#define MAX_INPUT_LENGTH 1000

int main() {
  unsigned char input[MAX_INPUT_LENGTH];
  unsigned char output[RIPEMD160_DIGEST_LENGTH];
  int i;

  printf("Enter a string to hash (up to %d characters):\n", MAX_INPUT_LENGTH - 1);
  fgets(input, MAX_INPUT_LENGTH, stdin);
  input[strcspn(input, "\n")] = 0; // Remove trailing newline from input

//THE RIPEMD160 FUNCTION CALL FROM OPENSSL LIBRARY
  RIPEMD160(input, strlen(input), output);

  printf("RIPEMD-160 hash of '%s': ", input);
  for (i = 0; i < RIPEMD160_DIGEST_LENGTH; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");

  return 0;
}