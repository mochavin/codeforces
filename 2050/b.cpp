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

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n);
  ll sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
  loop(i, n) {
    cin >> v[i];
    if (i % 2) sum2 += v[i], cnt2++;
    else sum1 += v[i], cnt1++;
  }
  if ((sum1 + sum2) % n != 0) {
    cout << "NO" << endl; return;
  }
  ll target = (sum1 + sum2) / n;

  if (sum1 % target != 0 || sum1 / cnt1 != target) {
    cout << "NO" << endl; return;
  }
  if (sum2 % target != 0 || sum2 / cnt2 != target) {
    cout << "NO" << endl; return;
  }

  cout << "YES" << endl;
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
