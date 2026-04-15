#include <cstdio>
#include <queue>
#include <vector>
#include <map>

using namespace std;

vector<int> start(5);
vector<int> target(5);

map<vector<int>, int> dist;

int main(){
	for(int i = 0; i < 5; i++) scanf("%d", &start[i]);
	for(int i = 0; i < 5; i++) scanf("%d", &target[i]);

	queue< vector<int> > q;
	q.push(start);
	dist[start] = 0;
	while(!q.empty()){
		vector<int> nx = q.front(); q.pop();
		int mvs = dist[nx];
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 2; j++){
				vector<int> mv = nx;
				int l = mv[i];
				mv[i] = 0;
				for(int k = 0; k < l; k++){
					int p = k*(j ? 1 : -1) + i;
					mv[(p + 50)%5]++;
				}
				if(dist.find(mv) == dist.end()){
					if(mv == target){
						printf("%d\n", mvs+1);
						return 0;
					}
					dist[mv] = mvs + 1;
					q.push(mv);
				}
			}
		}
	}
}
