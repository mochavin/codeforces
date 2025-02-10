#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 1;

void solve()
{
  ll n, m, k; cin >> n >> m >> k;
  if (abs(n - m) > k or (k > n and k > m)) {
    cout << -1 << endl; return;
  }
  ll sisa0 = n, sisa1 = m;
  if (n > m) {
    if ((n + m - k) % 2 == 1) {
      cout << "1";
      sisa1--;
    }
    loop(i, k) {
      cout << "0";
      sisa0--;
    }
    for (; sisa0 > 0 or sisa1 > 0;) {
      // cout << "10";
      if (sisa1) {
        cout << 1;
        sisa1--;
      }
      if (sisa0) {
        cout << 0;
        sisa0--;
      }
    }
    cout << endl; return;
  }
  else {
    if ((n + m - k) % 2 == 1) {
      cout << "0";
      sisa0--;
    }
    loop(i, k) {
      cout << "1";
      sisa1--;
    }
    // cout << sisa1 << " ";
    for (; sisa0 > 0 or sisa1 > 0;) {
      // cout << "01";
      if (sisa0) {
        cout << 0;
        sisa0--;
      }
      if (sisa1) {
        cout << 1;
        sisa1--;
      }
    }
    cout << endl; return;
  }
  cout << -1 << endl;


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
