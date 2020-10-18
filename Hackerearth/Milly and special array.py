//code by Manas Ranjan Munda
//github id-https://github.com/manas1410
//hackerearth id-https://www.hackerearth.com/@manasranjanmunda

def solve(N, s):
    vals = [int(i) for i in s.split()]
    pm_vals = [1 if i>0 else 0 for i in vals]
    
    best = sum(pm_vals[:])
    calc = best
    for i, val in enumerate(pm_vals[::-1]):
        if i==N-1:
            continue
        calc += 1 - 2*val
        if calc<best or i==0:
            best = calc
    
    return best
    
 
# Write your code here
for i in range(int(input())):
    N = int(input())
    print(solve(N, input()))
