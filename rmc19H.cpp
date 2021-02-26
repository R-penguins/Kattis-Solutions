#include <bits/stdc++.h>
using namespace std;

struct Vector
{
    double x, y;
    Vector(double x = 0, double y = 0) : x(x), y(y) { }

    double length() const
    {
        return sqrt(x * x + y * y);
    }

    Vector normalize() const
    {
        return Vector(-y / length(), x / length());
    }

    double angle() const
    {
        return atan2(y, x);
    }
};

using Point = Vector;

struct Line
{
    Point pt;
    Vector vec;
    Line(Point pt = 0, Vector vec = 0) : pt(pt), vec(vec) { }
};

const double EPS = 1e-10;
int dcmp(double x)
{
    return abs(x) < EPS ? 0 : (x < 0 ? -1 : 1);
}

bool operator==(const Point &l, const Point &r)
{
    return abs(l.x - r.x) <= EPS && abs(l.y - r.y) <= EPS;
}

bool operator<(const Point &l, const Point &r)
{
    return l.x < r.x || (l.x == r.x && l.y < r.y);
}

Vector operator-(const Vector &l, const Vector &r)
{
    return Vector(l.x - r.x, l.y - r.y);
}

Vector operator+(const Vector &l, const Vector &r)
{
    return Vector(l.x + r.x, l.y + r.y);
}

Vector operator*(double k, const Vector &vec)
{
    return Vector(k * vec.x, k * vec.y);
}

Vector operator/(const Vector &vec, double k)
{
    return Vector(vec.x / k, vec.y / k);
}

double dot(const Vector &l, const Vector &r)
{
    return l.x * r.x + l.y * r.y;
}

double angle(const Vector &l, const Vector &r)
{
    return acos(dot(l, r) / l.length() / r.length());
}

double cross(const Vector &l, const Vector &r)
{
    return l.x * r.y - l.y * r.x;
}

double area(const Point &a, const Point &b, const Point &c)
{
    return cross(b - a, c - a);

}

double dist(const Point &a, const Point &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double perimeter(const Point &a, const Point &b, const Point &c)
{
    return dist(a, b) + dist(b, c) + dist(a, c);
}

// Make sure cross(vp, vq) != 0
Point intersect(const Point &p, const Vector &vp, const Point &q, const Vector &vq)
{
    return p + cross(vq, p - q) / cross(vp, vq) * vp;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector <Line> lines;
    for (int i = 0; i < n; i++)
    {
        double x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2; 
        lines.push_back(Line(Point(x1, y1), Vector(x2-x1, y2-y1)));
    }
    
    double max_peri = 0;

    for (int i = 0; i < n; ++i)
    {
        Line &a = lines[i];
        Vector slope_a = a.vec;
        for (int j = i + 1; j < n; ++j)
        {
            Line &b = lines[j];
            Vector slope_b = b.vec;
            if (slope_a == slope_b || slope_a == -1 * slope_b) {continue;}

            for (int k = j + 1; k < n; ++k)
            {
                Line &c = lines[k];
                Vector slope_c = c.vec;
                if (slope_c == slope_a || slope_c == slope_b ||
                    slope_c == -1*slope_a || slope_c == -1*slope_b) 
                    continue;
                
                Point ab = intersect(a.pt, a.vec, b.pt, b.vec),
                      ac = intersect(a.pt, a.vec, c.pt, c.vec),
                      bc = intersect(b.pt, b.vec, c.pt, c.vec);
                double cur_peri = perimeter(ab, ac, bc);

                // cout << ab.x << ' ' << ab.y << endl;
                // cout << ac.x << ' ' << ac.y << endl;
                // cout << bc.x << ' ' << bc.y << endl;
                // cout << "cur_area: "  << cur_area << endl;

                if (max_peri < cur_peri)
                    max_peri = cur_peri;
            }
        }
    }
    
    if (max_peri < EPS)
    {
        cout << "no triangle" << endl;
        return 0;
    }

    cout << fixed << setprecision(6);
    cout << max_peri << endl;
    return 0;
}
