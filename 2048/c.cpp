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
  string s; cin >> s;
  cout << 1 << " " << s.length() << " ";
  ll n = s.length();
  string s2 = "";
  ll first0 = -1;
  loop(i, n) {
    s2 += (s[i] == '1' ? '0' : '1');
    if (s[i] == '0' and first0 == -1) first0 = i;
  }
  if (first0 == -1) {
    cout << "1 1" << endl;
    return;
  }

  ll mx = 0, l = 0, c = 0;
  ll pan = n - first0;
  string target = s2.substr(first0, pan);
  // cout << target << endl;
  loop(i, pan) {
    if (target[i] == '1') c++;
    else break;
  }
  cout << max(1ll, first0 - c + 1) << " " << max(1ll, first0 - c + 1) + pan - 1 << endl;
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
