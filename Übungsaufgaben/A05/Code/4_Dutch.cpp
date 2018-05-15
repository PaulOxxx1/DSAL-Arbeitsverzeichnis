void DutchNationalFlag(Color E[], int n) {
  int r=0, b=n+1;
  int u=1;
  while (u<b) {
    if (E[u] == rot) {
      sawp(E[r+1], E[u]);
      r++;
      u++;      
    }
    if (E[u] == weiss) {
      u++;
    }
    if (E[u] == blau) {
      swap(E[b-1], E[u]);
      b--;
    }
  }
}