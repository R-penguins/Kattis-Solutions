#include <bits/stdc++.h>
using namespace std;

struct Pt
{
    Pt() {};
    Pt(double x, double y) : x(x), y(y) {}
    double x = -1;
    double y = -1;
};
double dist(const Pt& a, const Pt& b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
struct Seg
{
    Seg() {};
    Seg(double dist, int j, int x) : dist(dist), j(j), x(x) {}
    double dist = numeric_limits<double>::infinity();
    int j = -1;
    int x = -1;
};
Seg min(Seg a, Seg b)
{
    if (a.dist < b.dist)
        return a;
    if (a.dist > b.dist)
        return b;
    if (a.j < b.j)
        return a;
    if (a.j > b.j)
        return b;
    if (a.x < b.x)
        return a;
    return b;
}
int main(int argc, char const *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    vector<Pt> judges(a);
    for (Pt& i : judges)
        cin >> i.x >> i.y;
    vector<Pt> tar(b);
    for (Pt& i : tar)
        cin >> i.x >> i.y;
    vector<Pt> feather(c);
    for (Pt& i : feather)
        cin >> i.x >> i.y;
    
    double ans = 0;
    vector<bool> jvis(a, false);
    vector<bool> tvis(b, false);
    for (int ii = 0; ii < a; ++ii)
    {
        Seg min_seg {};
        for (int i = 0; i < a; ++i)
            if (!jvis[i])
                for (int j = 0; j < b; ++j)
                    if (!tvis[j])
                    {
                        double dis = dist(judges[i], tar[j]);
                        min_seg = min(min_seg, Seg(dis, i, j));
                    }
        ans += min_seg.dist;
        jvis[min_seg.j] = true;
        tvis[min_seg.x] = true;
    }
    fill(jvis.begin(), jvis.end(), false);
    vector<bool> fvis(c, false);
    for (int ii = 0; ii < a; ++ii)
    {
        Seg min_seg {};
        for (int i = 0; i < a; ++i)
            if (!jvis[i])
                for (int j = 0; j < c; ++j)
                    if (!fvis[j])
                    {
                        double dis = dist(judges[i], feather[j]);
                        min_seg = min(min_seg, Seg(dis, i, j));
                    }
        ans += min_seg.dist;
        jvis[min_seg.j] = true;
        fvis[min_seg.x] = true;
    }
    cout << fixed << setprecision(7);
    cout << ans << "\n";
    return 0;
}