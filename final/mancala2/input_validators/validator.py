#!/usr/bin/python3
import re
import sys

int_pat = "(0|[1-9][0-9]*)"
input_re = "^" + int_pat + " " + int_pat + " " + int_pat + " " + int_pat + " " + int_pat + "$"

line = sys.stdin.readline()
assert re.match(input_re, line)
line = sys.stdin.readline()
assert re.match(input_re, line)
line = sys.stdin.readline()
assert len(line) == 0
sys.exit(42)
