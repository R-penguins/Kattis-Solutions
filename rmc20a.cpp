/// ICPC RMC 2020 A 
#include <bits/stdc++.h>
using namespace std;

int main()
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
