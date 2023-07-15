import os
import sys
import pprint

def subTree(directory):
	with os.scandir(directory) as it:
		for entry in it:
			if(entry.is_file()):
				if entry.name not in Dictionary:
					Dictionary[entry.name] = list()
				Dictionary[entry.name].append(directory)
			if(entry.is_dir()):
				subTree(entry.name)



if __name__=="__main__":

	if(len(sys.argv) != 2):
		print("errore");
		exit()

	Dictionary = {}

	directory = sys.argv[1]

	if(os.path.exists(directory) and os.path.isdir(directory)):
		subTree(directory)
		Dictionary = dict(sorted(Dictionary.items()))
		pprint.pprint(Dictionary)
	else:
		print("Not a directory")
	exit()


