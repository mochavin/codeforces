#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 5;

void solve()
{
  string s; cin >> s;
  ll sum = 0;
  vector<ll> v(10, 0);
  loop(i, s.length()) {
    int digit = (int)(s[i] - '0');
    sum += digit;
    v[digit]++;
  }
  sum %= 9;
  // 2 -> 4
  // 3 -> 9

  loop(i, v[2] + 1) {
    loop(j, v[3] + 1) {
      if ((sum + 2 * i + 6 * j) % 9 == 0) {
        cout << "YES" << endl; return;
      }
    }
  }
  cout << "NO" << endl;



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
