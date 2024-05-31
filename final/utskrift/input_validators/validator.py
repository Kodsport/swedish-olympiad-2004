#!/usr/bin/python3
import re
import sys

int_pat = "(0|[1-9][0-9]*)"
line_1_re = "^" + int_pat + "$"

line = sys.stdin.readline()
assert re.match(line_1_re, line)
n = int(line)
assert 1 <= n <= 80

line = sys.stdin.readline()
assert re.match(line_1_re, line)
k = int(line)

for i in range(k):
	line = sys.stdin.readline()
	assert len(line) > 1

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
