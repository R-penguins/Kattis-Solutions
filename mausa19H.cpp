/**
 * Don't Fence Me In
 */
#include <bits/stdc++.h>
using namespace std;
struct Pt
{
  int r, c;
  Pt(int r = 0, int c = 0) : r(r), c(c) { }
  Pt operator+(const Pt &rhs)
  {
    return Pt(r + rhs.r, c + rhs.c);
  }
};
int main()
{
  const vector<Pt> DIRS {Pt(-1, 0), Pt(0, 1), Pt(1, 0), Pt(0, -1)};
  int r, c;
  cin >> r >> c;
  vector<string> g {string(c + 2, '.')};
  for (int i = 0; i < r; ++i)
  {
    string line;
    cin >> line;
    line = "." + line;
    line.append(".");
    g.push_back(line);
  }
  g.push_back(string(c + 2, '.'));
  int ans = 0;
  queue<Pt> q;
  q.push(Pt(0, 0));
  g[0][0] = ' ';
  while (!q.empty())
  {
    Pt cur = q.front();
    q.pop();
    for (const Pt &dir : DIRS)
    {
      Pt next = cur + dir;
      if (0 <= next.r && next.r < r + 2 && 0 <= next.c && next.c < c + 2 &&
          g[next.r][next.c] == '.')
      {
        g[next.r][next.c] = ' ';
        q.push(next);
      }
    }
    // upper left
    if (cur.r > 0 && cur.c > 0 &&
        g[cur.r - 1][cur.c] != '/' &&
        g[cur.r][cur.c - 1] != '/' &&
        g[cur.r - 1][cur.c - 1] == '.')
    {
      g[cur.r - 1][cur.c - 1] = ' ';
      q.push(Pt(cur.r - 1, cur.c - 1));
    }
    // upper right
    if (cur.r > 0 && cur.c < c + 1 &&
        g[cur.r - 1][cur.c] != '\\' &&
        g[cur.r][cur.c + 1] != '\\' &&
        g[cur.r - 1][cur.c + 1] == '.')
    {
      g[cur.r - 1][cur.c + 1] = ' ';
      q.push(Pt(cur.r - 1, cur.c + 1));
    }
    // lower left
    if (cur.r < r + 1 && cur.c > 0 &&
        g[cur.r + 1][cur.c] != '\\' &&
        g[cur.r][cur.c - 1] != '\\' &&
        g[cur.r + 1][cur.c - 1] == '.')
    {
      g[cur.r + 1][cur.c - 1] = ' ';
      q.push(Pt(cur.r + 1, cur.c - 1));
    }
    // lower right
    if (cur.r < r + 1&& cur.c < c + 1 &&
        g[cur.r + 1][cur.c] != '/' &&
        g[cur.r][cur.c + 1] != '/' &&
        g[cur.r + 1][cur.c + 1] == '.')
    {
      g[cur.r + 1][cur.c + 1] = ' ';
      q.push(Pt(cur.r + 1, cur.c + 1));
    }
  }
  int nodot = 0;
  for (int i = 1; i <= r; ++i)
    for (int j = 1; j <= c; ++j)
      if (i < r && j < c &&
          g[i][j] == '/' &&
          g[i][j + 1] == '\\' &&
          g[i + 1][j] == '\\' &&
          g[i + 1][j + 1] == '/')
        ++nodot;
      else if (g[i][j] == '.')
      {
        ++ans;
        queue<Pt> q;
        g[i][j] = ' ';
        q.push(Pt(i, j));
        while (!q.empty())
        {
          Pt cur = q.front();
          q.pop();
          for (const Pt &dir : DIRS)
          {
            Pt next = cur + dir;
            if (0 <= next.r && next.r <= r && 0 <= next.c && next.c <= c &&
                g[next.r][next.c] == '.')
            {
              g[next.r][next.c] = ' ';
              q.push(next);
            }
          }
    // upper left
    if (cur.r > 1 && cur.c > 1 &&
        g[cur.r - 1][cur.c] != '/' &&
        g[cur.r][cur.c - 1] != '/' &&
        g[cur.r - 1][cur.c - 1] == '.')
    {
      g[cur.r - 1][cur.c - 1] = ' ';
      q.push(Pt(cur.r - 1, cur.c - 1));
    }
    // upper right
    if (cur.r > 1 && cur.c < c &&
        g[cur.r - 1][cur.c] != '\\' &&
        g[cur.r][cur.c + 1] != '\\' &&
        g[cur.r - 1][cur.c + 1] == '.')
    {
      g[cur.r - 1][cur.c + 1] = ' ';
      q.push(Pt(cur.r - 1, cur.c + 1));
    }
    // lower left
    if (cur.r < r && cur.c > 1 &&
        g[cur.r + 1][cur.c] != '\\' &&
        g[cur.r][cur.c - 1] != '\\' &&
        g[cur.r + 1][cur.c - 1] == '.')
    {
      g[cur.r + 1][cur.c - 1] = ' ';
      q.push(Pt(cur.r + 1, cur.c - 1));
    }
    // lower right
    if (cur.r < r && cur.c < c &&
        g[cur.r + 1][cur.c] != '/' &&
        g[cur.r][cur.c + 1] != '/' &&
        g[cur.r + 1][cur.c + 1] == '.')
    {
      g[cur.r + 1][cur.c + 1] = ' ';
      q.push(Pt(cur.r + 1, cur.c + 1));
    }
    /*
          // upper left
          if (cur.r < r && cur.c > 1 &&
              g[cur.r - 1][cur.c] != '/' &&
              g[cur.r][cur.c + 1] != '/' &&
              g[cur.r - 1][cur.c + 1] == '.')
          {
            g[cur.r - 1][cur.c + 1] = ' ';
            q.push(Pt(cur.r - 1, cur.c + 1));
          }
          // upper right
          if (cur.r < r && cur.c < c &&
              g[cur.r + 1][cur.c] != '\\' &&
              g[cur.r][cur.c + 1] != '\\' &&
              g[cur.r + 1][cur.c + 1] == '.')
          {
            g[cur.r + 1][cur.c + 1] = ' ';
            q.push(Pt(cur.r + 1, cur.c + 1));
          }
          // lower left
          if (cur.r > 1 && cur.c > 1 &&
              g[cur.r - 1][cur.c] != '\\' &&
              g[cur.r][cur.c - 1] != '\\' &&
              g[cur.r - 1][cur.c - 1] == '.')
          {
            g[cur.r - 1][cur.c - 1] = ' ';
            q.push(Pt(cur.r - 1, cur.c - 1));
          }
          // lower right
          if (cur.r > 1 && cur.c < c &&
              g[cur.r - 1][cur.c] != '/' &&
              g[cur.r][cur.c + 1] != '/' &&
              g[cur.r - 1][cur.c + 1] == '.')
          {
            g[cur.r - 1][cur.c + 1] = ' ';
            q.push(Pt(cur.r - 1, cur.c + 1));
          }
          */
        }
      }
  cout << nodot + ans << "\n";
}
