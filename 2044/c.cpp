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
  int m, a, b, c; 
  cin >> m >> a >> b >> c;
  int sisa1 = m, sisa2 = m;
  sisa1 -= min(m, a);
  sisa2 -= min(m, b);
  int total = min(sisa1 + sisa2, c);
  int ans = min(m, a) + min(m, b) + total;
  cout << ans << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll t; cin>>t;
  while(t--)
  solve();

  return 0;
}
