#include <bits/stdc++.h>
using namespace std;
struct Vec
{
  double x, y;
  Vec(double x = 0, double y = 0) : x(x), y(y) { }

  double len() const
  {
    return sqrt(x * x + y * y);
  }
};
using Pt = Vec;

struct Line
{
  Pt pt;
  Vec vec;
  Line(Pt pt = 0, Vec vec = 0) : pt(pt), vec(vec) { }
};

Vec operator- (const Vec &l, const Vec &r)
{
  return Vec(l.x - r.x, l.y - r.y);
}

double cross (const Vec &l, const Vec &r)
{
  return l.x * r.y - l.y * r.x;
}

double dist (const Pt &p, const Line &line)
{
  return abs(cross(line.vec, p - line.pt)) / line.vec.len();
}

int main()
{
  int n;
  cin >> n;
  vector<Pt> pts(n);
  for (auto &pt : pts)
  {
    cin >> pt.x >> pt.y;
  }
  pts.push_back(pts[0]);
  double ans = 1000000000;
  for (int i = 0; i < n; ++i)
  {
    Line line(pts[i], pts[i + 1] - pts[i]);
    double maxd = 0;
    for (int j = 0; j < n; ++j)
    {
      if (j != i && j != i + 1)
      {
        maxd = max(maxd, dist(pts[j], line));
      }
    }
    ans = min(ans, maxd);
  }
  cout << ans << "\n";
}
