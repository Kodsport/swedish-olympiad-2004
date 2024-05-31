#!/usr/bin/python3
import re
import sys

int_pat = "(0|[1-9][0-9]*)"
line_1_re = "^" + int_pat + " " + int_pat + "$"
line_2_re = "^" + int_pat + "$"
line_3_re = "^" + int_pat + "( (0|[1-9][0-9]*))*$"

line = sys.stdin.readline()
assert re.match(line_1_re, line)
v, e = [int(x) for x in line.split()]
for i in range(e):
	line = sys.stdin.readline()
	assert re.match(line_1_re, line)
	a, b = [int(x) for x in line.split()]
	assert 1 <= a <= v and 1 <= b <= v

line = sys.stdin.readline()
assert re.match(line_2_re, line)

n = int(line)
line = sys.stdin.readline()
assert re.match(line_3_re, line)
assert len([int(x) for x in line.split()]) == n

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
