#include <bits/stdc++.h>
using namespace std;

bool bs(vector<long long>::iterator beg, vector<long long>::iterator end, long long val)
{
  if (beg == end)
    return false;
  int count = (distance(beg, end) - 1) / 2;
  auto iter = beg + count;
  if (*iter == val)
    return true;
  else if (val > *iter)
    return bs(iter + 1, end, val);
  else
    return bs(beg, iter, val);
}

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n, m, a, c, x0;
  cin >> n >> m >> a >> c >> x0;
  vector<long long> x(n);
  c %= m;
  x[0] = ((a * x0) % m + c) % m;
  for (int i = 1; i < n; ++i)
    x[i] = ((a * x[i - 1]) % m + c) % m;
  int ans = 0;
  for (long long i : x)
    if (bs(x.begin(), x.end(), i))
      ++ans;
  cout << ans << "\n";
  return 0;
}
