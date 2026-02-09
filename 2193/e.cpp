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
set<ll> st;
vector<ll> pre(3e5 + 1, 0);

ll rec(ll n) {
  if (st.count(n)) return 1;
  if (pre[n]) return pre[n];
  ll mn = M, sq = sqrt(n);
  for (int i = 2; i <= sq; i++) {
    if (n % i == 0) mn = min(mn, rec(n / i) + rec(i));
  }
  pre[n] = mn;
  return mn;
}

void solve()
{
  pre.clear();
  pre.resize(3e5 + 1);
  st.clear();
  ll n; cin >> n;
  for (int i = 0; i < n; i++) {
    ll in; cin >> in; st.insert(in);
  }
  if (n == 1) {
    if (st.contains(1)) cout << 1 << endl;
    else cout << -1 << endl;
    return;
  }
  if (n == 2) {
    if (st.contains(1)) cout << 1 << " ";
    else cout << -1 << " ";
    if (st.contains(2)) cout << 1 << endl;
    else cout << -1 << endl;
    return;
  }
  if (st.contains(1)) cout << 1 << " ";
  else cout << -1 << " ";
  if (st.contains(2)) cout << 1 << " ";
  else cout << -1 << " ";

  for (int i = 3; i <= n; i++) {
    ll temp = rec(i);
    cout << (temp == M ? -1 : temp) << " ";
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
