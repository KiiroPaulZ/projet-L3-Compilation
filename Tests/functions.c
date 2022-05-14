extern int printd( int i );
int toto;

int foo(int i);

int foo(int i, int k){
  int a;
  if(i <= 10)
    return k;
  return 0;
}

int foo(int i);

int foo(int i, int k, int ok){ 
  if(i <= 10)
    return k;
  return 0;
}

int main() {
  int a;
  a = a + 1;
  return foo(1, a);
}
