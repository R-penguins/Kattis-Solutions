#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  string line;
  map<string, set<string>> cores;
  while (getline(cin, line) && line != "***")
  {
    stringstream ss(line);
    string word;
    while (ss >> word)
    {
      string core = "";
      for (char c : word)
        if (isalpha(c))
          core += tolower(c);
      if (core == "")
        continue;
      if (cores.count(core) == 0)
      {
        set<string> cur;
        for (auto &s : cores)
        {
          const string &str = s.first;
          if (abs((int)str.size() - (int)core.size()) > 1)
            continue;
          int i = 0;
          while (i < str.size() && i < core.size() && str[i] == core[i])
            ++i;
          if (equal(core.begin() + i, core.end(), str.begin() + i + 1) && (int)str.size() - (int)core.size() == 1 ||
              equal(core.begin() + i + 1, core.end(), str.begin() + i)  && (int)core.size() - (int)str.size() == 1 ||
              equal(core.begin() + i + 1, core.end(), str.begin() + i + 1) && core.size() == str.size() ||
              (str.size() > i + 1 && core.size() > i + 1 && str[i] == core[i + 1] && core[i] == str[i + 1] && equal(core.begin() + i + 2, core.end(), str.begin() + i + 2) && core.size() == str.size()))
          {
            s.second.insert(core);
            cur.insert(str);
          }
        }
        cores[core] = cur;
      }
    }
  }
  bool ok = false;
  for (auto & s : cores)
    if (s.second.size())
    {
      ok = true;
      cout << s.first << ":";
      for (const string & str : s.second)
        cout << " " << str;
      cout << "\n";
    }
  if (!ok)
    cout << "***\n";
}
