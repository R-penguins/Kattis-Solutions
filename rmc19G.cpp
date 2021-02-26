#include <bits/stdc++.h>
using namespace std;

// already sure that b.size() == a.size() + 1
bool isTypo(const string &a, const string &b)
{
    for (int i = 0; i < a.size(); ++i)
        if (a[i] != b[i])
            return equal(a.cbegin() + i, a.cend(), b.cbegin() + i+1);
    return true; // first a.size() chars are same, return true
}

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  int minlen = numeric_limits<int>::infinity();
  int maxlen = -numeric_limits<int>::infinity();
  cin >> n;
  vector<string> pool, ans;
  string line;
  while (getline(cin, line))
  {
    pool.push_back(line);
    int sz = line.size();
    minlen = min(minlen, sz);
    maxlen = max(maxlen, sz);
  }

  sort(pool.begin(), pool.end(), []
    (const std::string& first, const std::string& second){
        return first.size() < second.size();
    });

  for (auto &wa : pool)
  {
    for (auto &wb : pool)
    {
      if (wb.size() != wa.size() + 1) 
          continue;
      if (isTypo(wa, wb))
          ans.push_back(wb);
    }
  }

  if (ans.size() == 0)
  {
      cout << "NO TYPOS" << endl;
      return 0;
  }

  auto iter = unique(ans.begin(), ans.end());
  ans.erase(iter, ans.end());
  for (auto &s : ans)
    cout << s << endl;
  return 0;
}
