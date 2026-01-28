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
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<ll> pre(n + 1, 0), s(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pre[i + 1] = v[i];
    pre[i + 1] += pre[i];
    ll c = i + 1;
    s[i + 1] = c * c + c - pre[i + 1];
  }
  ll mn = s[0], ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, s[i] - mn);
    // cout << s[i] << " ";
    mn = min(mn, s[i]);
  }
  cout << pre[n] + ans << endl;
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
