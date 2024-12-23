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

void solve() {
  cout << "---" << endl;
  ll n, x, y;
  cin >> n >> x >> y;
  ll sum = 0;
  vector<int> a(n);
  loop(i, n) cin >> a[i], sum += a[i];
  sort(a.begin(), a.end());

  // objective: find pair count st. x <= sum - a[p] - a[q] <= y
  cout << sum << endl;
  loop(i, n) cout << a[i] << " ";
  cout << endl;
  ll ans = 0;
  loop(i, n) {
    if (i == n - 1) break;
    ll temp = sum - a[i];
    // find q st. a[q] <= temp - y
    auto low = lower_bound(a.begin() + i + 1, a.end(), temp - y);

    // High end: find first j where a[j] > temp - x
    auto high = upper_bound(a.begin() + i + 1, a.end(), temp - x);

    ans += high - low;
    cout << low - a.begin() << " " << high - a.begin() << endl;
  }


  cout << ans << endl;


  return;

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
