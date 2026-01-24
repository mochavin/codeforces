#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  int n; cin >> n;
  vector<int> v(n);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    mp[v[i]]++;
  }
  vector<int> vv;
  for (auto x : mp) {
    vv.push_back(x.first);
  }
  n = vv.size();

  int mx = 0;
  for (int i = 0; i < n; i++) {
    int c = vv[i];
    for (int j = i; j < n; j++) {
      if (vv[j] - c != j - i) {
        mx = max(mx, j - i);
        break;
      }
      if (j == n - 1) mx = max(mx, j - i + 1);
    }
  }
  cout << mx << endl;
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
