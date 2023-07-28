import os
import sys
if __name__ == "__main__":
	if(len(sys.argv) != 2): 
		print("invalid argument")
		exit()
	directory = sys.argv[1];
	FileList = []
	for l in os.scandir(directory):
		if(l.is_file()):
			FileList.append(l)
	print(FileList[:])
	RowSum = []
	for f in FileList: 
		index = 0
		with open(f,"r") as file:
			for line in list(file):
				try:
					RowSum[index] += len(line)
				except IndexError:
					RowSum.append(len(line))
				index += 1
	for i in range(len(RowSum)):
		print(i+1, RowSum[i])
	exit()
