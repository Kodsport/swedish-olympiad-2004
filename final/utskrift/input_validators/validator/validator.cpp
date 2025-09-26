#include <bits/stdc++.h>
#include "validator.h"

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void run() {
	int n = Int(5, 80);
	Endl();
	int k = Int(1, 1000);
	Endl();

	rep(i,0,k) {
		string s = Line();
		assert(s.size() >= 1 && s.size() <= 20);
		assert(s.size() <= n);
		for (char c : s) {
			assert(isprint(c));
		}
	}
}
