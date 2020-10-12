_ = input()
english = {int(x) for x in input().split()}
_ = input()
french = {int(x) for x in input().split()}
print(len(english & french))
