#!/usr/bin/python3

import csv
import random

out = csv.writer(open("MirrorProfileForces.csv","w"), delimiter='\t',quoting=csv.QUOTE_NONE)
for i in range (1000):
    data = random.sample(range(-100, 100), 6)
    out.writerow(data)


