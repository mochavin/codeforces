#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

void solve()
{
  int a, b; cin >> a >> b;
  if (a % 2 == 0 and b % 2 == 0) {
    cout << "YES" << endl; return;
  }
  if (a % 2) {
    cout << "NO" << endl; return;
  }
  // b is odd and a is even
  if (a >= 2) {
    cout << "YES" << endl; return;
  }
  else {
    cout << "NO" << endl; return;
  }


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
