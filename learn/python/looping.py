knights = {'gallahad': 'the pure', 'robin': 'the brave'}
for key,val in knights.items():
    print(key, val)

something = ['tic', 'tac', 'toe']
for index, val in enumerate(something):
    print(index, val)

questions = ['name', 'quest', 'favorite color']
answers = ['lancelot', 'the holy grail', 'blue']
for q, a in zip(questions, answers):
    print('What is your {0}?  It is {1}.'.format(q, a))

for i in reversed(range(1, 10, 2)):
    print(i)
#or
for i in range(9,0,-2):
    print(i, end=' ')

