read
numArr=($(cat))

numArr=${numArr[*]}
echo $((${numArr// /^}))
