#!/usr/bin/python3

import sys
import random
from random import randint

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    if default is None:
        print("missing parameter", name)
        sys.exit(1)
    return default

#random.seed(int(cmdlinearg('seed', sys.argv[-1])))

k=randint(5, 80)
print(k)
n=1000
print(n)
for i in range(n):
    print(''.join('a'*randint(1,min(k, 20))))
