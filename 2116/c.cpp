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
  ll n; cin >> n;
  vector<ll> v(n);
  map<ll, ll> mp;
  ll allgcd;
  loop(i, n) {
    cin >> v[i];
    mp[v[i]]++;
    if (i == 0) allgcd = v[i];
    else allgcd = gcd(v[i], allgcd);
  }
  // ans pasti faktor dari min(all(v))
  // target semua v[i] adalah gcd(all(v))
  if (mp[allgcd] > 0) {
    cout << n - mp[allgcd] << endl; return;
  }
  queue<ll> q;
  vector<ll> dp(5005, M);
  set<ll> st;
  loop(i, n) {
    v[i] /= allgcd;
    q.push(v[i]);
    dp[v[i]] = 0;
    st.insert(v[i]);
  }

  while (!q.empty()) {
    auto curr = q.front(); q.pop();
    for (auto x : st) {
      ll c = gcd(curr, x);
      if (dp[c] == M) {
        dp[c] = 1 + dp[curr];
        q.push(c);
      }
    }
    if (dp[1] != M) break;
  }
  cout << n + dp[1] - 1 << endl;
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
