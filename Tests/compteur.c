extern int printd(int i);

int main() {
  int k;
  for ( k = 0; k < 1000; k = k+1 ) {
    int k;
    printd(k);
  }
  return 0;
}
