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
  vector<pair<ll, ll>> pr(n);
  loop(i, n) cin >> a[i];
  loop(i, n) {
    cin >> b[i]; pr[i] = { a[i], b[i] };
  }
  sort(all(pr), [&](pair<ll, ll> x, pair<ll, ll> y) {
    return x.second < y.second;
    });

  fill(all(cnt), 0);

  loop(i, n) {
    for (auto x : fac[a[i]]) {
      cnt[x]++;
      if (cnt[x] > 1) {
        cout << 0 << endl; return;
      }
    }
  }

  ll ans = pr[0].second + pr[1].second;

  loop(i, n) {
    for (auto x : fac[pr[i].first]) {
      cnt[x]--;
    }
    for (auto x : fac[pr[i].first + 1]) {
      if (cnt[x]) {
        ans = min(ans, pr[i].second);
      }
    }
    for (auto x : fac[pr[i].first]) {
      cnt[x]++;
    }
  }

  set<ll> allFac;
  loop1(i, n - 1) {
    for (auto x : fac[pr[i].first]) {
      allFac.insert(x);
    }
  }

  for (auto x : allFac) {
    ll t = x - (pr[0].first % x);
    ans = min(ans, t * pr[0].second);
  }
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  for (ll i = 2; i < N; i++) {
    if (fac[i].size()) continue;
    for (ll j = i; j < N; j += i) {
      fac[j].push_back(i);
    }
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
