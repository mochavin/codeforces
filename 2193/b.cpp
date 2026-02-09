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
  int it = 0, val = n;
  for (int i = 0; i < n; i++) {
    if (v[i] != n - i) {
      val = n - i;
      it = i; break;
    }
  }
  for (int i = it; i < n; i++) {
    if (v[i] == val) {
      reverse(v.begin() + it, v.begin() + i + 1);
      break;
    }
  }
  for (auto x : v) cout << x << " ";

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
