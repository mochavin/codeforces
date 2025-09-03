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
  vector<ll> v(n + 1);
  loop1(i, n) {
    cin >> v[i];
  }
  vector<ll> dp(n + 1, 0);
  // mx(dp[i-1], )
  unordered_map<ll, queue<ll>> buff;
  loop1(i, n) {
    queue<ll>* x = &buff[v[i]];
    x->push(i);

    if (x->size() >= v[i]) {
      if (dp[x->front() - 1] + v[i] > dp[i - 1]) {
        dp[i] = dp[x->front() - 1] + v[i];
      }
      x->pop();
    }
    dp[i] = max(dp[i], dp[i - 1]);
    if (x->size() >= v[i]) x->pop();
  }
  // for (auto x : dp) cout << x << endl;
  cout << dp[n] << endl;
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
