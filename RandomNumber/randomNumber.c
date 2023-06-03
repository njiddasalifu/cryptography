#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//here we set the value of the seed as large as we want 
const int SEED = 123456789;

int main() {
  int i, n;
  int *rand_nums;

  srand(SEED); // setting the random seed

  printf("Enter the number of random numbers to generate: ");
  scanf("%d", &n);

  // allocating memory for the random numbers array
  rand_nums = (int*) malloc(n * sizeof(int));

  // generating the random numbers
  for (i = 0; i < n; i++) {
    rand_nums[i] = rand();
  }

  // print the random numbers
  printf("Random numbers generated:\n");
  for (i = 0; i < n; i++) {
    printf("%d\n", rand_nums[i]);
  }

  // clear memory for random numbers array
  free(rand_nums);

  return 0;
}