#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define ull unsigned long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
#define all(v) v.begin(), v.end()
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;

ull prexor(ull n) {
  if (n % 4 == 0) return n;
  else if (n % 4 == 1) return 1;
  else if (n % 4 == 2) return n + 1;
  return 0;
}

void solve()
{
  ull l, r, i, k;
  cin >> l >> r >> i >> k;
  ull ranlr = prexor(r) ^ prexor(l - 1);
  ull hi = ((prexor((r - k) >> i)) ^ prexor(((l - k + (1 << i) - 1) >> i) - 1LL));
  hi <<= i;
  ull lo = k * (((r - k) / (1LL << i) - (l - k - 1) / (1LL << i)) & 1);
  cout << (ranlr ^ hi ^ lo) << endl;
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
