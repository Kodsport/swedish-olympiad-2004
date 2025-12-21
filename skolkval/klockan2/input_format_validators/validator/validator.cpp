#include "validator.h"

void run() {
    int v = Int(0, 3959); Endl();
    Eof();
    assert(v % 5 == 0);
}
