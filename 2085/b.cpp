#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
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
  vector<ll> a(n);
  vector<ll> pr;
  loop(i, n) {
    cin >> a[i];
    if (a[i] == 0) {
      pr.push_back(i);
    }

  }
  if (pr.size() == 0) {
    cout << 1 << endl;
    cout << 1 << " " << n << endl; return;
  }
  if (pr.size() == 1) {
    cout << 2 << endl;
    if (pr[0] != n - 1) {
      cout << pr[0] + 1 << " " << pr[0] + 2 << endl;
    }
    else {
      cout << n - 1 << " " << n << endl;
    }
    cout << "1 " << n - 1 << endl;
    return;
  }

  if (!(pr[0] == 0 and pr.back() == n - 1)) {
    cout << 2 << endl;
    ll krg = n - (pr.back() - pr[0]);
    cout << pr[0] + 1 << " " << pr.back() + 1 << endl;
    cout << "1 " << krg << endl;
    return;
  }
  else {
    cout << 3 << endl;
    cout << n - 1 << " " << n << endl;
    cout << "1 " << n - 2 << endl;
    cout << "1 2" << endl;
    return;
  }

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
