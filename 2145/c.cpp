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
  ll n; cin >> n; string s; cin >> s;
  vector<ll> pre(n + 1, 0);
  loop1(i, n) {
    pre[i] = pre[i - 1] + (s[i - 1] == 'a' ? 1 : -1);
  }

  // shortest substring sum = pre[n];
  map<ll, ll> mp;
  mp[0] = 0;
  ll ans = M;
  loop1(i, n) {
    mp[pre[i]] = i;
    ll cek = pre[i] - pre[n];
    if (mp.count(cek)) {
      // cout << i << " ";
      ans = min(i - mp[cek], ans);
    }
  }
  if (ans == n) cout << -1 << endl;
  else
    cout << ans << endl;
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
