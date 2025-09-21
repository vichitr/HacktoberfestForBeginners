nbMesures = int(input())
tempMin = int(input())
tempMax = int(input())
tempValide = True
numMesure = 0
while tempValide and numMesure < nbMesures :
   temperature = int(input())
   tempValide = (tempMin <= temperature and temperature <= tempMax)
   if tempValide:
      print("Rien à signaler")
   else:
      print("Alerte !!")
   numMesure = numMesure + 1
