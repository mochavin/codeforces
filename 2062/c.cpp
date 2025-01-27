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
  int n; cin >> n;
  vector<ll> v(n);
  ll sum = 0;
  loop(i, n) {
    cin >> v[i];
    sum += v[i];
  }
  if (n == 1) {
    cout << v[0] << endl;
    return;
  }

  vector<vector<ll>> vv;
  loop(i, n - 1) {
    vector<ll> temp;
    ll last = (i == 0 ? n : vv[i - 1].size());
    loop(j, last) {
      if (j) {
        if (i == 0) temp.push_back(v[j] - v[j - 1]);
        else temp.push_back(vv[i - 1][j] - vv[i - 1][j - 1]);
      }
    }
    vv.push_back(temp);
  }

  // cek all of the length vv 
  loop(i, vv.size()) {
    ll temp1 = 0, temp2 = 0;
    loop(j, vv[i].size()) {
      temp1 += vv[i][j];
      temp2 -= vv[i][j];
      // cout << vv[i][j] << " ";
    }
    sum = max(sum, temp1);
    sum = max(sum, temp2);
    // cout << sum << " ";
    // cout << endl;
  }
  cout << sum << endl;

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
