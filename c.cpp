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
using LL = long long;
constexpr double pi = 3.1415926535897932385;
constexpr double EPS = 1e-12;
struct Segtree {
  Segtree(int n) : n(n), tree(2 * n){};
  void init() {
    for (int i = n - 1; i > 0; --i)
      tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  int query(int begin, int end) {
    int res = 0;
    for (begin += n, end += n; begin < end; begin /= 2, end /= 2) {
      if (begin % 2)
        res += tree[begin++];
      if (end % 2)
        res += tree[--end];
    }
    return res;
  }
  void modify(int pos, int val) {
    for (tree[pos += n] = val; pos > 1; pos /= 2)
      tree[pos / 2] = tree[pos] + tree[pos ^ 1];
  }
  vector<int> tree;
  int n;
};

/**
struct Segtree {
  Segtree(LL n)
    : n(n), d(n), height(sizeof(LL) * 8 - __builtin_clz(n)), tree(2 * n){}
  void calc(LL p, LL k) {
    if (d[p] == 0) tree[p] = tree[p<<1] + tree[p<<1|1];
    else tree[p] = d[p] * k;
  }
  void apply(LL p, LL value, LL k) {
    tree[p] = value * k; //!
    if (p < n) d[p] = value; //!
  }
  void build(LL l, LL r) {
    LL k = 2;
    for (l += n, r += n-1; l > 1; k <<= 1) {
      l >>= 1, r >>= 1;
      for (LL i = r; i >= l; --i) calc(i, k);
    }
  }
  void push(LL l, LL r) {
    LL s = height, k = 1 << (height-1);
    for (l += n, r += n-1; s > 0; --s, k >>= 1)
      for (LL i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
        apply(i<<1, d[i], k);
        apply(i<<1|1, d[i], k);
        d[i] = 0;
      }
  }
  void modify(LL l, LL r, LL value) {
    if (value == 0)
      return;
    push(l, l + 1);
    push(r - 1, r);
    bool cl = false, cr = false;
    LL k = 1;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
      if (cl) calc(l - 1, k);
      if (cr) calc(r, k);
      if (l&1) apply(l++, value, k), cl = true;
      if (r&1) apply(--r, value, k), cr = true;
    }
    for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
      if (cl) calc(l, k);
      if (cr && (!cl || l != r)) calc(r, k);
    }
  }
  LL query(LL l, LL r) {
    push(l, l + 1);
    push(r - 1, r);
    LL res = 0;
    for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
      if (l&1) res += tree[l++];
      if (r&1) res += tree[--r];
    }
    return res;
  }
  void init() {
    for (LL i = n - 1; i > 0; --i)
      tree[i] = tree[2 * i] + tree[2 * i + 1];
  }
  vector<LL> tree, d;
  LL n;
  LL height;
};
*/

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  Segtree segtree(8);
  segtree.modify(0, 2);
  segtree.modify(1, 3);
  cout << segtree.query(0, 2) << '\n';
  return 0;
}
