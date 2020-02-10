def judge(s):
	s = str(s)
	i = 0;
	j = len(s) - 1
	while i < j:
		if(s[i] != s[j]):
			return False
		i = i + 1
		j = j - 1
	return True
output = list(filter(judge, range(1, 1000)))
print(output)
