/// Benelux Algorithm Programming Contest (BAPC) preliminaries 2016 G Millionaire Madness
/// 0.19s
/// Dijkstra's
#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;

constexpr int dist(int a, int b)
{
  return (b < a) ? 0 : b - a;
}
struct Pt {
  int x, y;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int M, N;
  cin >> M >> N;
  VVI vault(M, VI(N));
  for (VI& row : vault)
    for (int& i : row)
      cin >> i;
  using Data = pair<int, Pt>;
  auto cmp = [](Data& a, Data& b) { return a.first > b.first; };
  priority_queue<Data, vector<Data>, decltype(cmp)> q(cmp);
  VVI ans(M, VI(N, INT_MAX));
  ans[0][0] = 0;
  q.emplace(0, Pt { 0, 0 });
  const array<Pt, 4> dirs { Pt { -1, 0 }, Pt { 1, 0 }, Pt { 0, -1 }, Pt { 0, 1 } };
  while (!q.empty()) {
    auto [weight, pt] = q.top();
    q.pop();
    if (ans[pt.x][pt.y] != weight)
      continue;
    if (pt.x == M - 1 && pt.y == N - 1)
      break;

    for (auto& dir : dirs) {
      Pt newpt { pt.x + dir.x, pt.y + dir.y };
      if (!(0 <= newpt.x && newpt.x < M && 0 <= newpt.y && newpt.y < N))
        continue;
      int newval = max(ans[pt.x][pt.y], dist(vault[pt.x][pt.y], vault[newpt.x][newpt.y]));
      if (newval < ans[newpt.x][newpt.y])
        q.emplace(ans[newpt.x][newpt.y] = newval, newpt);
    }
  }
  cout << ans[M - 1][N - 1] << '\n';

  return 0;
}
