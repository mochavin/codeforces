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
ll M = 1e18 + 7;
ll N = 2e5 + 1;

void solve()
{
  ll n, l, r; cin >> n >> l >> r;
  vector<ll> v(n);
  loop(i, n) cin >> v[i];
  l--, r--;
  vector<ll> temp, temp2, inside;
  int f = 0;
  loop(i, n) {
    if (!(l <= i and i <= r)) {
      if (!f) temp.push_back(v[i]);
      else temp2.push_back(v[i]);
    }
    else {
      inside.push_back(v[i]);
      f = 1;
    }
  }
  sort(all(temp));
  sort(all(temp2));
  sort(all(inside));

  ll ans = M;

  ll curr1 = 0, curr2 = 0, sum = 0;
  // case 1: from left
  vector<ll> tampung = temp;
  loop(i, inside.size()) {
    tampung.push_back(inside[i]);
  }
  sort(all(tampung));
  loop(i, inside.size()) sum += tampung[i];


  ans = min(ans, sum);
  sum = 0, curr1 = 0, curr2 = 0;

  // case 2: from right
  tampung = temp2;
  loop(i, inside.size()) {
    tampung.push_back(inside[i]);
  }
  sort(all(tampung));
  loop(i, inside.size()) sum += tampung[i];
  ans = min(sum, ans);

  cout << ans << endl;

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
