#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/rand.h>
#include <openssl/fortuna.h>

#define POOL_SIZE 32
#define KEY_LEN 32

int main() {
  int i, n;
  unsigned char *rand_nums;
  unsigned char key[KEY_LEN];

  // initialize the key with entropy from the OpenSSL PRNG
  RAND_bytes(key, KEY_LEN);

  // initialize the Fortuna PRNG with the key
  FORTUNA_CTX ctx;
  fortuna_init(&ctx, key, KEY_LEN);

  printf("Enter the number of random numbers to generate: ");
  scanf("%d", &n);

  // allocate memory for the random numbers array
  rand_nums = (unsigned char*) malloc(n * sizeof(unsigned char));

  // generate the random numbers using the Fortuna PRNG
  for (i = 0; i < n; i++) {
    fortuna_generate(&ctx, rand_nums + i, 1);
  }

  // print the random numbers
  printf("Random numbers generated:\n");
  for (i = 0; i < n; i++) {
    printf("%d\n", rand_nums[i]);
  }

  // free the memory allocated for the random numbers array
  free(rand_nums);

  return 0;
}