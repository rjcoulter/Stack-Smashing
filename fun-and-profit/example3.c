void function(int a, int b, int c) {
  char buffer1[5];
  char buffer2[10];
  int* ret;
  
  // This adds 12 to buffer1[]'s address,
  // giving us the address where the return
  // address is stored, now we want to skip
  // past the assignemnt on line 20 to the 
  // printf call
  ret = buffer1 + 12;
  (*ret) += 8;
}

void main() {
  int x;

  x = 0;
  function(1, 2, 3);
  x = 1;
  printf("%d\n", x);
}
