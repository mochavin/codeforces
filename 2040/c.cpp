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
ll N = 2e5 + 5;

void solve()
{
  ll n, k; cin >> n >> k;
  // ati ati bitwise terlalu gedhe, hmmmm :D
  if (n < 60 and k >(1LL << (n - 1))) {
    cout << -1 << endl;
    return;
  }
  if (n == 1) {
    cout << 1 << endl;
    return;
  }

  k--;
  vector<int> v;
  while (k) {
    if (k & 1) v.push_back(1);
    else v.push_back(0);
    k >>= 1;
  }

  while (v.size() < (n - 1)) v.push_back(0);
  reverse(v.begin(), v.end());
  // loop(i, v.size()) {
  //   cout << v[i] << " ";
  // }
  // cout << endl;
  vector<int> s(n, -1);
  for (int i = 0, l = 0, r = n - 1; i < n - 1; i++) {
    if (v[i] == 0) {
      s[l] = i + 1;
      l++;
    }
    else {
      s[r] = i + 1;
      r--;
    }
  }
  loop(i, n) if (s[i] == -1) s[i] = n;

  loop(i, n) {
    cout << s[i] << " ";
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
