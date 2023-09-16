#!/usr/bin/env python3

n = int(input())

s=input()

vowel="AEIOUY"

swedish=[]

i=0
while i<n:
    swedish.append(s[i])
    if s[i] in vowel:
        i+=1
        continue
    i+=3    

for i in range(len(swedish)):
    if swedish[i] in vowel:
        print("FI"+"".join(swedish)+"KON")
        exit()

