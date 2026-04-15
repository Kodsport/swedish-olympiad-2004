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

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
mode = cmdlinearg('mode')


if mode=='random':
    k=randint(1, 1000)
elif mode=='max':
    k=1000
else:
    assert 0

n=randint(1, 80)
print(n)
print(k)

ALLOWED_CHARS = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~"

for i in range(k):
    print(''.join(random.choices(ALLOWED_CHARS, k=randint(1,min(n, 20)))))
