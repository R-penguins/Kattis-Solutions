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
  Segtree_max(int n) : n(n), tree(2 * n){};
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

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  VI v(N);
  for (int& i : v)
    cin >> i;
  return 0;
}
