import sys
import string
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None, name
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('N', 30))
mode = cmdlinearg('mode',"none")

letters = [chr(x) for x in range(65, 91)]
vowels = ['A', 'E', 'I', 'O', 'U', 'Y']
consonants = [] 
for l in letters:
    if l not in vowels:
        consonants.append(l)

consonant = vowel = 0
while vowel == 0:
    consonant = random.randint(0, n//3)
    vowel = n - 3*consonant

rovar = []

while max(consonant, vowel) > 0:
    choice = random.randint(0, 1)
    if choice == 0 and vowel > 0:
        rovar.append(random.choice(vowels))
        vowel -= 1
    elif choice == 1 and consonant > 0:
        rovar.append(random.choice(consonants))
        rovar.append('O')
        rovar.append(rovar[-2])
        consonant -= 1

if mode == "vowel":
    for i in range(len(rovar)):
        rovar[i] = random.choice(vowels)
elif mode != "none":
    assert(False)

print("".join([str(x) for x in rovar]))
