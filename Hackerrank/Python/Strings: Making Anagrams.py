#author: amititkgp
'''Program to count the minimum number of deletions required to make 2 strings anagrams
    For eg:
    string1 = abcdefg
    string2 = abcd
    Output = 3
    as deleting 'efg' will make string1 and string2 anagrams'''

def makeAnagram(a, b):
    A = set(a) - set(b)
    B = set(b) - set(a)
    new_a = []
    new_b = []
    count = 0
    for i in a:
        if i not in A:
            new_a.append(i)
        else:
            count+=1
    for i in b:
        if i not in B:
            new_b.append(i)
        else:
            count+=1
    for i in set(a)-(A-B):
        count+= new_a.count(i) - new_b.count(i) if new_a.count(i)>new_b.count(i) else                                                       new_b.count(i) - new_a.count(i)
                # print(new_b)
    # print(sorted(new_a), sorted(new_b))
    return count

a = input() #string1
b = input() #string2
res = makeAnagram(a, b) #min number of deletions
print(res)
