import hashlib


def updatehash(*args: object) -> str:
    obj = ''
    for arg in args:
        obj += str(arg)
    return hashlib.sha256(obj.encode('utf-8')).hexdigest()


class Block:
    def __init__(self, data: object, number=0):
        self.data = data
        self.number = number
        self.nonce = 0
        self.previous_hash = '0' * 64

    def hash(self) -> str:
        return updatehash(self.number, self.previous_hash, self.data, self.nonce)

    def __str__(self) -> str:
        return 'Block#: ' + str(self.number) + '\nHash: ' + self.hash() + '\nPrevious: ' + str(
            self.previous_hash) + '\nData: ' + str(self.data) + '\nNonce: ' + str(self.nonce)
