#!/usr/bin/env python3

s=input()

n=len(s)

vowel="AEIOUY"

swedish=[*s]


for i in range(len(swedish)):
    if swedish[i] in vowel:
        print("FI"+"".join(swedish[i+1:])+"".join(swedish[:i+1])+"KON")
        exit()

