#!/usr/bin/python3
import re
import sys

int_pat = "(0|[1-9][0-9]*)"
line_1_re = "^" + int_pat + "$"

line = sys.stdin.readline()
assert re.match(line_1_re, line)
n = int(line)

line = sys.stdin.readline()
assert re.match(line_1_re, line)

line = sys.stdin.readline()
assert len(line) == n+1
assert re.match("^[A-Z]*$",line)

line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
