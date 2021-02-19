#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int W, P;
  cin >> W >> P;
  vector<int> L {0};
  for (int i = 0; i < P; ++i)
  {
    int t;
    cin >> t;
    L.push_back(t);
  }
  L.push_back(W);
  set<int> ans;
  for (int i = 0; i < P + 1; ++i)
    for (int j = i + 1; j < P + 2; ++j)
      ans.insert(L[j] - L[i]);
  for (int i : ans)
    cout << i << " ";
  cout << "\n";
  return 0;
}
