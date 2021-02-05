#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  set<string> orphan_file;
  map<string, bool> index;
  string line;
  while (getline(cin, line) && line.size())
    index[line] = false;
  while (getline(cin, line))
  {
    auto pos = find(line.rbegin(), line.rend(), '_');
    pos = find(pos + 1, line.rend(), '_');
    string name(line.begin(), pos.base() - 1);
    if (index.count(name))
      index[name] = true;
    else
      orphan_file.insert(line);
  }
  bool mismatch = orphan_file.size();
  for (const string &s : orphan_file)
    cout << "F " << s << "\n";
  for (auto &s : index)
    if (!s.second)
    {
      cout << "I " << s.first << "\n";
      mismatch = true;
    }
  if (!mismatch)
    cout << "No mismatches.\n";
}
