#include <cstdio>

int binom(int n, int k) {
	if(k>n || k<0) return 0;
	if(n-k < k) k = n-k;
	int c = 1;
	for(int i = 1; i <= k; ++i)
		c = c*(n - i + 1) / (i);
	return c;
}

int main(){
	int n;
	scanf("%d", &n);
	int ans = 0;
	for(int i = 0; i <= 2; i++)
		for(int j = 0; j <= 3; j++){
			int left = n - i - j - 1;
			if(left < 0) continue;
			for(int k = 0; k <= left/2; k++){
				int items = left - k;
				ans += binom(items, k);
			}
		}
	printf("%d\n", ans);
}
