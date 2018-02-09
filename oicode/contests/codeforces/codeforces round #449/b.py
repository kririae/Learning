a, b = [int(i) for i in str(input()).split(" ")]
count = 0
summ = 0
for i in range(1, a + 1):
    tempo = ''.join([i for i in list(str(i))])
    tempo += ''.join(list(reversed(tempo)))
    summ += int(str(tempo))
    summ %= b
print(summ % b)