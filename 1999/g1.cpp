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

int qu(int mid) {
  cout << "? " << 1 << " " << mid << endl;
  // int ans = 4;
  int ans; cin >> ans;
  // if (mid >= ans) return mid + 1;
  return ans;
}

void solve()
{
  int l = 1, r = 999;
  while (l < r) {
    int mid = (l + r) / 2;
    int curr = qu(mid);
    if (curr == -1) break;
    if (curr > mid) {
      r = mid;
    }
    else {
      l = mid + 1;
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
