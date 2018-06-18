#!/usr/bin/python3

import csv
import random
import numpy

out = csv.writer(open("MirrorProfileForces.csv","w"), delimiter='\t', quoting=csv.QUOTE_NONE)
for i in range (1000):
    data = numpy.random.uniform(low=-100.0, high=100.0, size=(6,))
#    data = random.sample(range(-100.0, 100.0), 6)
    out.writerow(data)


