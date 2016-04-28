#!/usr/local/bin/python3
from collections import Counter

def isGoodWord(word):
    isOdd = len(word) % 2
    return Counter(word[:len(word)//2]) == Counter(word[len(word)//2 + isOdd:])

words = []
for _ in range(int(input())):
    words.append(input())

for w in words:
    if isGoodWord(w):
        print("YES")
    else:
        print("NO")
