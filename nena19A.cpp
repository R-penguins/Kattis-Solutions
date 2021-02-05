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

bool getrev(int num, int& rev)
{
    rev = 0;
    while (num)
    {
        int cur = num % 10;
        if (cur == 3 || cur == 4 || cur == 7)
            return false;
        else if (cur == 6)
            cur = 9;
        else if (cur == 9)
            cur = 6;
        rev = rev * 10 + cur;
        num /= 10;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, s;
    cin >> n >> s;
    map<int, int> num_forbidden;
    while (n--)
    {
        int i;
        cin >> i;
        int rev;
        if (getrev(i, rev))
        {
            if (num_forbidden.find(rev) == num_forbidden.end())
            {
                num_forbidden[i] = rev;
                num_forbidden[rev] = i;
            }
            else
            {
                num_forbidden[i] = -1;
                num_forbidden[rev] = -1;
            }
        }
        else
            num_forbidden[i] = -1;
    }
    vector<pair<int, int>> arr;
    for (auto i : num_forbidden)
        arr.push_back(i);
    for (int i = 0, j = arr.size() - 1; i < j; ++i)
    {
        while (i < j && arr[i].first + arr[j].first > s)
            --j;
        if (arr[i].first + arr[j].first == s && arr[i].second != arr[j].first)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";

    return 0;
}
