/**
 * The Deal of the Day
 */
#include <bits/stdc++.h>
using namespace std;
const long long BOND = 1000000000000;
struct Big
{
  long long high, low;
  Big(long long high = 0, long long low = 0) : high(high), low(low) { }
  Big operator+(const Big &rhs)
  {
    long long temp = low + rhs.low;
    return Big(high + rhs.high + temp / BOND, temp % BOND);
  }
};
Big operator*(const Big &lhs, const Big &rhs)
{
  long long temp = rhs.low * lhs.low;
  return Big(lhs.low * rhs.high + (lhs.low * rhs.low / BOND), (lhs.low * rhs.low) % BOND);
}
int k;
vector<Big> nums;
Big f(int pos, int n)
{
  if (nums.size() - pos < n)
    return Big(0, 0);
  if (n == 1)
  {
    Big t =  accumulate(nums.begin() + pos, nums.end(), Big(0, 0));
    return t;
  }
  Big ans = f(pos + 1, n) + nums[pos] * f(pos + 1, n - 1);
  return f(pos + 1, n) + nums[pos] * f(pos + 1, n - 1);
}
int main()
{
  for (int i = 0; i <10; ++i)
  {
    int cur;
    cin >> cur;
    if (cur)
      nums.push_back(Big(0, cur));
  }
  cin >> k;
  Big ans = f(0, k);
  if (ans.high)
  {
    cout << ans.high;
    cout << setfill('0') << setw(12) << ans.low << "\n";
  }
  else 
    cout << ans.low << "\n";
}
