/* @EXPECTED_SCORE@:5 */
#include <cstdio>
#include <cstdlib>
#include <set>
#include <map>
#include <vector>

using namespace std;

bool forbidden[13][13];

vector<bool> used(13);

vector<int> ans;

void recurse(int dice, int placed, int lastNow, int lastPrev){
	if(dice == 3){
		for(int i = 0; i < 12; i++) printf("%d ", ans[i]);
		printf("\n");
		exit(0);
	}
	if(placed == 4){
		recurse(dice+1, 0, 0, lastPrev);
		return;
	}
	for(int i = (placed == 0 ? lastPrev : lastNow) + 1; i <= 12; i++){
		if(used[i]) continue;
		bool ok = true;
		for(int j = dice*4; j < dice*4+placed; j++) if(forbidden[ans[j]][i]) ok = false;
		if(!ok) continue;

		used[i] = true;
		ans.push_back(i);

		recurse(dice, placed+1, i, placed == 0 ? i : lastPrev);

		ans.pop_back();
		used[i] = false;
	}
}

int main(){
	for(int i = 0; i < 20; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		forbidden[a][b] = forbidden[b][a] = true;
		forbidden[a][c] = forbidden[c][a] = true;
		forbidden[b][c] = forbidden[c][b] = true;
	}
	recurse(0, 0, 0, 0);
}
