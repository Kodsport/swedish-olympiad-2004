#include <cstdio>
#include <set>
#include <map>
#include <vector>

using namespace std;

#define P 25165843

int n, v;
char b[10100];
vector<int> vowels;

bool isvowel(char c){
	return c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y';
}

typedef unsigned int Hash;
vector<Hash> pow(10001, 1);
map<Hash, set<Hash> > words;

int start = 0;
int len = 0;
Hash h = 0;

void rem(){
	h -= pow[--len] * b[start++];
}

void add(){
	h = h * P + b[start+(len++)];
}

int main(){
	for(int i = 1; i < 10001; i++) pow[i] = pow[i-1] * P;
	scanf("%d%d%s", &n, &v, b);
	for(int i = 0; i < n; i++) if(isvowel(b[i])) vowels.push_back(i);
	for(int i = v - 1; i < vowels.size(); i++){
		for(int j = start + len; j <= vowels[i]; j++) add();
		vector<Hash> hashes;
		int mid = vowels[i - (v - 1)];
		int end = vowels[i];
		for(int j = start; j < mid; j++){
			hashes.push_back(h);
			rem();
		}
		hashes.push_back(h);
		for(int j = 0; j < hashes.size(); j++) words[h].insert(hashes[j]);
		rem();
	}

	int best = 0;
	for(map<Hash, set<Hash> >::iterator it = words.begin(); it != words.end(); ++it) if(it->second.size() > best) best = it->second.size();
	printf("%d\n", best);
}
