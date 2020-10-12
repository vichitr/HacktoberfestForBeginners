# You need to construct a feature in a Digital Camera, which 
# will auto-detect and suggest to the photographer whether the 
# picture should be clicked in day or night mode, depending on 
# whether the picture is being clicked in the daytime or at night. 
# You only need to implement this feature for cases which are 
# directly distinguishable to the eyes (and not fuzzy scenarios 
# such as dawn, dusk, sunrise, sunset, overcast skies which might 
# require more complex aperture adjustments on the camera).

# Link: https://www.hackerrank.com/challenges/digital-camera-day-or-night
# Developer: Murillo Grubler

import numpy as np

img = input().split(" ")
lum = 0
for i in range(len(img)):
    types = [int(i) for i in img[i].split(",")]
    lum += np.sum(types) / 3
print("day" if lum/len(img) > 90 else "night")