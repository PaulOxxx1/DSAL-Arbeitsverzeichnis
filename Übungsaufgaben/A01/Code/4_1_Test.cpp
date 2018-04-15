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
  int n;

  list(): first(0), last(0), n(0) {}
  
  void addElement(element* e) {
    n++;
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

int main() {
  // erstelle hier eine beliebige Liste
  list L;
  L.addElement(new element(1));
  L.addElement(new element(2));
  L.addElement(new element(3));
  cout << L;
  
  // Start des Algorithmus
  int n = L.n;
  for (int m=n;m>1;m--) {
    for (int i=0;i<m-1;i=i+1) {
      element* a = L.first;
      for (int j=0;j<i;j++) a = a->next;
      if (a->value < a->next->value) {
        // Elemente vertauschen
        int c = a->value;
        a->value = a->next->value;
        a->next->value = c;
      }
    }
  }
  element* secondGreatest = L.first->next;

  // Ausgabe des Ergebnisses
  cout << L;
  cout << *secondGreatest;
  return 0;
}