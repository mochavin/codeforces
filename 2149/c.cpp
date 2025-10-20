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
  vector<ll> v(n);
  map<ll, ll> mp;
  loop(i, n) {
    cin >> v[i];
    mp[v[i]]++;
  }
  ll c = 0;
  for (int i = k - 1; i >= 0; i--) {
    if (mp[i] == 0) c++;
  }
  if (mp[k] >= c) {
    cout << mp[k] << endl;
  }
  else {
    cout << c << endl;
  }
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
