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
vector<ll> isprime(N, 1);

void solve()
{
  ll n; cin >> n;
  vector<ll> v(n + 1, 0);
  if (n <= 3) {
    if (n == 2) cout << "2 1" << endl;
    else cout << "2 1 3" << endl;
    return;
  }
  ll sq = n / 2;
  for (int l = sq, r = sq; l > 0 and r <= n; l--, r++) {
    if (isprime[l]) {
      sq = l; break;
    }
    if (isprime[r]) {
      sq = r; break;
    }
  }
  cout << sq << " ";
  v[sq] = 1;
  for (int l = sq - 1, r = sq + 1; l > 0 and r + 1 <= n; l--, r++) {
    cout << l << " " << r << " ";
    v[l] = 1, v[r] = 1;
  }
  loop1(i, n) {
    if (v[i] == 0) cout << i << " ";
  }

  cout << endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);

  isprime[1] = 0;
  for (int i = 2; i < N; i++) {
    for (int j = i * 2; j < N; j += i) {
      isprime[j] = 0;
    }
  }

  ll t; cin >> t;
  while (t--)
    solve();

  return 0;
}
