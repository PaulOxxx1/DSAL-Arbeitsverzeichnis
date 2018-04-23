int allTrue(bool [] E) {
  if (E.length < 1) {
    return -1;
  }
  int m = E.length;
  int i = 0;
  while (i<E.length) {
    if (E[i] == true) {
      m = m - 1;
      if (m == 0) {
        return 1;
      }
    }
    i = i + 1;
  }
  return 0;
}