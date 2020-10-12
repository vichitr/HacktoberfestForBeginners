awk {'
avg=($2+$3+$4)/3;
printf "%c %d %d %d : ", $1,$2,$3,$4;
if (avg<50)
print "FAIL";
else if (avg<80)
print "B";
else
print "A";
'}
