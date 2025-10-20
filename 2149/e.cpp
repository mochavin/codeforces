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
  ll n, k, l, r; cin >> n >> k >> l >> r;
  vector<ll> v(n);
  loop(i, n) {
    cin >> v[i];
  }

  ll ans = 0, x = 0, y = 0;
  map<ll, ll> st, st2;
  loop(i, n) {
    while (x <= n and st.size() < k) {
      if (x < n) st[v[x]]++;
      x++;
    }
    while (y <= n and st2.size() <= k) {
      if (y < n) st2[v[y]]++;
      y++;
    }

    ans += max(0ll, min(y - 2, i + r - 1) - (max(x - 1, i + l - 1) - 1));

    if (--st[v[i]] == 0) st.erase(v[i]);
    if (--st2[v[i]] == 0) st2.erase(v[i]);
  }
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
