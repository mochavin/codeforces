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
  ll n, a, b, c; cin >> n >> a >> b >> c;
  ll total = a + b + c;
  ll ans = n / total; // sekali
  // total -= ans;
  ll sisa = n - ans * total; // sisa 3
  if (sisa - a - b >= 0) {
    cout << ans * 3 + 2 + ((sisa - a - b) % c != 0);
  }
  else if (sisa - a >= 0) {
    cout << ans * 3 + 1 + ((sisa - a) % b != 0);
  }
  else {
    cout << ans * 3 + ((sisa % a) != 0);
  }
  cout << endl;
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
