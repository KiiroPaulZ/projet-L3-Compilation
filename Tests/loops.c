extern int printd( int i );

int main() {
  int i;
  i = 0;

  while (i <= 10) {
    int i;
      printd(i);
  }
  for ( i = -10; i <= 10; i = i+1 )
    printd(i);

  while (i >= -20) {
    int j;
    printd(i);
  }
  return 0;
}
