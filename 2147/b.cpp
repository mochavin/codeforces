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
  if (n == 1) {
    cout << "1 1" << endl; return;
  }
  else if (n == 2) {
    cout << "1 2 1 2" << endl; return;
  }
  else if (n == 3) {
    cout << "1 3 1 2 3 2" << endl; return;
  }
  cout << n - 1 << " " << n << " ";
  for (ll i = n - 2; i >= 1; i--) {
    cout << i << " ";
  }
  cout << n - 2 << " " << n << " ";
  for (ll i = 2; i <= n - 3; i++) {
    cout << i << " ";
  }
  cout << n - 1 << " ";
  cout << 1 << endl;

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
