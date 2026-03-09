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
  // 3 4 2 5 1 6
  // 4 3 5 2 6 1 7
  if (n & 1) {
    for (int hi = (n + 1) / 2, lo = n / 2; hi < n;) {
      cout << hi << " " << lo << " ";
      hi++; lo--;
    }
    cout << n << endl; return;
  }
  for (int lo = n / 2, hi = n / 2 + 1; hi <= n;) {
    cout << lo << " " << hi << " ";
    hi++; lo--;
  }
  cout << endl;
  // cout << n << endl;

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
