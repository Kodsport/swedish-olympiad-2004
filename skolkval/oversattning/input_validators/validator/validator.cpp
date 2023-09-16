#include "validator.h"

#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) // ignore
#define setcontains(set, x) (set.find(x) != set.end())
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

void run()
{
  int max_n = Arg("maxN", 30);
  string mode = Arg("mode", "none");
  int n = Int(1, max_n);
  Endl();
  set<char> vowels = {'A','E','I','O','U','Y'};
  string S = Line();
  if (mode == "vowel") {
          for (auto c: S) {
                  assert(vowels.find(c) != vowels.end());
          }
  }
  else {
          rep(i, 0, (int) S.size()) {
                  if (!setcontains(vowels, S[i])) {
                          assert(S[i+1] == 'O');
                          assert(S[i+2] == S[i]);
                          i += 2;
                  }
          }
  }
  Eof();
}
