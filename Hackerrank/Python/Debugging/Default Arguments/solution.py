################################################################################
#----------------------------- begin locked code ------------------------------#
class EvenStream(object):
    def __init__(self):
        self.current = 0

    def get_next(self):
        to_return = self.current
        self.current += 2
        return to_return

class OddStream(object):
    def __init__(self):
        self.current = 1

    def get_next(self):
        to_return = self.current
        self.current += 2
        return to_return
#------------------------------ end locked code -------------------------------#
################################################################################

def print_from_stream(n, stream=EvenStream()):
    for _ in range(n):
        print(stream.get_next())
    stream.current = 0

################################################################################
#----------------------------- begin locked code ------------------------------#
queries = int(input())
for _ in range(queries):
    stream_name, n = input().split()
    n = int(n)
    if stream_name == "even":
        print_from_stream(n)
    else:
        print_from_stream(n, OddStream())
#------------------------------ end locked code -------------------------------#
################################################################################
