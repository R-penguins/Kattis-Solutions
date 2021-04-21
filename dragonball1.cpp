#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using VI = vector<int>;
using VVI = vector<VI>;
using VD = vector<double>;
using VVD = vector<VD>;
using VS = vector<string>;
using VVS = vector<VS>;
using VB = vector<bool>;
using VVB = vector<VB>;
using PII = pair<int, int>;
using PLL = pair<LL, LL>;
using PDD = pair<double, double>;
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;

struct Edge {
  Edge(int to, int t) : to(to), t(t) {}
  int to, t;
};
void dijkstra(vector<vector<Edge>>& adj, int s, /* int t, */ vector<double>& dist)
{
  dist.assign(adj.size(), INFINITY);
  dist[s] = 0;
  priority_queue<PII, vector<PII>, greater<PII>> q; // weight, vertex
  q.emplace(0, s);
  while (!q.empty())
  {
    PII cur = q.top();
    q.pop();
    // if (cur.second == t)
    //   break;
    if (dist[cur.second] != cur.first)
      continue;
    for (Edge& edge : adj[cur.second])
      if (cur.first + edge.t < dist[edge.to])
      {
        dist[edge.to] = cur.first + edge.t;
        q.emplace(dist[edge.to], edge.to);
      }
  }
}

int balls_cnt;
VI vis;
VVD dist;
double check(int x) {
  if (all_of(vis.begin(), vis.end(), [](int i){ return i; }))
    return 0;
  double cur_min = INFINITY;
  for (int i = 0; i < balls_cnt; ++i)
    if (!vis[i] && dist[x][i] < INFINITY) {
      vis[i] = true;
      cur_min = min(cur_min, dist[x][i] + check(i));
      vis[i] = false;
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
  // for (vector<Edge>& city : cities)
  //   city.reserve(n);
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
  VD cur_dist(n);
  for (int i = 0; i < balls_cnt; ++i) {
    int s = balls[i];
    dijkstra(cities, s, cur_dist);
    for (int j = i + 1; j < balls_cnt; ++j) {
      dist[i][j] = cur_dist[balls[j]];
      dist[j][i] = cur_dist[balls[j]];
    }
  }
  vis.assign(balls_cnt, false);
  double ans = check(0);
  if (ans < INFINITY)
    cout << ans << '\n';
  else
    cout << "-1\n";

  return 0;
}
