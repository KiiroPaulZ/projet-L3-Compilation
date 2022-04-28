extern int * printd(int i);


int foo(int i){
  return i;
}

int * foo2(int * k, int o){
  return k;
}

int foo3(){
  return i;
}

void main(){
  int i;
  int j;
  i = 1;
  j = 2;
  printd(i+j);
  printd(45000+j);
  printd(i+123);
  printd(45000+123);
  printd(i+(j+0));
  printd((i+0)+j);
  printd((i+0)+(j+0));
  printd((i+0)+123);
  printd(45000+(j+0));
  return 0;
}
