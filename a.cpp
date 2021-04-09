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

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  if (N % 2)
  {
    cout << "still running\n";
    return 0;
  }
  int timer = 0;
  for (int i = 0; i < N / 2; ++i)
  {
    int a, b;
    cin >> a >> b;
    timer += b - a;
  }
  cout << timer << '\n';
  return 0;
}
