#include <bits/stdc++.h>
using namespace std;
using VD = vector<double>;
using VVD = vector<VD>;
using VI = vector<int>;
using VII = vector<VI>;
constexpr double EPS = 1e-9;

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, d;
  cin >> n >> d;
  VI a(n);
  for (int& i : a)
  {
    cin >> i;
    i /= d;
  }
  sort(a.begin(), a.end());
  long long ans = 0, cnt = 0;
  int prev = -1;
  for (int i : a)
  {
    if (i == prev)
      ++cnt;
    else
    {
      if (cnt)
        ans += cnt * (cnt - 1) / 2;
      prev = i;
      cnt = 1;
    }
  }
  if (cnt)
    ans += cnt * (cnt - 1) / 2;
  cout << ans << "\n";
  return 0;
}
