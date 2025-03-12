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
  vector<ll> b(2 * n);
  map<ll, ll> mp;
  loop(i, 2 * n) {
    cin >> b[i];
    mp[b[i]] = 1;
  }
  sort(all(b));
  ll sum = 0;
  vector<ll> g;
  loop1(i, n - 1) {
    g.push_back(b[i]);
    g.push_back(b[i + n - 1]);
    sum += b[i + n - 1] - b[i];
  }
  g.push_back(sum + b[n * 2 - 1] + b[0]);
  g.push_back(b[0]);
  cout << g.size() << " ";
  loop(i, n * 2) cout << g[i] << " ";
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
