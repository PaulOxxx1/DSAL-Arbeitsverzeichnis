int modus = 0;
int* anzahl = new int[n-1];

for (int i=0;i<n-1;i++) {
  int x = l[i];
  anzahl[x-1]++;
}

for (int i=0;i<n-1;i++) {
  if (anzahl[i] > modus) {
    modus = i;
  }
}

delete[] anzahl;

return modus;