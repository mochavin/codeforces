#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;


void solve()
{
  // only need how many problem count solved
  ll n, m; cin >> n >> m;
  vector<ll> a(n), b(m);
  loop(i, n) {
    cin >> a[i];
    // ignore all rank below a[0]
    if (a[i] < a[0]) a[i] = a[0];
  }
  loop(i, m) {
    cin >> b[i];
    // set no problem solved by me, so 0 problem has solved
    if (b[i] <= a[0]) b[i] = M;
  }
  vector<ll> cn(m);
  sort(all(a));
  sort(all(b));
  loop(i, m) {
    // count how many other solve problem i i.e from a[j] >= b[i] to end
    // it should in decreasing order
    cn[i] = a.end() - lower_bound(all(a), b[i]);
    // cout << cn[i] << " \n"[i == m - 1];
  }

  // what problem to choose
  sort(all(cn));
  loop1(k, m) {
    ll ans = 0;
    for (ll i = k - 1; i < m; i += k) {
      ans += cn[i] + 1;
    }
    cout << ans << " \n"[k == m];
  }

}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
