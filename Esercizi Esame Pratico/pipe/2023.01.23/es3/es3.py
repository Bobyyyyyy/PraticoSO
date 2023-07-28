import os
import sys
import shutil

if __name__ == "__main__":

	if(len(sys.argv) != 5):
		print("invalid argument")
		exit()

	directoryA = sys.argv[1]
	directoryB = sys.argv[2]

	os.mkdir(os.path.join(os.getcwd(),sys.argv[3]))
	os.mkdir(os.path.join(os.getcwd(),sys.argv[4]))

	for file1 in os.scandir(directoryA):
		if(file1.is_file()):
			for file2 in os.scandir(directoryB):
				if(file2.is_file()):
					if(file1.name == file2.name): 
						newFile = os.path.join(sys.argv[3],file1.name)
						shutil.copyfile(file1,newFile)
						newFile2 = os.path.join(sys.argv[4],file2.name)
						shutil.copyfile(file2,newFile2)


	exit()
