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
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;

int n, k; 
VS grid;
VI ship;
int ans = 0;
void check(int s) {
  if (s == k) {
    // Final check
    if (all_of(grid.begin(), grid.end(), [](string& row){ return row.find('O') == string::npos;}))
      ++ans;
    return;
  }
  // horizontal
  for (int r = 0; r < n; ++r)
    for (int c = 0; c <= n - ship[s]; ++c)
      if (all_of(grid[r].begin() + c, grid[r].begin() + c + ship[s], [](char i){return i == '.' || i == 'O';})) {
        for (int cc = c; cc < c + ship[s]; ++cc)
          ++grid[r][cc];
        // for_each(grid[r].begin() + c, grid[r].begin() + c + ship[s], [](char& i){ ++i;});
        check(s + 1);
        for (int cc = c; cc < c + ship[s]; ++cc)
          --grid[r][cc];
        // for_each(grid[r].begin() + c, grid[r].begin() + c + ship[s], [](char& i){ --i;});
      }
  if (ship[s] > 1) {
    // vertical
    for (int r = 0; r <= n - ship[s]; ++r)
      for (int c = 0; c < n; ++c) {
        bool ok = true;
        for (int rr = r; rr < r + ship[s]; ++rr)
          if (grid[rr][c] != '.' && grid[rr][c] != 'O') {
            ok = false;
            break;
          }
        if (ok) {
          for (int rr = r; rr < r + ship[s]; ++rr)
            ++grid[rr][c];
          check(s + 1);
          for (int rr = r; rr < r + ship[s]; ++rr)
            --grid[rr][c];
        }
      }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> k;
  grid = VS(n);
  for (string& s : grid)
    cin >> s;
  ship = VI(k);
  for (int& i : ship)
    cin >> i;
  sort(ship.rbegin(), ship.rend());
  check(0);
  cout << ans << '\n';
  return 0;
}
