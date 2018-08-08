from __future__ import print_function
import numpy as np
import cv2
import sys

args = sys.argv[1:]
imageName = args[0]
txtFileName = args[1]
	

img = cv2.imread(imageName, 1)
print (type(img))
image_data = np.asarray(img)
b, g, r = cv2.split(image_data)

f = open(txtFileName, 'w')
print ('{} , {} '.format(len(image_data), len(image_data[0])), file=f)

for i in range(len(image_data)):
	for j in range(len(image_data[0])):
		print ('[ {} , {} ] = [ {} , {} , {} ]'.format(i, j, b[i,j], g[i,j], r[i,j]), file=f)

