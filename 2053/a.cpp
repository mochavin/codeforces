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
  int n; cin >> n;
  vector<int> v(n);
  int f = 0;
  loop(i, n) {
    cin >> v[i];
    if (i > 0) {
      int mn = min(v[i], v[i - 1]);
      int mx = max(v[i], v[i - 1]);
      if (2 * mn > mx) f = 1;
    }
  }
  cout << (f ? "YES" : "NO") << endl;
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
