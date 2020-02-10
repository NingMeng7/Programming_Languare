import os
import sys


def parse_file(path):
    """
    分析给定文本文件，返回其空格、制表符、行的相关信息

    :arg path: 要分析的文本文件的路径

    :return: 包含空格数、制表符数、行数的元组
    """
    fd = open(path)
    i = 0
    spaces = 0
    tabs = 0
    for i,line in enumerate(fd):
        spaces += line.count(' ')
        tabs += line.count('\t')
    # 现在关闭打开的文件
    fd.close()

    # 以元组形式返回结果
    return spaces, tabs, i + 1


file_dir = r'C:\Users\xw201\Desktop\test\ch1.txt'
spaces, tabs, lines = parse_file(file_dir)
print("Spaces {}. tabs {}. lines {}".format(spaces, tabs, lines))
