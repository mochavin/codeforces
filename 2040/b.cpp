#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
#define all(v) v.begin(), v.end()
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;



void solve()
{
  ll n; cin >> n;
  if (n == 1) {
    cout << 1 << endl; return;
  }
  else if (n <= 4) {
    cout << 2 << endl; return;
  }
  vector<ll> v;
  v.push_back(0);
  v.push_back(0);
  ll x = 4;
  while (x <= 1e8) {
    v.push_back(x);
    x = (x + 1) * 2;
  }
  cout << lower_bound(all(v), n) - v.begin() << endl;

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
