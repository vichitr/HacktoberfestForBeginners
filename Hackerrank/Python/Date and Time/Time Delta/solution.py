from datetime import datetime

format_str = "%a %d %b %Y %H:%M:%S %z"
for i in range(int(input())):
    datetime1 = datetime.strptime(input(), format_str)
    datetime2 = datetime.strptime(input(), format_str)
    delta = abs(datetime1 - datetime2)
    print(int(delta.total_seconds()))
