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
  ll n, d; cin >> n >> d;
  set<ll> ans;
  ans.insert(1);
  if (d == 5) ans.insert(5);
  if (n >= 3 || d % 3 == 0) ans.insert(3);
  if (n >= 3 || d == 7) ans.insert(7);
  if (n >= 6 || d == 9 || (n >= 3 and d % 3 == 0)) ans.insert(9);

  for (ll x : ans) cout << x << " ";
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
