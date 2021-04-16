/// ICPC RMC 2020 B Arithmetic Decoding
#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p;
  cin >> n >> p;
  string encstr, ans(n, '0');
  cin >> encstr;
  long long enc_nm = stoll(encstr.substr(2), nullptr, 2);
  double enc = (double) enc_nm / (1LL << encstr.size()-2);

  double l = 0, r = 1;
  for (char& i : ans) {
    double c = l + (r - l) * p / 8;
    if (enc < c) {
      i = 'A';
      r = c;
    } else {
      i = 'B';
      l = c;
    }
  }

  cout << ans << '\n';

  return 0;
}
