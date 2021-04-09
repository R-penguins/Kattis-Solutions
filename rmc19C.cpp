// Unfinished
#include <bits/stdc++.h>
using namespace std;
using VD = vector<double>;
using VVD = vector<VD>;
using VI = vector<int>;
using VII = vector<VI>;
using VS = vector<string>;
constexpr double EPS = 1e-9;

struct Pt
{
  Pt() {}
  Pt(int x, int y) : x(x), y(y) {}
  int x = -1, y = -1;
};

VS paper(6);
int maxl = 0;
Pt max_pt;

void invert()
{
  VS ans(paper.size(), string(paper.size(), ' '));
  for (int i = 0; i < paper.size(); ++i)
    for (int j = 0; j < paper[i].size(); ++j)
      ans[i][j] = paper[j][i];
  paper = ans;
}

void fliph()
{
  for (string& str : paper)
    reverse(str.begin(), str.end());
}

void flipv()
{
  VS ans(6, string(6, ' '));
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j)
      ans[i][j] = paper[5 - i][j];
  paper = ans;
}

bool diag4()
{
  //find upper left
  Pt one;
  for (int i = 0; i < 4; ++i)
  {
    one = max_pt;
    one.y += i;
    if (one.x - 1 >= 0 && paper[one.x - 1][one.y] == '#')
    {
      if (one.x - 2 >= 0 && paper[one.x - 2][one.y] == '#')
        return false;
      break;
    }
    if (one.x + 1 < 6 && paper[one.x + 1][one.y] == '#')
    {
      if (one.x + 2 < 6 && paper[one.x + 2][one.y] == '#')
        return false;
      fliph();
      max_pt.x = 5 - max_pt.x;
      one.x = 5 - one.x;
      break;
    }
  }

  if (one.x + 1 >= 6)
    return false;
  while (one.y <= max_pt.y + 3)
  {
    if (paper[one.x + 1][one.y] == '#')
      return true;
    ++one.y;
  }
  return false;
}

bool diag3()
{
  Pt one;
  bool found;
  for (int i = 0; i < 3; ++i)
  {
    one = max_pt;
    one.y += i;
    if (one.x - 1 >= 0 && paper[one.x - 1][one.y] == '#' &&
        (one.y - 1 < 0 || paper[one.x - 1][one.y - 1] != '#') &&
        (one.x - 2 < 0 || paper[one.x - 2][one.y] != '#') &&
        (one.y + 1 >= 6 || paper[one.x - 1][one.y + 1] != '#'))
    {
      found = true;
      break;
    }
    if (one.x + 1 < 6 && paper[one.x + 1][one.y] == '#' &&
        (one.y - 1 < 0 || paper[one.x + 1][one.y - 1] != '#') &&
        (one.x + 2 >= 6 || paper[one.x + 2][one.y] != '#') &&
        (one.y + 1 >= 6 || paper[one.x + 1][one.y + 1] != '#'))
    {
      fliph();
      max_pt.x = 5 - max_pt.x;
      one.x = 5 - one.x;
      found = true;
      break;
    }
  }
  if (!found)
    return false;
  
  if (one.y == max_pt.y + 2)
  {
    flipv();
    max_pt.y = 5 - max_pt.y;
    one.y = 5 - one.y;
  }
  if (one.x + 1 >= 6)
    return false;
  if (one.y == max_pt.y)
  {
    if (paper[max_pt.x + 1][max_pt.y + 1] == '#' &&
        max_pt.x + 2 < 6 && paper[max_pt.x + 2][max_pt.y + 1] == '#')
      return true;
    if (paper[max_pt.x + 1][max_pt.y + 2] == '#' &&
        max_pt.y + 3 < 6 && paper[max_pt.x + 1][max_pt.y + 3] == '#')
      return true;
  }
  else
  {
    if (max_pt.y - 1 >= 0 && paper[max_pt.x + 1][max_pt.y] == '#' && paper[max_pt.x + 1][max_pt.y - 1] == '#')
      return false;
    if (max_pt.y + 1 < 6 && paper[max_pt.x + 1][max_pt.y + 2] == '#' && paper[max_pt.x + 1][max_pt.y + 3] == '#')
      return true;
  }
  return false;
}

vector<Pt> dirs {Pt(-1, 0), Pt(0, 1), Pt(1, 0), Pt(0, 1)};
bool diag2()
{
  Pt cur = max_pt;
  for (int i = 0; i < 5; ++i)
  {
    Pt next;
    bool found;
    for (Pt dir : dirs)
    {
      next = cur;
      next.x += dir.x;
      next.y += dir.y;
      if (next.x == cur.x && next.y == cur.y)
        continue;
      if (next.x >= 0 && next.x < 6 && 0 <= next.y && next.y < 6 && paper[next.x][next.y] == '#')
      {
        if (found)
          return false;
        found = true;
      }
    }
    if (!found)
      return false;
    cur = next;
  }
  return true;
}

int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (string& i : paper)
    cin >> i;
  
  // find main diagnal
  int max_h = 0;
  Pt max_h_pt;
  for (int i = 0; i < 6; ++i)
    for (int j = 0; j < 6; ++j)
      if (paper[i][j] == '#')
      {
        int v = 1;
        while (i + v < 6 && paper[i + v][j] == '#')
          ++v;
        if (v > maxl)
        {
          maxl = v;
          max_pt = Pt(i, j);
        }
        int h = 1;
        while (j + h < 6 && paper[i][j + h] == '#')
          ++h;
        if (h > max_h)
        {
          max_h = h;
          max_h_pt = Pt(i, j);
        }
      }
  if (max_h > maxl)
  {
    invert();
    swap(max_h, maxl);
    swap(max_h_pt.x, max_h_pt.y);
    max_pt = max_h_pt;
  }

  if (maxl >= 5)
  {
    cout << "cannot fold\n";
    return 0;
  }

  if ((maxl == 4 && diag4()) ||
      (maxl == 3 && diag3()) ||
      (maxl == 2 && diag2()))
    cout << "can fold\n";
  else
    cout << "cannot fold\n";

  return 0;
}
