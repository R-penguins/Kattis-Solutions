/// ICPC RMC 2020 G Distance
/// math
/// prefix sum
/// 0.06s
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VLL = vector<LL>;
using VVLL = vector<VLL>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  VVLL xs(2, VLL(N));
  for (int i = 0; i < N; ++i)
    cin >> xs[0][i] >> xs[1][i];
  LL ans = 0;
  for (VLL& x : xs) {
    sort(x.begin(), x.end());
    for (int i = 0; i < N; ++i)
      ans += i * x[i] - (N - i - 1) * x[i];
  }
  cout << ans << '\n';

  return 0;
}
