def test_3_5_15(n):
	if (n % 15 == 0) and n != 0 :
		return 'FizzBuzz'
	elif n % 3 ==0 and n != 0:
		return 'Fizz'
	elif n % 5 == 0 and n != 0:
		return 'Buzz'
	else:
		return n			

def coundown():
	for x in range (0,101):
		print(test_3_5_15(x))

coundown()	