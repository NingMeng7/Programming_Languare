weight = float(input('please input your weight by the unit of kg: '))
height = float(input('Please input your height by the unit of m: '))
BIM = weight/(height*height)

if   BIM >= 32:
	print('严重肥胖')
elif BIM >= 28:
	print('肥胖')
elif BIM >= 25:
	print('过重')
elif BIM >=18.5:
	print('正常')
else:
	print('过轻')