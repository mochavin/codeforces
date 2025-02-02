#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  sort(all(a));
  sort(all(b));
  set<ll> sta, stb;
  loop(i, n) sta.insert(a[i]);
  loop(i, n) stb.insert(b[i]);

  if (sta.size() + stb.size() - 1 >= 3) cout << "YES" << endl;
  else cout << "NO" << endl;

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
