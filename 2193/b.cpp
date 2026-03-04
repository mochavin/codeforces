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
  for (int i = 0; i < n; i++) cin >> v[i];

  int ls = -1;
  for (int i = 0; i < n; i++) {
    if (v[i] == n - i) {
      cout << v[i] << " ";
      ls = i;
      continue;
    }
    break;
  }
  int x = n;
  if (ls == -1) ls = -1;
  else x = v[ls] - 1;

  if (x == 0) {
    cout << endl; return;
  }

  int id = -1;
  for (int i = ls + 1; i < n; i++) {
    if (v[i] == x) {
      id = i; break;
    }
  }
  reverse(v.begin() + ls + 1, v.begin() + id + 1);
  for (int i = ls + 1; i < n; i++) cout << v[i] << " ";
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
