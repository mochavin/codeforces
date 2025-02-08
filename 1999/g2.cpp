#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 10;

int qu(int mid1, int mid2) {
  cout << "? " << mid1 << " " << mid2 << endl;
  // int ans = 570;
  int ans; cin >> ans;
  // if (mid1 >= ans) mid1++;
  // if (mid2 >= ans) mid2++;
  // return mid1 * mid2;

  return ans;
}

void solve()
{
  int l = 1, r = 999;
  while (l < r) {
    int third = (r - l) / 3;
    int m1 = l + third, m2 = r - third;
    int curr = qu(m1, m2);
    if (curr == -1) break;
    if (curr == (m1 + 1) * (m2 + 1)) {
      r = m1;
    }
    else if (curr == (m1) * (m2 + 1)) {
      r = m2;
      l = m1 + 1;
    }
    else {
      l = m2 + 1;
    }
  }
  cout << "! " << l << endl;
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
