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
  int n, k; cin >> n >> k;
  vector<int> v(n);
  loop(i, n) {
    cin >> v[i];
  }
  loop(i, n) {
    int f = 1;
    loop(j, n) {
      if (j == i) continue;
      if (abs(v[i] - v[j]) % k == 0) {
        f = 0;
      }
    }
    if (f) {
      cout << "YES" << endl;
      cout << i + 1 << endl;
      return;
    }
  }
  cout << "NO" << endl;
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
