/**
 * Wrong usage of a format function
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

/**
 * Example function where we can't enlarge our buffer
 */
void func3(char *user) {
  char buffer[512];

  snprintf(buffer, sizeof (buffer), user);
  buffer[sizeof (buffer) - 1] = '\0';
}

void main() {
  // Situation one
  char tmpbuf[512];

  snprintf(tmpbuf, sizeof (tmpbuf), "foo: %s", user);
  tmpbuf[sizeof (tmpbuf) - 1] = '\0';
  syslog(LOG_NOTICE, tmpbuf);

  // BO like exploit
  char outbuf[512];
  char buffer[512];
  sprintf(buffer, "ERR Wrong command %400s", user);
  sprintf(outbuf, buffer);
  
  // The code below will print i = 6
  // b/c foobar if 6 bytes
  int i;
  printf ("foobar%n\n", (int *) &i);
  printf ("i = %d\n", i);


  int a;
  printf ("%10u%n", 7350, &a);
  /* a == 10 */

  int b;
  printf ("%150u%n", 7350, &b);
  /* b == 150 */
  
  /*
   * When printf returns foo[0] contains '\x40',
   * which is equal to 64, the number we used to 
   * increase the counter
   */
  unsigned char foo[4];
  printf("%64u%n", 7350, (int *) foo);
}
