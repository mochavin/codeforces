#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  ll n, k; cin >> n >> k;
  map<ll, ll> mp1, mp2;
  vector<ll> v(n);
  loop(i, n) {
    cin >> v[i];
    mp1[v[i]] = i;
  }
  sort(all(v));
  // loop(i, n) cout << v[i] << " ";
  ll ans = 0;
  for (ll l = 0, r = n - 1; l < r;) {
    if (v[r] + v[l] > k) r--;
    else if (v[r] + v[l] < k) l++;
    else {
      r--, l++;
      ans++;
    }
  }
  cout << ans;
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
