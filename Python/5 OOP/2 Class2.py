class Test:

    def __init__(self, foo):
        self.__foo = foo

    def __bar(self):
        print(self.__foo)
        print('__bar')


def main():
    test = Test('hello')
    # AttributeError: 'Test' object has no attribute '__bar'
    test.__bar()
    # AttributeError: 'Test' object has no attribute '__foo'
    print(test.__foo)
	


main()
'''
python 并没有从语法上规定外部不能访问__开头的方法或者属性, 而是
使用了一种更换名字的规则来妨碍这种访问, 事实上你如果知道这种规则,
同样可以访问.
We are all consenting adults here
'''
test = Test('hello')
test._Test__bar()
print(test._Test__foo)

"""
大多数Python程序员会遵循一种命名惯例就是
让属性名以单下划线开头来表示属性是受保护的，本类之外的代码在访问这样的属性时应该要保持慎重。
"""