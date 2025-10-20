#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
#define pll pair<ll, ll>
using namespace std;
ll M = 998244353;
const ll N = 32;

pll dp[N][N * N];

void build() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N * N; j++) {
      dp[i][j] = pll(-1, -1);
    }
  }
  dp[0][0] = pll(0, 0);
  // i: panjang permut
  for (int i = 0; i < N; i++) {
    // j: total subseg increasing
    for (int j = 0; j < N * N; j++) {
      if (dp[i][j] != pll(-1, -1)) {
        // x : blok baru, jadi membentuk permut dg panjang i + x
        for (int x = 1; i + x < N; x++) {
          ll add = x * (x - 1) / 2;
          // backpointer
          if (j + add < N * N) dp[i + x][j + add] = pll(i, j);
        }
      }
    }
  }
}

void solve()
{
  ll n, k; cin >> n >> k;
  k = (n - 1) * n / 2 - k;
  if (dp[n][k] == pll(-1, -1)) {
    cout << 0 << endl; return;
  }

  vector<ll> ans;
  ll t = n;
  for (ll i = n, j = k; i > 0; tie(i, j) = dp[i][j]) {
    ll curBlockSize = i - dp[i][j].first;
    t -= curBlockSize;
    for (ll kk = t + 1; kk <= t + curBlockSize; kk++) ans.push_back(kk);
  }
  for (auto x : ans) cout << x << " ";
  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(0);
  build();
  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
