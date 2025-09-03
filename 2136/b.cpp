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
  ll satu = 0, nol = 0;
  ll c = 0;
  loop(i, n) {
    if (c >= k) {
      cout << "NO" << endl; return;
    }
    if (s[i] == '1') satu++, c++;
    else nol++, c = 0;
  }
  if (c >= k) {
    cout << "NO" << endl; return;
  }
  vector<ll> ans(n);
  ll mx = n, mn = 1;
  loop(i, n) {
    if (s[i] == '1') ans[i] = mn++;
    else ans[i] = mx--;
  }
  cout << "YES" << endl;
  for (auto x : ans) cout << x << " ";
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
