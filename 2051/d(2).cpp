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
  ll n, x, y;
  cin >> n >> x >> y;
  ll sum = 0;
  vector<int> a(n);
  loop(i, n) cin >> a[i], sum += a[i];
  sort(a.begin(), a.end());

  ll sum1 = 0, sum2 = 0, ans = 0;
  for (int i = n - 1, j = 0; i > j; i--) {
    while ((j < i) && sum - a[i] - a[j] >= x) {
      j++;
    }
    sum1 += i - j;
  }


  for (int i = n - 1, j = 0; i > j; i--) {
    while ((j < i) && sum - a[i] - a[j] >= y + 1) {
      j++;
    }
    sum2 += i - j;
  }

  // loop(i, n)
  //   if (sum - a[i] - a[i] < y + 1) sum2--;

  // sum2 = sum2 / 2;

  cout << sum2 - sum1 << endl;

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
