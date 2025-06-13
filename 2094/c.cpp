#include <bits/stdc++.h>
#include <iostream>
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
  vector<ll> v(2 * n + 1, 0);
  vector<ll> dah(2 * n + 1, 1);
  loop1(i, n) {
    loop1(j, n) {
      ll temp;
      cin >> temp;
      v[i + j] = temp;
      dah[temp] = 0;
    }
  }
  ll f = 0;
  loop1(i, 2 * n) {
    if (dah[i]) {
      cout << i << " "; f = i;
      break;
    }
  }
  loop1(i, 2 * n) {
    if (v[i]) cout << v[i] << " ";
  }
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
