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
  string s; cin >> s;
  int k = 0, idx = s.length();
  for (int i = s.length() - 1; i >= 0; i--) {
    if (s[i] == '0') k++;
    else break;
    idx = i;
  }

  loop(i, idx - 1) if (s[i] != '0') k++;

  cout << k << endl;

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
