#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;
using VB = vector<bool>;
using VVB = vector<VB>;
using PII = pair<int, int>;
using PDD = pair<double, double>;
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;

struct Pt
{
  int r, c;
  Pt(int r, int c) : r(r), c(c) {}
};
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  vector<vector<Pt>> pts(k);
  for (int r = 0; r < n; ++r)
    for (int c = 0; c < n; ++c) {
      int x;
      cin >> x;
      pts[x - 1].emplace_back(r, c);
    }
  if (pts[0].empty()) {
    cout << "-1\n";
    return 0;
  }
  VI ans(pts[0].size(), 0);
  for (int cur_k = 1; cur_k < k; ++cur_k) {
    if (pts[cur_k].empty()) {
      cout << "-1\n";
      return 0;
    }
    VI val(pts[cur_k].size(), INT_MAX);
    for (int ki = 0; ki < pts[cur_k].size(); ++ki)
      for (int pki = 0; pki < ans.size(); ++pki)
        val[ki] = min(val[ki], ans[pki] + abs(pts[cur_k][ki].r - pts[cur_k - 1][pki].r) + abs(pts[cur_k][ki].c - pts[cur_k - 1][pki].c));
    ans = val;
  }
  cout << *min_element(ans.begin(), ans.end()) << '\n';
  return 0;
}
