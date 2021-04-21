#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;
using VB = vector<bool>;
using VVB = vector<VB>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using PDD = pair<double, double>;
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string word;
  char cur = 0;
  int cnt = 0;
  while (cin >> word)
    if (all_of(word.begin(), word.end(), [](char c){ return c == 'u' || c == 'm' || !isalnum(c); }))
      for (char c : word)
        if (c == 'u' || c == 'm') {
          cur <<= 1;
          cur += (c == 'u' ? 1 : 0);
          if (++cnt % 7 == 0) {
            cout << cur;
            cur = 0;
          }
      }
  return 0;
}
