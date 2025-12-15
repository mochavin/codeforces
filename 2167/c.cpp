#include <bits/stdc++.h>
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
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int f1 = 0, f2 = 0;
  for (auto x : v) {
    if (x % 2) f1 = 1;
    else f2 = 1;
  }
  if (!(f1 and f2)) {
    for (auto x : v) cout << x << " ";
    cout << endl; return;
  }
  sort(v.begin(), v.end());
  for (auto x : v) cout << x << " ";
  cout << endl; return;
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
