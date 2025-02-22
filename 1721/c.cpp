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
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  for (int i = 0, j = 0; i < n; i++) {
    while (b[j] < a[i]) j++;
    cout << b[j] - a[i] << " ";
  }
  cout << endl;
  vector<ll> ans;
  for (int i = 0, j = 0; i < n; i++) {
    j = max(i, j);
    while (j + 1 < n and a[j + 1] <= b[j]) j++;
    cout << b[j] - a[i] << " ";
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
