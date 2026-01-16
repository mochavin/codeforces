#include <bits/stdc++.h>
#define ll long long
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 998244353;
ll N = 2e5 + 10;

void solve()
{
  int n; cin >> n;
  int sum = n * (n + 1) / 2;
  int len;
  cout << "2 1 " << n << endl;
  cin >> len;
  len = len - sum;
  int l = 1, r = n, cur = 0, cur2, ans = -1;
  while (l <= r) {
    int mid = r + (l - r + 1) / 2;
    // ori
    cout << "1 1 " << mid << endl;
    cin >> cur;
    // not ori
    cout << "2 1 " << mid << endl;
    cin >> cur2;
    // to find l, it should find the most left r
    if (cur == cur2) {
      l = mid + 1;
    }
    else {
      r = mid - 1;
      ans = mid;
    }
  }
  l = ans;
  cout << "! " << l << " " << l + len - 1 << endl;
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
