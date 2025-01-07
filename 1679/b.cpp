#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  int n, q; cin >> n >> q;
  vector<ll> a(n);
  ll sum = 0;
  loop(i, n) {
    cin >> a[i];
    sum += a[i];
  }

  ll f = 0, fresh = -1;
  map<ll, ll> mp;
  loop(i, q) {
    int t; cin >> t;
    if (t == 1) {
      ll n, x; cin >> n >> x;
      n--;
      sum = sum + x;
      // cek a[n] == fresh?
      if (f && mp.find(n) == mp.end()) sum -= fresh;
      else sum -= a[n];
      mp[n] = 1;
      a[n] = x;
    }
    else {
      ll x; cin >> x;
      f = 1;
      fresh = x;
      sum = n * x;
      mp.clear();
    }
    // loop(i, n) cout << a[i] << " ";
    // cout << "mp: " << i << " " << endl;
    // for (auto it : mp) {
    //   cout << it.first << " ";
    // }

    cout << sum << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  // ll t; cin >> t;
  // while (t--)
  solve();

  return 0;
}
