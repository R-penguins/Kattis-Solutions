/// ICPC RMC 2020 E Interview Queue
/// linked list
#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;
using VVI = vector<VI>;
using VB = vector<bool>;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  list<int> q;
  VI v(N), lookat(N);
  VB alive(N, true);
  vector<list<int>::iterator> q_iter(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
    lookat[i] = i;
    q.push_back(i);
    q_iter[i] = prev(q.end());
  }

  VVI ans;
  while (!q.empty()) {
    VI del;
    set<int> next_lookat;
    for (int pos : lookat) {
      auto iter = q_iter[pos];
      if ((iter != q.begin() && v[*prev(iter)] > v[*iter]) || (next(iter) != q.end() && v[*next(iter)] > v[*iter])) {
        del.push_back(pos);
        alive[pos] = false;
        if (iter != q.begin())
          next_lookat.insert(*prev(iter));
        if (next(iter) != q.end())
          next_lookat.insert(*next(iter));
      }
    }

    if (del.empty())
      break;
    ans.emplace_back();
    for (int pos : del) {
      ans.back().push_back(v[pos]);
      q.erase(q_iter[pos]);
    }
    lookat.clear();
    copy_if(next_lookat.begin(), next_lookat.end(), back_inserter(lookat), [&](int pos) { return alive[pos]; });
  }

  cout << ans.size() << '\n';
  for (VI& row : ans) {
    for (int i : row)
      cout << i << ' ';
    cout << '\n';
  }
  for (int i : q)
    cout << v[i] << ' ';
  cout << '\n';

  return 0;
}
