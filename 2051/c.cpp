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

void solve() {
  ll n, m, k; cin >> n >> m >> k;
  map<int, int> mp;
  vector<int> a(m), q(k);
  loop(i, m) {
    cin >> a[i];
  }
  loop(i, k) {
    cin >> q[i];
    mp[q[i]] = 1;
  }

  if (k < n - 1) {
    loop(i, m) cout << 0;
    cout << endl; return;
  }

  loop(i, m) {
    if (mp[a[i]] == 0 || k == n) cout << 1;
    else cout << 0;
  }
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
