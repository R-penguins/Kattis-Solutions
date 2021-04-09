/**
 * @file mausa20I.cpp
 * @author R-penguins
 * @brief ICPC Mid-Atlantic USA 2020 I Bitonic Ordering
 * @date 2021-04-03
 * 
 * Solution with Binary Indexed Tree. O(n log n)
 */
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
using PDI = pair<double, int>;
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;

struct Bit
{
  Bit(int size) : tree(size + 1) { }
  Bit(vector<int>& arr) : tree(arr)
  {
    for (int i = 1; i < tree.size(); ++i)
    {
      int p = i + (i & -i);
      if (p < tree.size())
        tree[p] += tree[i];
    }
  }
  int sum(int ind)
  {
    int ans = 0;
    while (ind)
    {
      ans += tree[ind];
      ind -= (ind & -ind);
    }
    return ans;
  }
  void add(int ind, int val)
  {
    while (ind < tree.size())
    {
      tree[ind] += val;
      ind += (ind & -ind);
    }
  }
  vector<int> tree;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<PII> c_index(n);
  for (int i = 1; i < n + 1; ++i)
  {
    int c;
    cin >> c;
    c_index[i - 1] = {c, i};
  }
  sort(c_index.rbegin(), c_index.rend());
  Bit bit(c_index.size());
  long long ans = 0;
  for (int i = 0; i < n; ++i)
  {
    int index = c_index[i].second;
    long long left_greater = bit.sum(index - 1);
    ans += min(left_greater, i - left_greater);
    bit.add(index, 1);
  }
  cout << ans << "\n";
  return 0;
}
