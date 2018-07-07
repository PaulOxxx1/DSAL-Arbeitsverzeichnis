void topoSort(List adj[n], int n, int &topo[n]) {
  int color[n] = WHITE; topoNum = 0;
  for (int start=0;start<n;start++) {
    // Starte so lange von diesem Knoten,
    // bis es keine Pfade von hier aus mehr gibt,
    // dann ist der Startknoten selbst das Ende
    // eines Pfades gewesen und schwarz
    while (color[start] == WHITE) {
      // Beginne (wieder) vom Startknoten aus
      int next = start;
      // Gehe so lange weiter,
      // bis es keinen naechsten weissen Knoten mehr gibt
      while (color[next] == WHITE) {
        // Merke die den (neuen) aktuellen Knoten
        int curr = next;
        // Durchsuche alle seine Nachbarn nach
        // einem geeigneten naechsten Knoten
        for (neighbor in reverse(adj[curr])) {
          if (color[neighbor] == WHITE) {
            // Kommt als naechster Knoten in Frage
            next = neighbor;
          }
          // Durch die umgekehrte Liste ist sichergestellt,
          // dass die Reihenfolge stimmt
        }
        if (curr == next) {
          // Kann nicht mehr weiter, da es keinen geeigneten
          // naechsten Knoten mehr gibt, z.B. weil alle Nachbarn
          // schon schwarz sind oder es keine Nachbarn gibt
          topo[curr] = ++topoNum;
          color[curr] = BLACK;
          // Jetzt wird in die erste while Schleife gesprungen,
          // also wieder mit dem Startknoten begonnen
        } else {
          // Fahre beim Nachbarn fort
        }
      }
    }
  }
}