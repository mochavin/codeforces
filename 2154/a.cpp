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
  string s; cin >> s;
  ll ans = 0, c = 0, f = 0;
  loop(i, n) {
    if (s[i] == '0') c++;
    else {
      if (!f) {
        ans++;
      }
      else {
        if (c >= k - 1) ans++;
      }
      f = 1;
      c = 0;
    }
  }
  cout << ans << endl;
}

int main()
{
  #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
  #endif
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
