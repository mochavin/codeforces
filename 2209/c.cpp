#include <bits/stdc++.h>
#define ll long long
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

  int in;
  for (int i = 1; i <= n - 1; i++) {
    cout << "? ";
    cout << 2 * i - 1 << " " << 2 * i << endl;
    cin >> in;
    if (in == 1) {
      cout << "! " << 2 * i << endl; return;
    }
  }

  cout << "? ";
  cout << "1 " << 2 * n - 1 << endl;
  cin >> in;
  if (in == 1) {
    cout << "! 1" << endl; return;
  }

  cout << "? ";
  cout << "2 " << 2 * n - 1 << endl;
  cin >> in;
  if (in == 1) cout << "! 2" << endl;
  else cout << "! " << 2 * n << endl;
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
