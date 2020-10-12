read x
read y
read z

if [[ x -ne z ]] && [[ x -ne y ]] && [[ y -ne z ]]; then
    echo SCALENE
elif [[ x -eq z ]] && [[ x -eq y ]] && [[ y -eq z ]]; then
    echo EQUILATERAL
else
    echo ISOSCELES
fi
