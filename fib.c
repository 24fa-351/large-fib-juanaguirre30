#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

uint64_t fib_r(uint64_t input) {
   if (input < 2) {
      return input; 
   } else {
      return fib_r(input - 1) + fib_r(input - 2); 
   } 
}

uint64_t fib_i(uint64_t input) {
   uint64_t previous = 0; 
   uint64_t current = 1; 
   uint64_t next = 0; 
   

   for (uint64_t i = 0; i < input; i++) {
      next = previous + current;
      previous = current;
      current = next;
   }

   return previous;
}

int main(int argc, char* argv[]){

   uint64_t inputNumber = atoi(argv[1]);
   char option = argv[2][0]; 

   uint64_t decrement = 1;
   inputNumber -= decrement;  

   if (inputNumber > 93) {
      printf("Input number is too large and will cause overflow.\n");
      return 1;
   }

   uint64_t result;
   if (option == 'r') { 
      result = fib_r(inputNumber);
   } else { 
      result = fib_i(inputNumber);
   }

   printf("%lu\n", result);

   return 0; 
}