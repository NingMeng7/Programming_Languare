"""
1 首先，执行 `try` 子句 （在try和except关键字之间的部分）。

2 如果没有异常发生, except子句在try子句执行完毕后就被忽略了。

2 如果在try子句执行过程中发生了异常，那么try子句剩下的部分就会被忽略, 进入异常匹配过程

3 如果异常匹配于except关键字后面指定的异常类型,就执行对应的except子句.然后继续执行try"语句"之后的代码(注意是完整的try,except语句, 而不是try子句)

如果发生了一个异常，在except子句中没有与之匹配的分支，它就会传递到上一级try语句中。

如果最终仍找不到对应的处理语句，它就成为一个未处理异常，终止程序运行，显示提示信息

如果还有可选字句 finally, 程序离开try后不论什么情况，都会执行finally字句，当try语句中发生未被except捕获的异常，在finally子句后会重新被抛出

try:
    statements to be inside try clause
    do something
except ExpectionName:
    statements to evaluated in case of ExceptionName happens
"""
def get_number():
    number = float(input("Enter a float number: "))
    return number

while True:
    try:
        print(get_number())
    except ValueError:
        print("You entered a wrong value.")
    finally:
        print('bye')


# KeyboardInterrupt 无法被ValueError捕获, 因此程序会停止运行(最后一条)
# 空的except 能捕获任何异常
try:
    input()
except:
    print("Unknown Exception")
    
# 我们可以主动raise(抛出)异常
raise ValueError("A value error happened.")

# Finally 子句(可选)