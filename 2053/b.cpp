#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;



void solve()
{
  int n; cin >> n;
  vector<pair<int, int>> v(n + 1);
  map<pair<int, int>, int> mp;
  vector<int> ans(2 * n + 5, 0), pre(2 * n + 5, 0);
  loop1(i, n) {
    int l, r; cin >> l >> r;
    v[i] = { l , r };
    if (l == r) {
      mp[{l, r}] = (mp[{l, r}] != 0 ? -i : i);
      ans[l] = 1;
    }
  }
  loop1(i, 2 * n + 2) {
    pre[i] = pre[i - 1] + ans[i];
  }

  loop1(i, n) {
    int l = v[i].first, r = v[i].second, f = 0;
    if ((pre[r] - pre[l - 1] != r - l + 1) || mp[{l, l}] == i)
      cout << 1;
    else cout << 0;
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
