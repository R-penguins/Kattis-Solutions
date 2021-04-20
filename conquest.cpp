/// conquest
/// ICPC RMC 2020 F
/// graphs, shortest paths
/// Dijkstra's
#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

struct Edge {
  int index, val;
  Edge(int ind, int val) : index(ind), val(val){}
};
int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N, M;
  cin >> N >> M;
  VVI adj(N);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    --u;
    --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  VI s(N);
  for (int& i : s)
    cin >> i;
  int army = s[0];
  auto cmp = [](Edge& a, Edge& b) { return a.val > b.val; };
  priority_queue<Edge, vector<Edge>, decltype(cmp)> q(cmp);
  VB vis(N);
  vis[0] = true;
  for (int i : adj[0]) {
    vis[i] = true;
    q.push(Edge(i, s[i]));
  }
  while (!q.empty()) {
    Edge cur = q.top();
    if (cur.val >= army)
      break;
    q.pop();
    army += cur.val;
    for (int i : adj[cur.index])
      if (!vis[i]) {
        q.push(Edge(i, s[i]));
        vis[i] = true;
      }
  }
  cout << army << '\n';
  return 0;
}
