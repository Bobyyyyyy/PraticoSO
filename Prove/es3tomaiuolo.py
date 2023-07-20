import os
import sys



def subTree(directory):
	with os.scandir(directory) as it:
		for entry in it:
			if(entry.is_file()):
				if not entry.name.isascii():
					print(entry.name)
			if(entry.is_dir()):
				if not entry.name.isascii():
					print(entry.name)
				subTree(entry.path)



if __name__ == "__main__":

	if(len(sys.argv) != 2):
		print("arg error")
		exit();

	subTree(sys.argv[1]);

	exit()



