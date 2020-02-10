# if else
# 如果条件是True就把缩进！！的语句执行
# 别忘记 if, else, elif 条件后的冒号!!!
# 这是我18年3月在上海交通大学闵行校区自学python的时候写的代码, 时隔2年啦

try :
	age = float(input('Please enter your age: '))
	if age - int(age) == 0:
		if age >= 18:
			print('your age is', age)
			print('adult')
		else:
			print('your age is', age)
			print('teenager')
	else:
		print('Are you kidding me????')
except ValueError as e:
	print('Error: ', e)
finally:
	input('waiting...')


