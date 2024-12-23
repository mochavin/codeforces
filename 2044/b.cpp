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

void solve()
{
  string s; cin >> s;
  int len = s.length();
  for(int i = len-1; i >= 0; i--) {
    if(s[i] == 'q') cout << 'p';
    else if(s[i] == 'p') cout << 'q';
    else cout << 'w';
  }
  cout <<endl;
}

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  ll t; cin>>t;
  while(t--)
  solve();

  return 0;
}
