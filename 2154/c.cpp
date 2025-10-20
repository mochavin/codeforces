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

vector<vector<ll>> fac(N);
vector<ll> cnt(N);

void solve()
{
  ll n; cin >> n;
  vector<ll> a(n), b(n);
  loop(i, n) cin >> a[i];
  loop(i, n) cin >> b[i];

  fill(all(cnt), 0);

  loop(i, n) {
    for (auto x : fac[a[i]]) {
      cnt[x]++;
      if (cnt[x] > 1) {
        cout << 0 << endl; return;
      }
    }
  }

  loop(i, n) {
    for (auto x : fac[a[i]]) {
      cnt[x]--;
    }
    for (auto x : fac[a[i] + 1]) {
      if (cnt[x]) {
        cout << 1 << endl; return;
      }
    }
    for (auto x : fac[a[i]]) {
      cnt[x]++;
    }
  }
  cout << 2 << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  for (ll i = 2; i <= N; i++) {
    if (fac[i].size()) continue;
    for (ll j = i; j <= N; j += i) {
      fac[j].push_back(i);
    }
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
