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
  string s; cin >> s;
  if (n == 1) {
    cout << (s[0] == '0' ? 0 : 1) << endl; return;
  }
  vector<ll> presum1(n + 1, 0), presum2(n + 1, 0);
  ll ans1 = 0, ans2 = 0;
  // pre1[0] = 0, pre2[0] = n - 1;
  presum1[0] = 0, presum2[0] = s[0] == '0' ? n - 1 : 1;
  loop1(i, n - 1) {
    if (s[i] == '0') {
      // case 1: 00
      if (s[i - 1] == '0') {
        presum1[i] = presum1[i - 1] + i;
        presum2[i] = presum2[i - 1] + n - i - 1;
      }
      // case 2: 10
      if (s[i - 1] == '1') {
        presum1[i] = presum2[i - 1] + i;
        presum2[i] = n - i - 1;
      }
    }
    else {
      // case 3: 01
      if (s[i - 1] == '0') {
        presum1[i] = 0;
        presum2[i] = presum2[i - 1] + 1;
      }
      // case 4: 11
      if (s[i - 1] == '1') {
        presum1[i] = 0;
        presum2[i] = 1;
      }
    }
    ans1 = max(ans1, presum1[i]);
    ans2 = max(ans2, presum2[i]);
    // cout << pre1[i] << " " << pre2[i] << endl;
  }
  cout << max(ans1, ans2) << endl;
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
