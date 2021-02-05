#include <bits/stdc++.h>
using namespace std;
int main()
{
  long long n;
  cin >> n;
  long long w = 2 * ceil(sqrt((long double)n / 2));
  long long h = ceil((long double)n / w);
  long long ans = numeric_limits<long long>::max();
  while (h <= w * 2)
  {
    if (w <= h * 2)
    {
      ans = min(ans, w * h - n);
      if (ans == 0)
        break;
    }
    if (w == 0)
      break;
    --w;
    h = ceil((double)n / w);
  }
  cout << ans << "\n";
}

