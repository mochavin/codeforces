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

vector<ll> p(100, 0);
map<ll, int> pr;

void solve()
{
  int n; cin >> n;
  vector<ll> v(n, 0);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (auto [k, val] : pr) {
    for (int i = 0; i < n; i++) {
      if (v[i] % k != 0) {
        cout << k << endl; return;
      }
    }
  }
  cout << -1 << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  for (int i = 2; i < 100; i++) {
    if (p[i]) continue;
    pr[i] = 1;
    for (int j = i * 2; j < 100; j += i) {
      p[j] = 1;
    }
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
