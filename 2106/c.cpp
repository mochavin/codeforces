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
  int n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];
  ll mx = 0, mn = 2 * M;
  set<int> st;
  loop(i, n) {
    if (b[i] != -1) {
      st.insert(a[i] + b[i]);
    }
    else {
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
    }
  }
  if (st.size() > 1) {
    cout << 0 << endl; return;
  }
  if (st.size() == 1) {
    ll val = *st.begin();
    if (mn + k < val || mx > val) cout << 0 << endl;
    else cout << 1 << endl; return;
  }
  cout << max(0ll, mn + k - mx + 1) << endl;
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
