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

  string p, s;
  cin >> s >> p;
  bool ok;
  if (p.size() == s.size()) {
    if (p == s) {
      cout << "Yes\n";
      return 0;
    }
    for (char& c : p)
      if (isupper(c))
        c = tolower(c);
      else if (islower(c))
        c = toupper(c);
    if (p == s) {
      cout << "Yes\n";
      return 0;
    }
  } else if (s.size() == p.size() + 1 &&
    (isdigit(s[0]) && equal(p.begin(), p.end(), s.begin() + 1) ||
    isdigit(s.back()) && equal(p.begin(), p.end(), s.begin()))) {
    cout << "Yes\n";
    return 0;
  }
  cout << "No\n";
  return 0;
}
