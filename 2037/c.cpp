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
vector<int> prime(N, 1);

void solve()
{
  ll n; cin >> n;
  // 2 4 6 1 3 5 7
  // 1 3 5 4 2 6
  // 1 3 2 4
  if (n >= 5) {
    for (int i = 1; i <= n; i += 2) {
      if (i == 5) continue;
      cout << i << " ";
    }
    cout << "5 4 ";
    for (int i = 2; i <= n; i += 2) {
      if (i == 4) continue;
      cout << i << " ";
    }
    cout << endl; return;
  }
  else {
    cout << -1 << endl;
  }
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  // precalc prime
  for (int i = 2; i * i < N; i++) {
    if (prime[i]) {
      for (int j = i * i; j < N; j += i) {
        prime[j] = 0;
      }
    }
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
