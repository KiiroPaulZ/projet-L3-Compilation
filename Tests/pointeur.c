extern int printd( int i );

int main() {
   int *i;
   int *j;
   
   i=malloc(sizeof(int)); /* on doit sizeof avec une variable */
   j=malloc(sizeof(int));

   *i=4;
  
   printd(*i);

   *j=6;
   printd(*j);

   /**j=*j+(*i)++; /* le langage ne reconnait pas ++ */
   printd(*j);
   return 0;
}
