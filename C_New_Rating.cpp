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
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }

  vector<int> pre(n + 1);
  int curr = 0;
  for (int i = 1; i <= n; i++) {
    if (curr < v[i - 1]) curr++;
    else if (curr > v[i - 1]) curr--;
    pre[i] = max(pre[i - 1], curr);
  }


  auto cek = [&](int in) {
    int c = in;
    for (int i = n; i >= 1; i--) {
      if (pre[i - 1] >= c) return true;

      if (c > v[i - 1]) c++;
      else c--;
    }

    return false;
    };


  int l = 0, r = n;
  while (l < r) {
    int m = (l + r + 1) / 2;
    if (cek(m)) l = m;
    else r = m - 1;
  }

  cout << l << endl;
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
