class MyQueue(object):
    def __init__(self):
        self.store = []
        self.delivery = []

    def peek(self):
        if not self.delivery:
            while self.store:
                self.delivery.append(self.store.pop())

        return self.delivery[-1]

    def pop(self):
        if not self.delivery:
            while self.store:
                self.delivery.append(self.store.pop())

        return self.delivery.pop()

    def put(self, value):
        self.store.append(value)


queue = MyQueue()
t = int(input())
for line in range(t):
    values = map(int, input().split())
    values = list(values)
    if values[0] == 1:
        queue.put(values[1])
    elif values[0] == 2:
        queue.pop()
    else:
        print(queue.peek())
