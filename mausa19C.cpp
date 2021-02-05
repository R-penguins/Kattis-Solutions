/**
 * Gray Balance
 */
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  bool ok = true;
  vector<int> wcol(n, 0);
  vector<string> cols(n, "");
  for (int i= 0; ok && i < n; ++i)
  {
    string line;
    cin >> line;
    if (line.find("WWW") != string::npos || line.find("BBB") != string::npos)
      ok = false;
    int w = 0, b = 0;
    for (int j = 0; j < n; ++j)
    {
      if (line[j] == 'W')
      {
        ++w;
        ++wcol[j];
      }
      else
        ++b;
      cols[j] += line[j];
    }
    if (w != b)
      ok = false;
  }
  for (int i : wcol)
    if (i != n / 2)
      ok = false;
  for (int i = 0; ok && i < n; ++i)
    if (cols[i].find("WWW") != string::npos || cols[i].find("BBB") != string::npos)
      ok = false;
  if (ok)
    cout <<"1\n";
  else
    cout << "0\n";
}
