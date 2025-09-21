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
  ll n, k; cin >> n >> k;
  vector<ll> a(n), b(k);
  loop(i, n) cin >> a[i];
  loop(i, k) cin >> b[i];
  sort(all(b));
  sort(rall(a));
  ll it = b[0], ans = 0;
  for (int i = 0, j = 0; i < n; i++) {
    ans += a[i];
    it--;
    if (j < k and it == 0) {
      ans -= a[i];
      j++;
      it = b[j];
    }
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
