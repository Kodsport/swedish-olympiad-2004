#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int, int> E;

E e[10001];

int n, k, l;
bool knows[1001], ans[1001], exchange[1001][1001];

int main(){
        scanf("%d%d", &n, &k);
        for(int i = 1; i <= n; i++) exchange[i][i] = true;
        for(int i = 1; i <= k; i++) scanf("%d%d", &e[i].first, &e[i].second);
        scanf("%d", &l);
        for(int i = 0; i < l; i++){
                int x;
                scanf("%d", &x);
                knows[x] = true;
        }
        for(int i = k; i >= 1; i--){
                int a = e[i].first,  b = e[i].second;
                if(!knows[a] && !knows[b]) continue;
                bool ok = true;
                for(int j = 1; j <= n; j++){
                        exchange[a][j] = exchange[b][j] = exchange[a][j]|exchange[b][j];
                        ok &= (knows[j] == (exchange[a][j] || exchange[b][j]));
                }
                if(ok){
                        ans[a] = ans[b] = true;
                }
        }
        for(int i = 1; i <= n; i++) if(ans[i]) printf("%d ", i);
        printf("\n");
}

