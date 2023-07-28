import os
import sys
if __name__ == "__main__":
	Directories = []
	magicnumber = b'\x7fELF'
	if(len(sys.argv) == 1):
		Directories.append(os.getcwd())
	else:
		for i in range(1,len(sys.argv)):
			if(os.path.exists(sys.argv[i])):
 				Directories.append(sys.argv[i])
	fullsize = 0
	print(Directories)

	for dir in Directories:
		with os.scandir(dir) as it:
			for entry in it:
				if(entry.is_file()):
					with open(entry,'rb') as f:
						if(f.read(4) == magicnumber):
							fullsize += os.stat(entry).st_size
	print(fullsize)
	exit()
