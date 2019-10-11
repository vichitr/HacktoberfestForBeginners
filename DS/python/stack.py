class stack:
    def __init__(self):
        self.stack = []

    def push(self, obj):
        self.stack.append(obj)

    def pull(self):
        if len(self.stack) > 0:
            return self.stack.pop()
        return None

    def top(self):
        if len(self.stack) > 0:
            return self.stack[-1]
        return None
