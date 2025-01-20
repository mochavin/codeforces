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
  ll n; cin >> n;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];
  int last = v[1] - v[0];
  if (last < 0) {
    cout << "NO" << endl; return;
  }
  loop(i, n) {
    if (i == 0) continue;
    if (last > v[i]) {
      cout << "NO" << endl; return;
    }
    v[i] -= v[i - 1];
    last = v[i];
    // cout << last << " ";
  }
  cout << "YES" << endl;
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
