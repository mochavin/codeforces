#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  int n, m; cin >> n >> m;
  vector<ll> v(n);
  loop(i, n) {
    string s; cin >> s;
    v[i] = s.length();
  }
  // sort(v.begin(), v.end());
  ll ans = 0;
  loop(i, n) {
    if (v[i] <= m) {
      m -= v[i];
      ans++;
    }
    else {
      break;
    }
  }
  cout << ans << endl;
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
