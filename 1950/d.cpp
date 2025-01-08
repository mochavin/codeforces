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
  int n; cin >> n;
  vector<ll> v;
  map<ll, ll> mp;
  v.push_back(0);
  mp[0] = 0;
  mp[1] = 1;
  v.push_back(1);
  loop(i, 5) {
    int n = v.size();
    loop(j, n) {
      v.push_back(10 * v[j]);
      v.push_back(10 * v[j] + 1);
      mp[10 * v[j]] = 10 * v[j];
      mp[10 * v[j] + 1] = 10 * v[j] + 1;
    }
  }
  while (n >= 1)
  {
    int f = 0;
    if (mp.find(n) != mp.end() or n == 1) {
      cout << "YES" << endl;
      return;
    }
    for (auto x : mp) {
      if (x.second == 0 || x.second == 1) continue;
      if (n % x.second == 0) {
        f = 1;
        n /= x.second;
      }
    }
    if (f == 0) break;
  }
  cout << "NO" << endl;
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
