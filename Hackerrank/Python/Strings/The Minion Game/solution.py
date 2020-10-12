vowels = "AEIOU"

def minion_game(string):
    kevin_score = 0
    stuart_score = 0
    for i in range(len(string)):
        # Number of substrings starting at string[i]
        num_substrings = len(string) - i
        if string[i] in vowels:
            kevin_score += num_substrings
        else:
            stuart_score += num_substrings

    if kevin_score > stuart_score:
        print("Kevin " + str(kevin_score))
    elif stuart_score > kevin_score:
        print("Stuart " + str(stuart_score))
    else:
        print("Draw")

################################################################################
#----------------------------- begin locked code ------------------------------#
if __name__ == '__main__':
    s = input()
    minion_game(s)
#------------------------------ end locked code -------------------------------#
################################################################################
