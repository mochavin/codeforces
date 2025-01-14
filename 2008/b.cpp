#include <bits/stdc++.h>
#include <iostream>
#define ll long long
#define endl '\n'
#define pb push_back
#define all(v) v.begin(), v.end()
#define loop(i, h) for (int i = 0; i < h; i++)
#define loop1(i, h) for (int i = 1; i <= h; i++)
using namespace std;
ll M = 1e9 + 7;
ll N = 2e5 + 1;



void solve()
{
  int n; cin >> n;
  string s; cin >> s;
  int sqr = sqrt(n);
  if (sqr * sqr != n) {
    cout << "No" << endl; return;
  }
  string cek1 = "", cek2 = "";
  loop(i, sqr) cek1 += '1';
  cek2 += '1';
  loop(i, sqr - 2)  cek2 += '0';
  cek2 += '1';

  loop(i, sqr) {
    if (i == 0 or i == sqr - 1) {
      if (s.substr(i * sqr, sqr) != cek1) {
        cout << "No" << endl; return;
      }
      continue;
    }
    if (s.substr(i * sqr, sqr) != cek2) {
      cout << "No" << endl; return;
    }
  }
  cout << "Yes" << endl; return;


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
