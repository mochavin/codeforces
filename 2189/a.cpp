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
  int n, w, h; cin >> n >> w >> h;
  if (w < h) swap(w, h);
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int in; cin >> in;
    if (in <= w) v.push_back(in);
  }
  sort(v.begin(), v.end());
  n = v.size();
  int ans = 0;
  for (int r = n - 1, l = 0; l < r;) {
    if (v[l] > h) break;
    ans++;
    l++, r--;
  }
  cout << ans << endl;
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
