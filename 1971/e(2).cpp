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
  vector<ll> a(k), b(k);
  // a[i] == n
  loop(i, k) cin >> a[i];
  loop(i, k) cin >> b[i];

  while(q--) {
    ll in; cin >> in;
    // greatest a[x] less than in;
    ll l = 0, r = k-1, ans = -1;
    while(l <= r) {
      ll m = l + (r-l)/2;
      if(in >= a[m]) {
        ans = m;
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    if(ans == -1) {
      cout << in * b[0] /a[0] << " ";
    } else if(ans != k-1) {
      cout << (in - a[ans]) * (b[ans+1]-b[ans])/(a[ans+1]-a[ans])  + b[ans] << " ";
    } else {
      cout << b[ans] << " ";
    }
  }
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
