#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
        int n;
        string s, svenska = ""; 
        cin >> n >> s;
        set<char> vokal = {'A', 'E', 'I', 'O', 'U', 'Y'};
        rep(i, 0, (int) s.size()) {
                svenska += s[i];
                if (vokal.find(s[i]) == vokal.end()) {
                        i += 2;
                }
        }
        string one = "", two = ""; 
        bool vokalHittad = 0;
        rep(i, 0, (int) svenska.size()) {
                if (vokalHittad) {
                        two += svenska[i];
                }
                else one += svenska[i];
                if (vokal.find(svenska[i]) != vokal.end()) {
                        vokalHittad = 1;
                }
        }
        cout << "FI" << two << one << "KON" << "\n";
}

