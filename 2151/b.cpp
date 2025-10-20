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
  ll n, m; cin >> n >> m;
  string s; cin >> s;
  vector<ll> a(m);
  map<ll, bool> mp;
  loop(i, m) {
    cin >> a[i];
    mp[a[i]] = 1;
  }
  ll cur = 1;
  loop(i, n) {
    if (s[i] == 'A') {
      cur++;
      mp[cur] = 1;
    }
    else {
      cur++;
      while (mp.count(cur)) {
        cur++;
      }
      mp[cur] = 1;
      while (mp.count(cur)) {
        cur++;
      }
    }
  }
  cout << mp.size() << endl;
  for (auto x : mp) {
    cout << x.first << " ";
  }
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
