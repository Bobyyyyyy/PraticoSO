import os
import sys



def scandir(directory):
	with os.scandir(directory) as it:
		for entry in it:
			if(entry.is_symlink()):
				os.remove(entry)
			if (entry.is_dir()):
				scandir(entry.path)



if __name__ == "__main__":
	if(len(sys.argv) != 2):
		print("errore")
		exit()

	Directory = "0";

	if(os.path.exists(sys.argv[1])):
		Directory = sys.argv[1]

	scandir(Directory)


	exit()





