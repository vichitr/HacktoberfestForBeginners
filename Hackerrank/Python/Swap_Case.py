def swapCase(s):
    a = ''
    for x in s:
        if x.isupper():
            a = a + x.lower()
        else:
            a = a + x.upper()
    return a
