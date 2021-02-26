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

  int n, p, d;
  cin >> n >> p >> d;
  string pattern;
  cin >> pattern;
  pattern += pattern;
  int l = n - p + 1;
  int r = n;
  int sleep = count(pattern.begin() + l, pattern.begin() + r + 1, 'Z');
  int ans = (sleep < d) ? 1 : 0;
  for (int i = 0; i < n - 1; ++i)
  {
    if (pattern[l++] == 'Z')
      --sleep;
    if (pattern[++r] == 'Z')
      ++sleep;
    if (sleep < d)
      ++ans;
  }
  cout << ans << "\n";
  return 0;
}
