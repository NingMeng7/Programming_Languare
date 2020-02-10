'''文件读取
'''
def get_lines():
	with open('file.txt', 'rb') as f:
        return f.readlines()

def get_lines2():  # 内存不足以一次读入，分次读入
	with open(r'C:\Users\xw2016\Desktop\MYFFT.txt', 'rb') as f:
        for i in f:
            yield i

for e in get_lines2():
    print(e)
