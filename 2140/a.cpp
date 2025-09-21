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
  ll c = 0;
  loop(i, n) {
    if (s[i] == '1') c++;
  }
  ll ans = 0;
  for (int i = n - 1; c > 0; i--) {
    if (s[i] == '0') ans++;
    // cout << s[i] << " ";
    c--;
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
