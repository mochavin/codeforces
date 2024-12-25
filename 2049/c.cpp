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

int mex(vector<ll>& arr) {
  bool zero = false, one = false, two = false;
  for (int x : arr) {
    if (x == 0) zero = true;
    else if (x == 1) one = true;
    else if (x == 2) two = true;
  }
  if (!zero) return 0;
  if (!one) return 1;
  if (!two) return 2;
  return 3;
}

void solve() {
  ll n, x, y; cin >> n >> x >> y;

  // 0 1 2 0 2 1 --- 2,4
  // 5 5 5 5 5 5
  // 0 1 0 2 0 1
  vector<ll> v(n);
  loop(i, n) v[i] = 5;
  loop(i, n) {
    if (i == x - 1) {
      vector<ll> temp = { v[(i - 1 + n) % n], v[(i + 1 + n) % n], v[y - 1] };
      v[i] = mex(temp);
    }
    else
      if (i == y - 1) {
        vector<ll> temp = { v[(i - 1 + n) % n], v[(i + 1 + n) % n], v[x - 1] };
        v[i] = mex(temp);
      }
      else {
        vector<ll> temp = { v[(i - 1 + n) % n], v[(i + 1 + n) % n] };
        v[i] = mex(temp);
      }
  }

  loop(i, n)   cout << v[i] << " ";
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
