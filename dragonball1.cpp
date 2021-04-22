/// ICPC Mid-Central USA 2019 F Dragon Ball 1
/// graphs, shortest paths
/// Dijkstra's, enumeration
/// 0.30s
#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
using VI = vector<int>;
using VD = vector<double>;
using VVD = vector<VD>;
using PII = pair<int, int>;

struct Edge {
  Edge(int to, int t)
      : to(to)
      , t(t)
  {
  }
  int to, t;
};

void dijkstra(vector<vector<Edge>>& adj, int s, /* int t, */ vector<double>& dist)
{
  dist.assign(adj.size(), INFINITY);
  dist[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q; // weight, vertex
  q.emplace(0, s);
  while (!q.empty()) {
    PII cur = q.top();
    q.pop();
    // if (cur.second == t)
    //   break;
    if (dist[cur.second] != cur.first)
      continue;
    for (Edge& edge : adj[cur.second])
      if (cur.first + edge.t < dist[edge.to]) {
        dist[edge.to] = cur.first + edge.t;
        q.emplace(dist[edge.to], edge.to);
      }
  }
}

int balls_cnt;
bitset<8> vis;
VVD dist;
double check(int x)
{
  if (vis.all())
    return 0;
  double cur_min = INFINITY;
  for (int i = 1; i < balls_cnt; ++i)
    if (!vis[i] && dist[x][i] < INFINITY) {
      vis.set(i);
      cur_min = min(cur_min, dist[x][i] + check(i));
      vis.reset(i);
    }
  return cur_min;
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<vector<Edge>> cities(n);
  for (int i = 0; i < m; ++i) {
    int a, b, t;
    cin >> a >> b >> t;
    if (a == b)
      continue;
    --a;
    --b;
    cities[a].emplace_back(b, t);
    cities[b].emplace_back(a, t);
  }
  VI balls(7);
  for (int& i : balls) {
    cin >> i;
    --i;
  }
  balls.push_back(0);
  sort(balls.begin(), balls.end());
  balls.erase(unique(balls.begin(), balls.end()), balls.end());
  balls_cnt = balls.size();
  dist.assign(balls_cnt, VD(balls_cnt));
  VD cur_dist;
  for (int i = 0; i < balls_cnt; ++i) {
    int s = balls[i];
    dijkstra(cities, s, cur_dist);
    for (int j = i + 1; j < balls_cnt; ++j) {
      dist[i][j] = cur_dist[balls[j]];
      dist[j][i] = cur_dist[balls[j]];
    }
  }
  vis = (0b11111111 << balls_cnt);
  vis.set(0);
  double ans = check(0);
  cout << (ans < INFINITY ? ((LL)ans) : -1) << '\n';

  return 0;
}
