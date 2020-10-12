awk '{
printf (NR%2==0) ? $0 "\n" : $0";"
}'
