#include <bits/stdc++.h>
using namespace std;
using VD = vector<double>;
using VVD = vector<VD>;
using VI = vector<int>;
using VVI = vector<VI>;
using VS = vector<string>;
using VVS = vector<VS>;
constexpr double EPS = 1e-9;

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  VVS ori_list(n);
  for (int i = 0; i < n; ++i)
  {
    int q;
    cin >> q;
    ori_list[i] = VS(q);
    for (string& str : ori_list[i])
      cin >> str;
  }
  int p;
  cin >> p;
  VS names(p);
  for (string& str : names)
    cin >> str;
  map<string, int> ranks;
  for (int i = 0; i < p; ++i)
    ranks[names[i]] = i;
  VVI pref(n);
  for (int i = 0; i < n; ++i)
  {
    VI& team_pref = pref[i];
    team_pref = VI(ori_list[i].size());
    for (int j = 0; j < team_pref.size(); ++j)
      team_pref[j] = ranks[ori_list[i][j]];
  }

  VVI players(n, VI(k));
  VI pref_ptr(n); // can use a queue instead
  vector<bool> selected(p);
  int availble = 0;
  for (int round = 0; round < k; ++round)
    for (int team = 0; team < n; ++team)
    {
      while (pref_ptr[team] < pref[team].size() && selected[pref[team][pref_ptr[team]]])
        ++pref_ptr[team];
      int player;
      if (pref_ptr[team] < pref[team].size())
      {
        player = pref[team][pref_ptr[team]];
        ++pref_ptr[team];
      }
      else
      {
        while (selected[availble])
          ++availble;
        player = availble;
      }
      players[team][round] = player;
      selected[player] = true;
    }

  for (auto& team : players)
  {
    for (int i : team)
      cout << names[i] << " ";
    cout << "\n";
  }
  return 0;
}
