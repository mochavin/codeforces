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
  ll n, k; cin >> n >> k;
  map<ll, ll> S, T;
  loop(i, n) {
    ll in; cin >> in;
    S[min(in % k, (k - (in % k)) % k)]++;
  }
  loop(i, n) {
    ll in; cin >> in;
    T[min(in % k, (k - (in % k)) % k)]++;
  }

  for (auto [fs, se] : T) {
    if (S.find(fs) == S.end() || se != S[fs]) {
      cout << "NO" << endl; return;
    }
  }
  cout << "YES" << endl;
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
