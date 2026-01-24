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
  vector<int> ans(n);
  ans[0] = n; ans[n - 1] = 1;
  for (int i = 1; i < n - 1; i += 2) {
    ans[i] = i + 1 + 1;
    if (i + 1 < n - 1) ans[i + 1] = i + 1;
  }
  if (n % 2) {
    ans[0] = n - 1;
    ans[n - 2] = n;
  }
  for (auto x : ans) {
    cout << x << " ";
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
