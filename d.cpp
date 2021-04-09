/**
 * Pixelated
 * TLE
 */
#include <bits/stdc++.h>
using namespace std;
using Pt = pair<int, int>;
struct Pulse
{
  int t, m, a;
  Pulse(int t = 0, int m = 0, int a = 0) : t(t), m(m), a(a) { }
  bool operator<(const Pulse &rhs)
  {
    return a < rhs.a;
  }
};
int main()
{
  int n;
  cin >> n;
  vector<Pulse> hs, vs;
  while (n--)
  {
    Pulse cur;
    string type;
    cin >> type;
    cin >> cur.t >> cur.m >> cur.a;
    if (type == "h")
      hs.push_back(cur);
    else
      vs.push_back(cur);
  }
  // sort(hs.begin(), hs.end());
  int ans = 0;
  int prevH = -1, c;
    // set<int> zong;
  for (const Pulse &h : hs)
  {
    // if (h.a != prevH)
      // zong = set<int>();
    prevH = h.a;
    for (const Pulse &v : vs)
    {
      int hstart = h.t + v.a, hend = h.t + v.a + h.m,
          vstart = v.t + h.a, vend = v.t + h.a + v.m;
      if (hend <= vstart || vend <= hstart)
        continue;
      // if (zong.count(v.a) == 0)
      // {
      //   ++ans;
      //   zong.insert(v.a);
      // }
    }
  }
  cout << ans << "\n";
}
