a = [1,2,3]
b = ['a','b','c','d']

#  zip(a,a,a)
for l, x in zip(b,(a,a,a)):
    print(l)
    print(x)
