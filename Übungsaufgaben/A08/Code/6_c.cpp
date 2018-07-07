void function(int n) {
  a = 1;
  b = 1;
  for (int i=0;i<n;i++) {
    a = a*3;
    b = b*n;
  }
  k = a + b;
  
  for (int i=0;i<k;i++) {
    print();
  }
}