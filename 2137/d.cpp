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
  unordered_map<ll, ll> v;
  vector<ll> a(n);
  ll cc = 0;
  loop(i, n) {
    ll in; cin >> in;
    v[in]++;
    a[i] = in;
    if (!v.count(in)) {
      cc += in;
    }
  }
  if (cc > n) {
    cout << -1 << endl; return;
  }
  ll c = 1;
  unordered_map<ll, vector<ll>> mp;
  unordered_map<ll, ll> count;
  for (auto [fs, se] : v) {
    if (se) {
      if (se % fs) {
        cout << -1 << endl; return;
      }
      else {
        auto x = &mp[fs];
        while (se--) {
          mp[fs].push_back(c);
          if (x->size() % fs == 0) c++;
        }
      }
    }
  }
  loop(i, n) {
    cout << mp[a[i]][count[a[i]]++] << " ";
  }
  cout << endl;


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
