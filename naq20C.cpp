#include <bits/stdc++.h>
using namespace std;

vector<string> board(8);
bool check(int i, int j)
{
    //row
    for (int jj = 0; jj < 8; ++jj)
        if (jj != j && board[i][jj] == '*')
            return false;
    //col
    for (int ii = 0; ii < 8; ++ii)
        if (ii != i && board[ii][j] == '*')
            return false;
    //diag
    int ii = i, jj = j;
    while (--ii >= 0 && --jj >= 0)
        if (board[ii][jj] == '*')
            return false;
    ii = i, jj = j;
    while (++ii < 8 && ++jj < 8)
        if (board[ii][jj] == '*')
            return false;
    //antidiag
    ii = i, jj = j;
    while (--ii >= 0 && ++jj < 8)
        if (board[ii][jj] == '*')
            return false;
    ii = i, jj = j;
    while (++ii < 8 && --jj >= 0)
        if (board[ii][jj] == '*')
            return false;
    
    return true;
}
int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (string& s : board)
        cin >> s;
    
    int queen = 0;
    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j)
            if (board[i][j] == '*')
            {
                ++queen;
                if (!check(i, j))
                {
                    cout << "invalid";
                    return 0;
                }
            }
    cout << ((queen == 8) ? "valid" : "invalid");
    return 0;
}
