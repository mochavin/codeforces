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
  int hour = (s[0] - '0') * 10 + (s[1] - '0');
  int minute = (s[3] - '0') * 10 + (s[4] - '0');
  if (hour < 13) {
    if (hour == 0) {
      string newminute = to_string(minute);
      if (newminute.length() == 1) newminute = "0" + newminute;
      cout << "12:" << newminute << " AM";
    }
    else {
      if (hour == 12) {
        cout << s << " PM";
      }
      else {
        cout << s << " AM";
      }
    }
  }
  else {
    int newhour = hour - 12;
    string newhourstr = to_string(newhour);
    string newminute = to_string(minute);
    if (newminute.length() == 1) newminute = "0" + newminute;
    if (newhourstr.length() == 1) newhourstr = "0" + newhourstr;
    cout << newhourstr << ":" << newminute << " PM";
  }
  cout << endl;

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
