base_dir=r'C:\Users\xw201\Desktop\test'
def pick(obj):
    if ob.endswith(".pyc"):
        print(obj)
		
def scan_path(ph):
    file_list = os.listdir(ph)
    for obj in file_list:
        if os.path.isfile(obj):
    pick(obj)
        elif os.path.isdir(obj):
            scan_path(obj)
    
scan_path(base_dir)