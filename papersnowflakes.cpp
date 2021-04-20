/// ICPC RMC 2020 C Paper Snowflakes
/// discreatlize
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

  LL N, M, L;
  cin >> N >> M >> L;
  vector<PLL> pos;
  pos.reserve(N + M + 2);
  pos.emplace_back(0, 1);
  LL prev = L;
  for (int i = 0; i < N; ++i) {
    LL f;
    cin >> f;
    LL crease = prev + (i % 2 ? f : -f);
    pos.emplace_back(crease, (i % 2 ? 2 : -2));
    prev = crease + (i % 2 ? f : -f);
  }
  pos.emplace_back(prev, (N % 2 ? 1 : -1));
  for (int i = 0; i < M; ++i) {
    LL x;
    cin >> x;
    pos.emplace_back(x, 0);
  }
  sort(pos.begin(), pos.end());
  LL layers = 0, curlen = 0;
  prev = LONG_LONG_MIN;
  for (auto& [loc, num] : pos) {
    curlen += layers * (loc - prev);
    if (num == 0) {
      cout << curlen << ' ';
      curlen = 0;
    } else
      layers += num;
    prev = loc;
  }
  cout << curlen << '\n';
  return 0;
}
