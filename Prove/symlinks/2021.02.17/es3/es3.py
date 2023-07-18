import os
import sys



def subTree(directory,pattern):
	with os.scandir(directory) as it:
		for entry in it:
			if(entry.is_file()):
				f = open(entry.path,"r");
				lines = f.readlines()
				for line in lines:
					if line.find(pattern) != -1:
						fileinfo = os.stat(entry.path);
						Dictionary[entry.name] = fileinfo.st_mtime



if __name__ == "__main__":
	if(len(sys.argv) != 2):
		print("Errore argomenti")

	Pattern = sys.argv[1];
	Dictionary = {}
	subTree(os.getcwd(),Pattern)

	Dictionary = sorted(Dictionary.items(), key= lambda x:x[1],reverse = True)
	print(Dictionary)

	exit()
