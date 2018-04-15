program FindSecondGreatest
  // Gegeben: Liste L
  newL = L; // Kopie der Liste, die sortiert wird
  for (int m=n;m>1;m--) {
    for (int i=0;i<m-1;i=i+1) {
      a = newL.first;
      for (int j=0;j<i;j++) a = a.next;
      if (a.value < a.next.value) {
        // Elemente vertauschen
        b = a;
        a = a.next;
        a.next = b;
      }
    }
  }
  secondGreatest = newL.first.next;
end program