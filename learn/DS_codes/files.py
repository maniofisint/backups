s = """ dfl;kjghdf;ljk
dfgh;lkjfd;lgkjfd
sdfg;lkjfd
ds;lgkjdfg'jgf;lkj\
    dfggdfgl;jkg
    dfglkjdf

df;ghkl
"""
name = "newfile.txt"
"""
fp = open(name , 'w') # w , a , r , rb , wb , ab
print(s , file=fp)
fp.close()"""

fp = open(name , "r")
print(fp.read())
fp.seek(0)
print(fp.read(30))
print(fp.readlines())
fp.seek(0)
for li in fp:
    print(li)
fp.seek(23)
print(fp.tell())
fp.write(name)
print(name , file=fp)