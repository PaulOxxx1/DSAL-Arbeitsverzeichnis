function sorted(first) returns element
  if (first.next == 0) {
    // Nur ein Element, also ist Liste bereits sortiert!
    return first;
  } else {
    // Es gibt mindestens zwei Elemente
    if (first.value < sorted(first.next).value) {
      // Erstes Element ist kleiner als groesstes Element,
      // muss also nach hinten wandern
      b = first;
      first = first.next;
      first.next = b;
      sorted(first.next);
    }
    return first;
  }
end function

program FindSecondGreatest
  // Gegeben: Liste L
  newL = L; // Kopie der Liste, die sortiert wird
  sorted(newL.first);
  secondGreatest = newL.first.next;
end program 

