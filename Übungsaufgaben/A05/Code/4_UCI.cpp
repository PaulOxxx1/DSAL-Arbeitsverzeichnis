int DutchNationalFlag(Color E[], int n, Color first, Color second) {
  int r=0, b=n+1;
  int u=1;
  while (u<b) {
    if ((E[u] != first) and (E[u] != second)) { // Element ist "bunt"
      sawp(E[r+1], E[u]);
      r++;
      u++;      
    }
    if (E[u] == first) {  // Element hat Farbe "first"
      u++;
    }
    if (E[u] == second) { // Element hat Farbe "second"
      swap(E[b-1], E[u]);
      b--;
    }
  }
  return r; // Anzahl der Elemente im ersten ("bunten") Bereich
}

int main() {
  // E ist gegeben, 5 Farben, unsortiert
  
  int x = DutchNationalFlag(E, E.size, GELB, GRUEN); // Lauzeit in Theta(n)
  
  // E enthaelt im Bereich 1 bis x nur BLAU, ROT und SCHWARZ unsortiert
  // und im Bereich x+1 bis n nur GELB (links) und GRUEN (rechts)
  
  DutchNationalFlag(E, x, ROT, SCHWARZ);  // Laufzeit in Theta(x)
  
  // E ist sortiert
  // BLAU, ROT, SCHWARZ, GELB, GRUEN
  return 0;
}