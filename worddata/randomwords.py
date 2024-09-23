from random import randrange
import requests

word_file = "/usr/share/dict/words"
words = open(word_file).read().splitlines()

words = [i for i in words if len(i) <= 10 and "\'" not in i]

#print(words)

tam = len(words)
print(tam)

with open('rw.txt', 'w') as f:
    for i in range(tam):
        f.write(words[randrange(tam)])
        f.write('\n')


