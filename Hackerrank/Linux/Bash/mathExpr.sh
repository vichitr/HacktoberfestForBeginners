read word
value=` echo "$word " | bc -l `
echo $(printf %.3f $value)