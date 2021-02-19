//TLE
#include <bits/stdc++.h>
using namespace std;
using PII = pair<int, int>;

int mod(int a, int b)
{
    return ((a % b) + b) % b;
}

int gcd(int a, int b)
{
    while (b) {
        int t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

int extended_euclid(int a, int b, int &x, int &y)
{
    int xx = y = 0;
    int yy = x = 1;
    while (b)
    {
        int q = a / b;
        int t = b; b = a % b; a = t;
        t = xx; xx = x - q * xx; x = t;
        t = yy; yy = y - q * yy; y = t;
    }
    return a;
}

PII crt_single(int m1, int r1, int m2, int r2)
{
  int s, t;
  int g = extended_euclid(m1, m2, s, t);
  if (r1 % g != r2 % g) return make_pair(0, -1);
  return make_pair(mod(s * r2 * m1 + t * r1 * m2, m1 * m2) / g, m1 * m2 / g);
}

// PII crt(const vector<int> &m, const vector<int> &r) 
// {
//     PII ret = make_pair(r[0], m[0]);
//     for (int i = 1; i < m.size(); i++) 
//     {
//         ret = crt_single(ret.second, ret.first, m[i], r[i]);
//         if (ret.second == -1) break;
//         cout << "ret is " << ret.first << ' ' << ret.second << endl; //debug
//     }
//     return ret;
// }

int crt(const vector<int> &m, const vector<int> &r)
{
    int a = 1;
    while (1)
    {
        bool found = true;
        for (int i = 0; i < m.size(); ++i)
        {
            if (a % m[i] != r[i])
            {
                found = false;
                break;
            }
        }
        if (found)
            return a;
        a++;
    }
}

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int boxw, boxl, minlim, maxlim;
  vector<int> rem(3), top_size(3);
  cin >> boxw >> boxl;
  for (int &i : rem)
    cin >> i;
  cin >> minlim >> maxlim;

  vector<int> boxsize;
  for (int r = 0; r < (int) boxw / 2; ++r) 
      boxsize.push_back(r * (boxw - 2 * r) * (boxl - 2 * r));
  make_heap(boxsize.begin(), boxsize.end());

  for (int &i : top_size)
  {
    pop_heap(boxsize.begin(), boxsize.end());
    i = boxsize.back();
    boxsize.pop_back();
  }

//   PII ans_pair = crt(top_size, rem);
//   int ans = ans_pair.first, modulo = ans_pair.second;
//   cout << ans << ' ' << modulo << endl; // debug
//   while (ans < minlim)
//     ans += modulo;

  int ans = crt(top_size, rem);
  int least_cm = lcm(lcm(top_size[0], top_size[1]), top_size[2]);
  while (ans < minlim)
    ans += least_cm;

  cout << ans << endl;
  return 0;
}
