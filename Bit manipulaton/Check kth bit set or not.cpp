bool checkKthBit(int n, int k){
       n>>=k;
       return (n&1)?1:0;
}

// or
/*

bool checkKthBit(int n, int k){
  int x = (1<<(k-1));
       return (n&x)?1:0;
}
*/
