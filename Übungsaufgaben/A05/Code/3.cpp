#import<iostream>
#import<fstream>
#import<vector>

using namespace std;

// Ausgabe von Listen
ostream& operator<<(ostream& o, vector<int>& L) {
  o << "[";
  for (int i=0;i<L.size();i++) {
    o << L[i];
    if (i<L.size()-1) {
      o << ", ";
    } 
  }
  o << "]";
  return o;
}

// Tail von Listen
vector<int> tail(vector<int> L) {
  vector<int>::iterator it = L.begin();
  L.erase(it);
  return L;
}

int S(vector<int> L, int a, int b, int c) {
  cout << "S: " << L << " [" << a << ", " << b << ", " << c << "]" << endl;
  if (L.size() == 0) {
    return b;
  }
  if (L[0]>c) {
    return S(tail(L),a+1,a,L[0]);
  } else {
    return S(tail(L),a+1,b,c);
  }
}

vector<int> T(vector<int> L) {
  if (L.size() == 1) return L;
  cout << "T: " << L << endl;
  int i = S(L,0,0,-1);
  
  // Swap
  cout << "Swap: i=" << i << endl;
  int temp = L[0];
  L[0] = L[i];
  L[i] = temp;
  
  vector<int> A = T(tail(L));
  vector<int>::iterator it = A.begin();
  A.insert(it,L[0]);
  return A;
}

int main(int argc, char const *argv[]) {
  vector<int> L;
  L.push_back(3);
  L.push_back(1);
  L.push_back(2);
  L.push_back(4);
  L.push_back(5);
  L.push_back(6);
  
  vector<int> A = T(L);
  cout << "Ausgabe: " << A << endl;

  return 0;
}