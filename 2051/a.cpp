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
  int n; cin >> n;
  vector<int> a(n), b(n);
  loop(i, n) {
    cin >> a[i];
  }
  int total = 0;
  loop(i, n) {
    cin >> b[i];
    if (i > 0)
      total += max(a[i - 1] - b[i], 0);
  }
  cout << total + a[n - 1] << endl;
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
