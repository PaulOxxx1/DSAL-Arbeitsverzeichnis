#include<iostream>
using namespace std;

struct element {
  element* prev;
  element* next;
  int value;
  
  element(int value): value(value), prev(0), next(0) {}
  
  friend ostream& operator<<(ostream& s, const element& e) {
    s << e.value;
    return s;
  }
};

struct list {
  element* first;
  element* last;

  list(): first(0), last(0) {}
  
  void addElement(element* e) {
    if (last) {
      last->next = e;
      e->prev = last;
      last = e;
    } else {
      first = e;
      last = e;
    }
  }
  
  friend ostream& operator<<(ostream& s, const list& l) {
    element* p = l.first;
    while (p) {
      s << *p << " ";
      p = p->next;
    }
    s << endl;
    return s;
  }
};

element* sorted(element* first) {
  if (first->next == 0) {
    // Nur ein Element, also ist Liste bereits sortiert!
    return first;
  } else {
    // Es gibt mindestens zwei Elemente
    if (first->value < sorted(first->next)->value) {
      // Erstes Element ist kleiner als größtes Element, muss also nach hinten wandern
      int c = first->value;
      first->value = first->next->value;
      first->next->value = c;
      sorted(first->next);
    }
    return first;
  }
}

int main() {
  // erstelle hier eine beliebige Liste
  list L;
  L.addElement(new element(1));
  L.addElement(new element(2));
  L.addElement(new element(3));
  cout << L;
  
  // Start des Algorithmus
  sorted(L.first);
  element* secondGreatest = L.first->next;  
  
  // Ausgabe des Ergebnisses
  cout << L;
  cout << *secondGreatest;
  return 0;
}