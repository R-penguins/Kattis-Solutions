/// ICPC SWERC 2009 B Working at the restaurant
/// 0.01s
/// stack, queue
#include "bits/stdc++.h"
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  bool first = true;
  while (cin >> N && N) {
    if (first)
      first = false;
    else
      cout << '\n';
    int pile1 = 0, pile2 = 0;
    while (N--) {
      string cmd;
      int m;
      cin >> cmd >> m;
      if (cmd[0] == 'D') { // DROP
        cout << "DROP 2 " << m << '\n';
        pile2 += m;
      } else { // TAKE
        int taken = min(m, pile1);
        if (taken) {
          cout << "TAKE 1 " << taken << '\n';
          pile1 -= taken;
          m -= taken;
        }
        if (m) {
          cout << "MOVE 2->1 " << pile2 << '\n';
          cout << "TAKE 1 " << m << '\n';
          pile1 += pile2 - m;
          pile2 = 0;
        }
      }
    }
  }
  return 0;
}
