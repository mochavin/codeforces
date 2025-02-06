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
  string s1, s2; cin >> s1 >> s2;
  ll n = s1.length(), m = s2.length();
  ll idx = 0;
  int i = 0, j = 0;
  for (; i < n and j < m;) {
    if (s1[i] == s2[j] or s1[i] == '?') {
      s1[i] = s2[j];
      i++, j++;
    }
    else {
      i++;
    }
  }

  if (j != m) {
    cout << "NO" << endl;
  }
  else {
    cout << "YES" << endl;
    loop(i, n) {
      cout << (s1[i] == '?' ? 'x' : s1[i]);
    }
    cout << endl;
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
