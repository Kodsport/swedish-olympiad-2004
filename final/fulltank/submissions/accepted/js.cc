#include <cstdio>
#include <cassert>
#include <vector>

using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	vector<bool> ok(1501, true);
	for(int i = 0; i < n; i++){
		int vol, pris;
		scanf("%d%d", &vol, &pris);
		for(int j = 600; j <= 1500; j++){
			int ppris = (vol * j + 500)/1000;
			if(ppris != pris/10) ok[j] = false;
		}
	}
	int ans = -1;
	int s;
	scanf("%d", &s);
	for(int i = 600; i <= 1500; i++){
		if(ok[i]){
			int aans = (i * s + 500)/1000;
			if(ans != -1 && ans != aans){
				assert(false && "multiple answers");
			}
			ans = aans;
		}
	}
	printf("%d\n", ans*10);
}
