for (int i=0; i<list.size-1; i++) {
  for (int j=i+1; j<list.size; j++) {
    if (list[i] == list[j]) return true;
  }
} 
return false;