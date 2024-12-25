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
  vector<ll> v(n);
  int f = 0;
  loop(i, n) {
    cin >> v[i];
    if (v[i] != 0) f = 1;
  }

  if (!f) {
    cout << 0 << endl;
    return;
  }
  f = 0;
  int ida = 0, idb = n - 1;
  for (int i = 0; i < n; i++) {
    if (v[i] != 0) {
      ida = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (v[i] != 0) {
      idb = i;
      break;
    }
  }

  for (; ida <= idb; ida++) {
    if (v[ida] == 0) {
      cout << 2 << endl;
      return;
    }
  }
  cout << 1 << endl;

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
