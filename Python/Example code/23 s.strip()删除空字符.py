# 1. filter 删除空字符
def not_empty(s):
	return s and s.strip()	# s:去除None or ''   s.strip()：去除s内的white space

L = list(filter(not_empty, ['A', '', 'B', None, 'C', ' ']))
print(L)
input('waiting...')
