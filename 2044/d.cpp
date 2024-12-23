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
  int n; cin >> n;
  vector<int> dah(n+1, 0);
  queue<int> qu;
  loop(i,n) qu.push(i+1);
  int ptr = 0;
  loop(i, n) {
    int temp; cin >> temp;
    ptr = temp;
    if(dah[ptr] != 0) {
      while(dah[qu.front()] != 0) {
        qu.pop();
      }
      ptr = qu.front();
    }
    dah[ptr] = 1;
    cout << ptr << " ";
  }
  cout << endl;
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
