import sys

# 转换函数
def Hours(minute):
    # 如果为负数则 raise 异常
    if minute < 0:
        raise ValueError("Input number cannot be negative")
    else:
        print("{} H, {} M".format(int(minute / 60), minute % 60))

# 函数调用及异常处理逻辑
while True:
    minute = float(input("Enter the minute: "))
    try:
        Hours(minute)
    except:
        print("Parameter Error")
