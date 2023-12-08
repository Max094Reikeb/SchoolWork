from time import perf_counter

from block import Block
from blockchain import Blockchain

t1_start = perf_counter()
blockchain = Blockchain()
blockchain.mine(Block('bonjour'))
t1_stop = perf_counter()

print('Time elapsed: ' + str(t1_stop - t1_start) + 's\n')
print(blockchain)
