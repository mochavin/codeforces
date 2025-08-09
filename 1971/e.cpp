#include <bits/stdc++.h>
#include <iostream>
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
  int n, k, q; cin >> n >> k >> q;
  vector<ll> a(k + 2, 0), b(k + 2, 0);
  map<ll, ll> mp;
  // a[k] == n
  for (ll i = 1; i <= k; i++) {
    cin >> a[i];
    mp[b[i]] = i;
  }
  vector<ll> prefix(k + 2, 0);
  for (ll i = 1; i <= k; i++) {
    cin >> b[i];
    prefix[i] = prefix[i - 1] + b[i];
  }


  while (q--) {
    ll d; cin >> d;
    // greatest a[i] that <= d
    ll l = 0, r = k;
    while (l < r) {
      ll mid = (l + r + 1) / 2;
      if (a[mid] > d) r = mid - 1;
      else if (a[mid] < d) l = mid + 1;
      else {
        l = mid; break;
      }
    }
    if (a[l] > d) l--;
    // cout << "l: " << (d - a[l]) * (b[l + 1] - b[l]) << " || ";
    if (d == a[l]) cout << b[l] << " ";
    else cout << b[l] + (d - a[l]) * (b[l + 1] - b[l]) / (a[l + 1] - a[l]) << " ";
  }
  cout << endl; return;
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
