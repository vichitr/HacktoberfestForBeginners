class queue:
    def __init__(self):
        self.queue = []

    def enqueue(self, obj):
        self.queue.append(obj)

    def dequeue(self):
        if len(self.queue) > 0:
            return self.queue.pop(0)
        return None

    def rear(self):
        return self.queue[-1]

    def front(self):
        if len(self.queue) > 0:
            return self.queue[0]
        return None
