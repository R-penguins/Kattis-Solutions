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

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string line;
  cin >> line;
  VI score(2);
  for (int i = 0; i < line.size(); i += 2)
    score[line[i] - 'A'] += line[i + 1] - '0';
  cout << (score[0] > score[1] ? "A\n" : "B\n");
  return 0;
}
