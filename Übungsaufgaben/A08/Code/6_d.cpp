void function(int n) {
  k = 0;
  while (n>1) {
    n = n/2;
    k++;
  }
  
  while (k>1) {
    k = k/2;
    print();
  }
}