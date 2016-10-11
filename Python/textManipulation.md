import numpy

keys = numpy.genfromtxt('MIFAREKeys.txt', comments='#', dtype=str)

for i in range(len(keys)):
	print '{0x' + keys[i][0:2] + ', 0x' + keys[i][2:4] + ', 0x' + keys[i][4:6] + ', 0x' + keys[i][6:8] + ', 0x' + keys[i][8:10] + ', 0x' + keys[i][10:12] + '},'
