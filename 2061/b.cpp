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
ll N = 2e5 + 1;

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];
  sort(all(v));
  ll k = -1;
  loop(i, n) {
    if (!i) continue;
    if (v[i] == v[i - 1]) k = i;
  }

  if (k == -1) {
    cout << -1 << endl; return;
  }

  ll x = v[k];

  v.erase(v.begin() + k);
  v.erase(v.begin() + k - 1);

  loop(i, v.size()) {
    if (!i)  continue;
    if (2 * x + v[i - 1] > v[i]) {
      cout << x << " " << x << " " << v[i - 1] << " " << v[i] << endl;
      return;
    }
  }


  cout << -1 << endl;
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
