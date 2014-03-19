#!/usr/bin/python

a = []

def foo(n):
    a.append(n)
    if n <= 1: return
    if (n%2)==1:
        foo((3*n)+1)
    else:
        foo(n/2)

def main():
    s = raw_input('input?\n')
    i = [int(s) for s in s.split(' ')]
    cycle = 0
    max = 0
    if i[0] <= i[1]: 
        start, end = i[0], i[1]+1
    else:
        start, end = i[1], i[0]+1
    for ii in range(start, end):
        foo(ii)
        k = ' '.join(str(j) for j in a)
        #print k+' - '+str(len(a))
        if len(a) > max: max = len(a)
        del a[:]
    k = ' '.join([str(i[0]),str(i[1]),str(max)])
    print k

if __name__ == '__main__':
    main()

