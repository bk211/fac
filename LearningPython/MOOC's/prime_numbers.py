def odd_iter():
	n=1
	while True:
		n=n+2
		yield n

def not_divisible():
	return lambda x:x%n>0

def prime(n):
	yield 2
	it =odd_iter()
	while True:
		n=next(it)
		yield n
		it = filter(not_divisible(n),it)
