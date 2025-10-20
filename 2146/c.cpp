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
  ll n; cin >> n;
  string s; cin >> s;
  s = 'a' + s;
  vector<ll> ans(n + 1, 0);
  ll ls = 0;
  loop1(i, n) {
    if (s[i] == '1') {
      ans[i] = i;
      if (ls == i - 2) {
        cout << "NO" << endl; return;
      }
      ll t = i - 2;
      for (ll j = i - 1; j >= ls + 2; j--) {
        ans[j] = t--;
      }
      if (ans[ls + 1] == 0) ans[ls + 1] = i - 1;
      ls = i;
    }
  }
  if (s[n] == '0' and s[n - 1] == '1') {
    cout << "NO" << endl; return;
  }
  cout << "YES" << endl;
  for (ll i = n; i >= 0 and ans[i] == 0; i--) {
    ans[i] = ls + 1; ls++;
  }
  loop1(i, n) cout << ans[i] << " ";
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
