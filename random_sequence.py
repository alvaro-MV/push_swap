import random
import argparse 

'''
for i in range(100):
    sequence.append(i)

for i in range(100):
    num1 = random.randint(0, 99)
    num2 = random.randint(0, 99)

    aux = sequence[num1]
    sequence[num1] = sequence[num2]
    sequence[num2] = aux

print(' '.join(list(map(lambda x : str(x), sequence))))
'''

parser = argparse.ArgumentParser()
parser.add_argument("--len", help="sequence length", type = int)
args = parser.parse_args()

sequence = list(range(0, args.len))
random.shuffle(sequence)
print(' '.join(list(map(lambda x : str(x), sequence))))
