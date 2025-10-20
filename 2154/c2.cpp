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
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  map<ll, ll> mp, mp2;
  loop(i, n) {
    cin >> a[i];
  }
  loop(i, n) {
    cin >> b[i];
    if (mp2.count(a[i])) mp2[a[i]] = min(b[i], mp2[a[i]]);
    else mp2[a[i]] = b[i];
  }
  loop(i, n) {
    for (int j = 1; j * j <= a[i]; j++) {
      if (j * j == a[i]) mp[j]++;
      else if (a[i] % j == 0) mp[j]++, mp[a[i] / j]++;
      if (j > 1 and (mp.count(j) and mp.count(a[i] / j) and (mp[j] > 1 or mp[a[i] / j] > 1))) {
        cout << 0 << endl; return;
      }
    }
  }

  ll mn = M;
  for (auto [fs, se] : mp) {
    // cout << fs << ": ";
    loop(i, n) {
      if (fs > 1 and (a[i] + 1) % fs == 0 and a[i] > 1) {
        // cout << i << " ";
        mn = min(mn, b[i]);
      }
    }
    // cout << endl;
  }
  sort(all(b));
  sort(all(a));
  if (mn == M) cout << b[0] + b[1] << endl;
  else {
    ll temp = (a[1] - a[0]) * mp2[a[0]];
    loop(i, n - 1) {
      temp = min(temp, (a[i + 1] - a[i]) * mp2[a[i]]);
    }
    cout << min(temp, min(mn, b[0] + b[1])) << endl;
  }

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
