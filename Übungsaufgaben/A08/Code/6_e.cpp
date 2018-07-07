void function(int n) {
  k = 0;
  while (n > 1) {
    n = n/2;
    k++;
  }
  
  for (int i=0;i*i*i<k;i++) {
    print();
  }
}