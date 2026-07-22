/* @EXPECTED_SCORE@:5 */
#include <cstdio>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

int n, k;

vector<string> lines;

int best[1001], nxt[1001]; //Bästa diffen om vi börjar en ny rad på [i]

int dp(int at){
	if(best[at] != 1001) return best[at];
	if(at == k) return 0;
	int len = -1;
	for(int i = at; len < 120 && i < k; i++){
		len += lines[i].size() + 1;
		int diff = max((int)abs(len - n), dp(i+1));
		if(diff < best[at]){
			best[at] = diff;
			nxt[at] = i+1;
		}
	}
	return best[at];
}

int main(){
	cin >> n >> k;
	lines.resize(k);
	for(int i = 0; i < k; i++) cin >> lines[i];
	for(int i = 0; i < k; i++) best[i] = 1001;
	int at = 0;
	dp(0);
	while(at != k){
		int nx = nxt[at];
		cout << lines[at];
		for(int i = at + 1; i < nx; i++){
			cout << ' ' << lines[i];
		}
		cout << endl;
		at = nx;
	}
}
