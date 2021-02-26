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

  int n, h, v;
  cin >> n >> h >> v;
  int h2 = n - h, v2 = n - v;
  cout << (int) max(h, h2) * (int) max(v, v2) * 4 << "\n";
  return 0;
}
