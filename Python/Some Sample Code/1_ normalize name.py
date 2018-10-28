name = input('Please enter your name:')
if 'yuhui' in name.lower() or 'yu hui' in name.lower():   
    print('你这个死gay!')
    
firname, lasname = name.split(' ')
name = firname[0].upper() + firname[1:].lower() + ' ' + lasname[0].upper() + lasname[1:].lower()
print('Hello', name)
