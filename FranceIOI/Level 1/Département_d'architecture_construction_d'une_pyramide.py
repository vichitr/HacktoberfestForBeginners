nbreMaxPierres = int(input())
nbrePierres = 0
hauteur =1
while nbrePierres + hauteur * hauteur <= nbreMaxPierres:
   nbrePierres = nbrePierres + hauteur * hauteur
   hauteur = hauteur + 1

print(hauteur - 1)
print(nbrePierres)
