#include "validator.h"

const string ALLOWED_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

void run() {
	int n = Int(1, 80);
	Endl();
	int k = Int(1, 1000);
	Endl();

	for (int i = 0; i < k; i++) {
		string s = Line();
		assert(s.size() >= 1 && s.size() <= 20);
		assert(s.size() <= n);
		for (char c : s) {
			assert(ALLOWED_CHARS.find(c) != string::npos);
		}
	}
}
