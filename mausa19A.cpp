/**
 * Kafkaesque
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int k;
  cin >> k;
  int ans = 1, prev = 0;
  while (k--)
  {
    int i;
    cin >> i;
    if (i < prev)
    {
      ++ans;
    }
    prev = i;
  }
  cout << ans << "\n";
}
