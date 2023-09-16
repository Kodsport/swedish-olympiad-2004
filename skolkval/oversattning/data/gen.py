import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('N', 30))
n //= 3
mode = cmdlinearg('mode',"none")

vowels = [65, 69, 73, 79, 85, 89]
a = [chr(random.randint(65,90)) for i in range(n+1)]
a[random.randint(0, n)] = chr(random.choice(vowels))

rovar = []

vowelChars = ['A', 'E', 'I', 'O', 'U', 'Y']
for x in a:
    rovar.append(x)
    if x not in vowelChars:
        rovar.append('O')
        rovar.append(x)

if mode=="vowel":
    for i in range(len(rovar)):
        rovar[i] = chr(random.choice(vowels))

print(len(rovar))
print("".join([str(x) for x in rovar]))
