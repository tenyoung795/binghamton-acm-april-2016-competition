#!/usr/local/bin/python3
import math

def tupleFromInput():
    return tuple(map(float, input().split()))

def dist(p1, p2):
    xx, yy = (p2[0] - p1[0], p2[1] - p1[1])
    return math.sqrt(xx*xx + yy*yy)

cpos = tupleFromInput()
poslst = []
for _ in range(int(input())):
    poslst.append(tupleFromInput())

totalD = 0.0
while poslst:
    minD = float("inf")
    for i, pt in enumerate(poslst):
        curD = dist(pt, cpos)
        if curD < minD:
            minD = curD
            todel = i
    cpos = poslst[todel]
    totalD += minD

    del poslst[todel]

print("{0:.5f}".format(totalD))
