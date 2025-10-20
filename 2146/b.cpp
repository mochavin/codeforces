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
  ll n, m; cin >> n >> m;
  set<ll>st;
  vector<ll> ss(m + 1, 0);
  vector<vector<ll>> tt(n);
  loop(i, n) {
    ll L; cin >> L;
    tt[i].resize(L);
    loop(j, L) {
      ll in; cin >> in;
      tt[i][j] = in;
      ss[in]++;
      st.insert(in);
    }
  }
  if (st.size() != m) {
    cout << "NO" << endl; return;
  }
  ll cc = 1;
  loop(i, n) {
    int ok = 1;
    for (auto x : tt[i]) {
      if (ss[x] == 1) {
        ok = 0;
        break;
      }
    }
    // cout << i << " ";
    cc += ok;
  }
  cout << (cc >= 3 ? "YES" : "NO") << endl;
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
