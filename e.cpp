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

struct Segtree_max {
  Segtree_max(int n) : n(n), tree(2 * n, INT_MIN){};
  int query(int begin, int end) {
    int res = INT_MIN;
    for (begin += n, end += n; begin < end; begin /= 2, end /= 2) {
      if (begin % 2)
        res = max(res, tree[begin++]);
      if (end % 2)
        res = max(res, tree[--end]);
    }
    return res;
  }
  void modify(int pos, int val) {
    for (tree[pos += n] = val; pos > 1; pos /= 2)
      tree[pos / 2] = max(tree[pos], tree[pos ^ 1]);
  }
  vector<int> tree;
  int n;
};

struct Segtree_min {
  Segtree_min(int n) : n(n), tree(2 * n, INT_MAX){};
  int query(int begin, int end) {
    int res = INT_MAX;
    for (begin += n, end += n; begin < end; begin /= 2, end /= 2) {
      if (begin % 2)
        res = min(res, tree[begin++]);
      if (end % 2)
        res = min(res, tree[--end]);
    }
    return res;
  }
  void modify(int pos, int val) {
    for (tree[pos += n] = val; pos > 1; pos /= 2)
      tree[pos / 2] = min(tree[pos], tree[pos ^ 1]);
  }
  vector<int> tree;
  int n;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  VI v(N);
  vector<PII> sorted(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i];
    sorted[i] = {v[i], i};
  }
  sort(sorted.rbegin(), sorted.rend());
  Segtree_max left_max(N);
  Segtree_min right_min(N);
  VI ans(N, INT_MAX);
  for (int i = 0; i < N; ++i) {
    VI temp;
    auto& [val, ind] = sorted[i];
    int lmax = left_max.query(0, ind), rmin = right_min.query(ind, N);
    if (lmax >= 0)
      ans[ind] = min(ans[ind], ind - lmax);
    if (rmin < INT_MAX)
      ans[ind] = min(ans[ind], rmin - ind);
    temp.push_back(ind);
    while (i + 1 < N && sorted[i+1].first == val) {
      ++i;
      auto& [val, ind] = sorted[i];
      lmax = left_max.query(0, ind), rmin = right_min.query(ind, N);
      if (lmax >= 0)
        ans[ind] = min(ans[ind], ind - lmax);
      if (rmin < INT_MAX)
        ans[ind] = min(ans[ind], rmin - ind);
      temp.push_back(ind);
    }
    for (int ind : temp) {
      left_max.modify(ind, ind);
      right_min.modify(ind, ind);
    }
  }
  for (int& i : ans)
    if (i == INT_MAX)
      i = -1;
  int M = max(*max_element(ans.begin(), ans.end()), 0);
  for (int& i : ans)
    if (i == -1)
      i = M + 1;

  cout << M << '\n';
  for (int i = 1; i <= M + 1; ++i) {
    for (int ind = 0; ind < N; ++ind)
      if (ans[ind] == i)
        cout << v[ind] << ' ';
    cout << '\n';
  }
  return 0;
}
