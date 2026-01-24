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
  int n, a; cin >> n >> a;
  vector<int> v(n);
  int x = a - 1, y = a + 1;
  int res1 = 0, res2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    if (abs(v[i] - a) > abs(v[i] - x)) res1++;
    if (abs(v[i] - a) > abs(v[i] - y)) res2++;
  }
  cout << (res1 > res2 ? x : y) << endl;
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
