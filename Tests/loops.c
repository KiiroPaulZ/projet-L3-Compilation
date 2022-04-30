extern int printd( int i );

int main() {
  int i;
  i = 0;
  while ( i < 10 ) {
    int j;
    printd(i+j);
    i = i+2;
  }

  for ( i = -10; i <= 10; i = i+1 )
    printd(i);
    
  i = 0;
  while (i >= -20) {
    int j;
    printd(i);
    i = i-1;
  }
  return 0;
}
