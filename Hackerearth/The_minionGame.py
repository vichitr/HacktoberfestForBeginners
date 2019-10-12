

def minion_game(string):
    length = len(string)

    the_vowel = "AEIOU"

    kevin = 0
    stuart = 0
    for i in range(length):
        if string[i] in the_vowel:
            kevin = kevin + length - i
        else:
            stuart = stuart + length - i

    if kevin > stuart:
        print ("Kevin %d" % kevin)
    elif kevin < stuart:
        print ("Stuart %d" % stuart)
    else:
        print ("Draw")
