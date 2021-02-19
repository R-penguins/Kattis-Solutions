#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  list<pair<int, int>> k;
  for (int i = 0; i < n; ++i)
  {
    int x;
    cin >> x;
    k.push_back({i, x});
  }
  int prev = 0;
  for (int i = 0; i < n - 1; ++i)
  {
    auto iter = k.begin();
    advance(iter, prev % k.size());
    int step = ((iter->second + prev) % k.size() + k.size() - 1) % k.size();
    auto iter2 = k.begin();
    advance(iter2, step);
    prev = distance(k.begin(), iter2);
    k.erase(iter2);
  }
  cout << k.front().first + 1 << "\n";
  return 0;
}
