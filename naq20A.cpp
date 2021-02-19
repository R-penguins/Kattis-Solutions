#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int N;
  cin >> N;
  string line;
  getline(cin, line);
  vector<int> char_lang(N);
  map<string, int> lang_id;
  vector<vector<int>> lang_char;
  for (int character = 0; character < N; ++character)
  {
    getline(cin, line);
    stringstream ss(line);
    string word;
    ss >> word; //name
    ss >> word; // native
    if (lang_id.find(word) == lang_id.end())
    {
      lang_id[word] = lang_id.size();
      lang_char.push_back(vector<int> {character});
    }
    char_lang[character] = lang_id[word];
    while (ss >> word)
    {
      if (lang_id.find(word) == lang_id.end())
      {
        lang_id[word] = lang_id.size();
        lang_char.push_back(vector<int> {character});
      }
      else
        lang_char[lang_id[word]].push_back(character);
    }
  }
  vector<vector<bool>> understand(N, vector<bool>(N));
  for (int character = 0; character < N; ++character)
  {
    for (int i : lang_char[char_lang[character]])
      understand[character][i] = true;
  }

  vector<bool> del(N);
  for (int character = 0; character < N; ++character)
  {
    if (del[character])
      break;
    vector<bool> vis(N);
    vis[character] = true;
    queue<int> q;
    q.push(character);
    while (!q.empty())
    {
      int cur = q.front();
      q.pop();
      for (int i = 0; i < N; ++i)
        if (!del[i] && !vis[i] && understand[cur][i])
        {
          vis[i] = true;
          q.push(i);
        }
    }
    for (int i = 0; i < N; ++i)
      if (!vis[i])
      {
        del[i] = true;
      }
  }
  cout << accumulate(del.begin(), del.end(), 0) << '\n';
  return 0;
}
