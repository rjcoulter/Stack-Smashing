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

}
