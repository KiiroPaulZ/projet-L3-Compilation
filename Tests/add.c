extern int printd(int i);

/* int (*fact) (int no); */

int f(int n){
  return n;
}

int * foo(int * k, int m){
  return k - m;
}

int main(int a){
  int i;
  int j;
  i = a + b;
  j = 2;
  /*fact = &f;
  (*fact)(1);*/
  printd(j);
  printd(i);
  foo(i, b);
  printd(i);
  foo(a, j);
  return 0;
}
