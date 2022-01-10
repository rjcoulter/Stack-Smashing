/**
 * Bad usage of a format function
 */
int func1(char *user) { 
  printf(user);
}

/**
 * Ok usage of a format function
 */
int func2(char *user) {
  printf("%s", user);
}
