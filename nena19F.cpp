#include <cctype>
#include <cmath>
#include <cstdlib>
#include <ctime>

#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>

#include <array>
#include <chrono>
#include <forward_list>
#include <initializer_list>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int w, width_left, ans = 1;

void put(int len)
{
    if (len <= width_left)
        width_left -= len;
    else
    {
        ++ans;
        width_left = w - len;
    }
    if (width_left)
        --width_left;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d >> w;
    width_left = w;
    int prev = 0;
    for (int i = 0; i < n; ++i)
    {
        string line;
        cin >> line;
        if (i % 2)
            reverse(line.begin(), line.end());
        int last;
        if ((last = line.find('.')) != string::npos)
        {
            put(last + prev);
            int loc = last + 1;
            while ((last = line.find('.', loc)) != string::npos)
            {
                put(last - loc);
                loc = last + 1;
            }
            prev = line.size() - loc;
        }
        else
            prev += line.size();
    }
    put(prev);
    cout << ans << '\n';
    return 0;
}
