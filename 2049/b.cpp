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
  string s; cin >> s;
  // ...s.... it means that 'p' not allowed after and before `s`
  // ...p.... it means that 's' not allowed after and before 'p'
  // when does 'yes' occur? when only 1 type of 's' or 'p'
  // when only the first char is 's' or last char is 'p' (1 char occurence)

  // count 'p' and 's'
  map<char, int> mp; // ps.
  loop(i, n) {
    mp[s[i]]++;
  }

  if (mp['p'] == 0 || mp['s'] == 0) {
    cout << "YES" << endl;
    return;
  }

  // it has atleast 1 'p' and 's'
  if ((mp['p'] == 1 and s[n - 1] == 'p') || (mp['s'] == 1 and s[0] == 's')) {
    cout << "YES" << endl;
    return;
  }

  // check whether 
  // int f = 0;
  // loop(i, n) {
  //   if (f && (s[i] != 'p')) {
  //     cout << "NO" << endl;
  //     return;
  //   }
  //   if (s[i] == 'p') f = 1;
  // }
  cout << "NO" << endl;
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
