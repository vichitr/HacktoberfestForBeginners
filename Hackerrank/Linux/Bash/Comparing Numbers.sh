#!/bin/bash
read X
read Y
if (( $X > $Y ))
then
    echo "X is greater than Y"
fi

if (( $X == $Y))
then
    echo "X is equal to Y"
fi

if(( $X < $Y))
then
    echo "X is less than Y"
fi