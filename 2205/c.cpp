#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
int M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  int n; cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    int l; cin >> l;
    for (int j = 0; j < l; j++) {
      int t; cin >> t;
      a[i].emplace_back(t);
    }
    reverse(begin(a[i]), end(a[i]));
  }

  unordered_map<int, bool> vv;
  for (int i = 0; i < n; i++) {
    vector<int> temp;
    for (auto x : a[i]) if (!vv[x]) temp.emplace_back(x), vv[x] = true;
    for (auto x : temp) vv[x] = false;
    a[i] = temp;
  }

  // for (auto v : a) {
  //   for (auto x : v) {
  //     cout << x << " ";
  //   }
  //   cout << endl;
  // }

  vector<bool> vis(n, false);
  unordered_map<int, int> mp;
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    int id = i;
    for (int j = 0; j < n; j++) {
      if (a[j] < a[id] and !vis[j]) id = j;
    }

    for (int j = 0; j < a[id].size(); j++) {
      if (!mp.count(a[id][j])) { ans.emplace_back(a[id][j]); mp[a[id][j]]++; }
    }

    a[id] = { M };

    for (int j = 0; j < n; j++) {
      if (a[j].size() == 0 or a[j][0] == M) continue;

      vector<int> temp;
      for (int k = 0; k < a[j].size(); k++) {
        if (!mp.count(a[j][k])) temp.emplace_back(a[j][k]);
      }

      a[j] = temp;
    }
    vis[id] = true;
  }

  for (auto x : ans) cout << x << " ";
  cout << endl;


}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
