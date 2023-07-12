import os
import sys

def visitTree(directory,int):
	try: 
		with os.scandir(directory) as it:
			for entry in it:
				if(int != 2): 
					if(entry.is_dir()):
						visitTree(entry.path,int+1)
					if(entry.is_file()):
						if(entry.name == "loginuid"):
							try:
								f = open(entry.path,"r")
							except PermissionError:
								print("Non hai il permesso, vado avanti")
							else:
								uid = f.readlines()
								print(uid)
								for line in lines:
									if (line != "1000"):
										return
						if(entry.name == "status"):
							try:
								f = open(entry.path,"r")
							except PermissionError:
								print("Non hai il permesso, vado avanti")
							else:
								lines = f.readlines()
								for line in lines:
									if line.find("Name") != -1:
										print(line)
									if line.find("VmSize") != -1:
										print(line)
	except PermissionError:
		return
	except ProcessLookupError:
		return





if __name__ == "__main__":
	if(len(sys.argv) > 1):
		print("Non sono accettati parametri")
		exit()
	print("pietro")
	visitTree("/proc",0);
	exit()
