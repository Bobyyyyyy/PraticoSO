import os
import sys



def checkSubTree(directory):
	with os.scandir(directory) as it:
		for entry in it:
			if(entry.is_symlink()):
				stat = os.stat(entry.path)
				path = os.path.realpath(entry.path)
				path = os.path.basename(path)
				if path not in Dictionary:
					Dictionary[path] = list()
				Dictionary[path].append(entry.name)
			if(entry.is_dir()):
				checkSubTree(entry.name)


if __name__ == "__main__":

	if(len(sys.argv)!=2):
		print("Arg Error")
		exit()

	dir = sys.argv[1]

	Dictionary = {}

	if(os.path.exists(dir) and os.path.isdir(dir)):
		checkSubTree(dir)

	for k,v in Dictionary.items():
		print(k,"è puntato da ",v) 
