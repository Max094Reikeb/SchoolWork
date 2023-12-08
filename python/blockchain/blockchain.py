from block import Block


class Blockchain:
    def __init__(self, difficulty=8, chain=None):
        self.difficulty = difficulty
        if chain is None:
            self.chain = []
        else:
            self.chain = chain

    def __str__(self) -> str:
        full_str = ''
        for block in self.chain:
            full_str += str(block) + '\n\n'
        return full_str

    def mine(self, block: Block):
        try:
            block.previous_hash = self.chain[-1].hash()
            block.number = len(self.chain)
        except IndexError:
            pass

        while True:
            hash = block.hash()
            if hash[:self.difficulty] == "0" * self.difficulty:
                self.chain.append(block)
                break
            else:
                block.nonce += 1
