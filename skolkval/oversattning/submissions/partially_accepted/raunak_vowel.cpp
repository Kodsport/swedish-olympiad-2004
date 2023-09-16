#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)

int main() {
        int n; 
        string s;
        cin >> n >>  s;
        string one = "", two = ""; 
        set<char> vokal = {'A','E','I','O','U','Y'};
        bool vokalHittad = 0;
        rep(i, 0, (int) s.size()) {
                if (vokalHittad) {
                        two += s[i];
                }
                else one += s[i];
                if (vokal.find(s[i]) != vokal.end()) {
                        vokalHittad = 1;
                }
        }
        cout << "FI" << two << one << "KON" << "\n";
}
