#include <bits/stdc++.h>
using namespace std;
using VD = vector<double>;
using VVD = vector<VD>;
using VI = vector<int>;
using VII = vector<VI>;
using PII = pair<int, int>;
constexpr double EPS = 1e-9;

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<PII> line;
  for (int i = 2; i <= n; ++i)
  {
    int cur;
    cin >> cur;
    line.push_back({cur, i});
  }
  sort(line.begin(), line.end());
  cout << "1";
  for (auto i : line)
    cout << " " << i.second;
  cout << "\n";
  return 0;
}
