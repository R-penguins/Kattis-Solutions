/**
 * @file mausa20I-2.cpp
 * @author R-penguins
 * @brief ICPC Mid-Atlantic USA 2020 I Bitonic Ordering
 * @date 2021-04-06
 * 
 * Solution with Merge-sort. O(n log n)
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

struct Num
{
  int val, lgreater = 0, rgreater = 0;
};
vector<Num> c, temp;
void merge_sort(int begin, int end)
{
  if (begin + 1 >= end)
    return;
  int mid = begin + (end - begin) / 2;
  merge_sort(begin, mid);
  merge_sort(mid, end);
  int i = begin, j = mid;
  for (int k = begin; k < end; ++k)
    if (i == mid || (j < end && c[j].val < c[i].val))
    {
      temp[k] = c[j++];
      temp[k].lgreater += mid - i;
    }
    else
    {
      temp[k] = c[i++];
      temp[k].rgreater += end - j;
    }
  copy(temp.begin() + begin, temp.begin() + end, c.begin() + begin);
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  c = vector<Num>(n);
  temp = vector<Num>(n);
  for (Num& i : c)
    cin >> i.val;
  merge_sort(0, n);
  long long ans = 0;
  for (Num& i : c)
    ans += min(i.lgreater, i.rgreater);
  cout << ans << "\n";
  return 0;
}
