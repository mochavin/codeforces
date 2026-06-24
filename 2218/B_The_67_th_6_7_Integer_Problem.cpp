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
  vector<int> v(7);
  int sum = 0;
  for (int i = 0; i < 7; i++) {
    cin >> v[i];
    v[i] *= -1;
    sum += v[i];
    v[i] *= -1;
  }
  int ans = INT_MIN;
  for (int i = 0; i < 7; i++) {
    // hanya i yang gak negate
    ans = max(ans, sum + (v[i] > 0 ? 2 * v[i] : 2 * v[i]));
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
