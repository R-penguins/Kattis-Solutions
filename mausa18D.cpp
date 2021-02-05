#include <bits/stdc++.h>
using namespace std;
using Pt = pair<int, int>;
map<Pt, int> toID;
vector<vector<int>> adjs;
int id(const Pt &pt)
{
    if (toID.count(pt))
        return toID[pt];
    adjs.push_back(vector<int>());
    return toID[pt] = toID.size();
}
int main()
{
    regex r("\\s*\\(\\s*(\\d*)\\s*,\\s*(\\d*)\\s*\\)\\s*,\\s*\\(\\s*(\\d*)\\s*,\\s*(\\d*)\\s*\\)\\s*;");
    string line;
    while (getline(cin, line))
        for (sregex_iterator it(line.begin(), line.end(), r), end_it; it != end_it; ++it)
        {
            int x1 = stoi(it->str(1)), y1 = stoi(it->str(2)),
                x2 = stoi(it->str(3)), y2 = stoi(it->str(4));
            int id1 = id(Pt(x1, y1)), id2 = id(Pt(x2, y2));
            adjs[id1].push_back(id2);
            adjs[id2].push_back(id1);
        }
    int fig = 0, poly = 0;
    vector<bool> vis(adjs.size(), false);
    for (int i = 0; i < adjs.size(); ++i)
        if (!vis[i])
        {
            vis[i] = true;
            ++fig;
            bool isPoly = (adjs[i].size() % 2 == 0);
            queue<int> q;
            q.push(i);
            while (!q.empty())
            {
                int cur = q.front();
                q.pop();
                isPoly &= (adjs[cur].size() % 2 == 0);
                for (int next : adjs[cur])
                    if (!vis[next])
                    {
                        vis[next] = true;
                        q.push(next);
                    }
            }
            if (isPoly)
                ++poly;
        }
    cout << fig << " " << poly << "\n";
}
