#include "validate.h"
#include <vector>
using namespace std;

#define rep(i, b) for(int i = 0; i < (b); i++)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<ll> vi;

const string ALLOWED_CHARS = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";

int main(int argc, char **argv) {
    init_io(argc, argv);

    int n, k;
    judge_in >> n >> k;

    vector<string> tokens(k);
    for (auto& t : tokens) judge_in >> t;
    
    auto check = [&](istream& sol, feedback_function feedback) {
        vector<string> lines;
        string line;
        while (getline(sol, line)) lines.push_back(line);
        vector<string> out_tokens;
        int penalty = 0;
        for (string line : lines) {
            if (sz(line) > n) feedback("Output line too long");
            if (sz(line) == 0) continue;
            if (line[0] == ' ' || line.back() == ' ') feedback("Output line has leading or trailing space");
            penalty = max(penalty, n - sz(line));

            string curr_part;
            for (char c : line) {
                if (c == ' ') {
                    if (curr_part.empty()) feedback("Output line has consecutive spaces");
                    out_tokens.push_back(curr_part);
                    curr_part = "";
                } else {
                    if (ALLOWED_CHARS.find(c) == string::npos) feedback("Output contains invalid character");
                    curr_part.push_back(c);
                }
            }
            assert(!curr_part.empty());
            out_tokens.push_back(curr_part);
        }
        if (out_tokens.size() != k) feedback("Expected %d lines of output, got %d", k, (int)out_tokens.size());
        if (out_tokens != tokens) feedback("Output lines do not match input lines");
        return penalty;
    };

    int judge_score = check(judge_ans, judge_error);
    int author_score = check(author_out, wrong_answer);

    if (author_score < judge_score) judge_error("Author solution provides better score");
    if (author_score > judge_score) wrong_answer("Author solution provides suboptimal score");
    accept();
}
