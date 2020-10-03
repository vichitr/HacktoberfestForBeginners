#Author: Khush31
#Problem Statement: Minion Game https://www.hackerrank.com/challenges/the-minion-game/problem



if __name__=='__main__':
    s= input()
    Minion_Game(s)


def Minion_Game(string):
    kevin=0
    stuart=0
    for i in range(len(string)):
        if string[i]=='A' or string[i]=='E' or string[i]=='I' or string[i]=='O' or string[i]=='U':
            kevin+=len(string)-i
        else:
            stuart+=len(string)-i
    if kevin>stuart:
        print("Kevin "+str(kevin))
    elif kevin<stuart:
        print("Stuart "+str(stuart))
    else:
        print("Draw")    
