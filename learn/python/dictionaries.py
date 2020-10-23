tel = {'jack': 4098, 'sape': 4139}
tel['guido'] = 4127
print(tel)
print(tel['jack'])

del tel['sape']
print(tel)

tel['irv'] = 4127
print(tel)

print(list(tel.keys()))
print(sorted(tel.keys()))

print('guido' in tel)
print('jack' not in tel)

print(dict(sape=4139, guido=4127, jack=4098) )