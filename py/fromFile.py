import numpy as np
import cv2
import re
import sys

args = sys.argv[1:]
txtFileName = args[0]

line = open(txtFileName).readline()
str = line.rstrip()
size = list(map(int, re.findall('\d+', str)))
b = np.zeros((size[0], size[1]), np.uint8)
g = np.zeros((size[0], size[1]), np.uint8)
r = np.zeros((size[0], size[1]), np.uint8)

lineCounter = 0

with open(txtFileName) as fp:
	for line in fp:
		str = line.rstrip()
		lineCounter += 1
		if lineCounter != 1 :
			values = list(map(int, re.findall('\d+', str)))
			b[values[0], values[1]] = values[2]
			g[values[0], values[1]] = values[3]
			r[values[0], values[1]] = values[4]
img = cv2.merge((b, g, r))
cv2.imshow('Created image', img)
cv2.waitKey()