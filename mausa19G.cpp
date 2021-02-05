/**
 * Flickering Colors
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n>> m;
  vector<vector<int>> g(n, vector<int>());
  while (m--)
  {
    int a, b;
    cin >> a >> b;
    --a; --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  vector<bool> vis(n, false);
  vector<int> lev(n, 0);
  queue<int> q;
  q.push(0);
  vis[0] = true;
  bool ok = false;
  while (!q.empty() && !ok)
  {
    int cur = q.front();
    q.pop();
    for (int next : g[cur])
      if (!vis[next])
      {
        lev[next] = lev[cur] + 1;
        vis[next] = true;
        q.push(next);
        if (next == n - 1)
        {
          ok = true;
          break;
        }
      }
  }
  cout << lev[n - 1] - 1 << "\n";
}
