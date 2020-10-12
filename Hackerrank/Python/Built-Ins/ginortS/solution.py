def char_priority(ch):
    if ch.islower():
        return (1, ch)
    elif ch.isupper():
        return (2, ch)
    elif ch.isdigit():
        if int(ch) % 2 == 1:
            return(3, ch)
        else:
            return(4, ch)

print(*sorted(input(), key=char_priority), sep='')
