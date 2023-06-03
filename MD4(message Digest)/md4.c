#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md4.h>

#define MAX_INPUT_LENGTH 1000

int main() {
  unsigned char input[MAX_INPUT_LENGTH];
  unsigned char output[MD4_DIGEST_LENGTH];
  int i;

  printf("Enter a string to hash (up to %d characters):\n", MAX_INPUT_LENGTH - 1);
  fgets(input, MAX_INPUT_LENGTH, stdin);
  input[strcspn(input, "\n")] = 0; // Remove trailing newline from input

//MD4 is the message digest 4 algorithm
  MD4(input, strlen(input), output);

  printf("MD4 hash of '%s': ", input);
  for (i = 0; i < MD4_DIGEST_LENGTH; i++) {
    printf("%02x", output[i]);
  }
  printf("\n");

  return 0;
}