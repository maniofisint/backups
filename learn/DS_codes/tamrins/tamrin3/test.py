#prefix = list(map(int, sys.stdin.readline().strip().split()))

import sys
x = sys.stdin.readline()
print(x.strip().split())

y = list(map(int,input().split()))
print(y)

# Python program to demonstrate working 
# of map. 

# Return double of n 
def addition(n): 
	return n + n 

# We double all numbers using map() 
numbers = [1, 2, 3, 4]
result = list(map(addition, numbers))
print(result) 
