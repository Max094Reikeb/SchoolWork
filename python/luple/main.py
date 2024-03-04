from typing_extensions import SupportsIndex


def convert(item):
    if isinstance(item, bool):
        if item:
            return [1, 0]
        else:
            return [0, 0]
    elif isinstance(item, int):
        return [item, 1]
    elif isinstance(item, str):
        return [int(item), 2]
    else:
        return []


def deconvert(item):
    if isinstance(item, list):
        if item[1] == '0':
            return item[0] == '1'
        elif item[1] == '1':
            return int(str(item[0]))
        elif item[1] == '2':
            return str(item[0])
        else:
            return ""
    return ""


class Luple(list):
    def __init__(self, iterable):
        super().__init__(convert(item) for item in iterable)

    def __setitem__(self, index, item):
        super().__setitem__(index, convert(item))

    def insert(self, index, item):
        super().insert(index, convert(item))

    def append(self, item):
        super().append(convert(item))

    def extend(self, other):
        if isinstance(other, type(self)):
            super().extend(other)
        else:
            super().extend(convert(item) for item in other)

    def count(self, item) -> int:
        return super().count(convert(item))

    def index(self, item, start: SupportsIndex = ..., stop: SupportsIndex = ...) -> int:
        return super().index(convert(item), start, stop)

    def remove(self, item):
        super().remove(convert(item))
