/// ICPC RMC 2020 H Antimatter Rain
/// data structures, implementation
/// RMQ, segment tree, discretization
/// 0.68s
#include <bits/stdc++.h>
using namespace std;
using VI = vector<int>;

struct Obj
{
  int y = INT_MAX, x1, x2 = -1;
};

vector<Obj> objs;

auto cmp = [](int l, int r){ return objs[l].y < objs[r].y; };

struct Segtree {
  Segtree(int n) : n(n), tree(2 * n){};
  int query(int begin, int end) {
    int res = 0;
    for (begin += n, end += n; begin < end; begin /= 2, end /= 2) {
      if (begin % 2)
        res = min(res, tree[begin++], cmp);
      if (end % 2)
        res = min(res, tree[--end], cmp);
    }
    return res;
  }
  void modify(int pos, int val) {
    for (tree[pos += n] = val; pos > 1; pos /= 2)
      tree[pos / 2] = min(tree[pos], tree[pos ^ 1], cmp);
  }
  vector<int> tree;
  int n;
};

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int D, S;
  cin >> D >> S;
  objs.resize(D + S + 1);
  set<int> xs;
  for (int i = 1; i <= D; ++i) {
    cin >> objs[i].x1 >> objs[i].y;
    xs.insert(objs[i].x1);
  }
  for (int i = D + 1; i <= D + S; ++i) {
    cin >> objs[i].x1 >> objs[i].x2 >> objs[i].y;
    xs.insert(objs[i].x1);
    xs.insert(objs[i].x2);
  }
  map<int, int> x_pt;
  int pt_cnt = 0;
  for (int x : xs)
    x_pt[x] = pt_cnt++;
  vector<stack<int>> stk(pt_cnt);
  for (auto& s : stk)
    s.emplace(); // sentinal
  VI del(D);
  Segtree segtree(pt_cnt);
  VI y_ordered_ind(D + S);
  iota(y_ordered_ind.begin(), y_ordered_ind.end(), 1);
  sort(y_ordered_ind.rbegin(), y_ordered_ind.rend(), cmp);
  for (int i : y_ordered_ind) {
    Obj& obj = objs[i];
    if (obj.x2 == -1) { // droplet
      int pt = x_pt[obj.x1];
      stk[pt].push(i);
      segtree.modify(pt, i);
    } else { // sensor
      int ptl = x_pt[obj.x1], ptr = x_pt[obj.x2];
      int hit = segtree.query(ptl, ptr + 1);
      int hity = objs[hit].y;
      while (hity < INT_MAX && objs[hit].y == hity) {
        del[hit - 1] = obj.y;
        int hitx_pt = x_pt[objs[hit].x1];
        stk[hitx_pt].pop();
        segtree.modify(hitx_pt, stk[hitx_pt].top());
        hit = segtree.query(ptl, ptr + 1);
      }
    }
  }
  for (int y : del)
    cout << y << '\n';

  return 0;
}
