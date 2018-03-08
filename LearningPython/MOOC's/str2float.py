from functools import reduce
def str2float(s):
    sl = s.split('.')
    return reduce(lambda x,y:x*10+y,list(map(int, sl[0]))) + reduce(lambda x,y:x*10+y,list(map(int, sl[1])))/pow(10, len(sl[1]))
print('str2float(\'123.456\') =', str2float('123.456'))