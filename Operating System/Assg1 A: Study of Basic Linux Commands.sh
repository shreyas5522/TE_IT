#!/bin/sh
# echo "Hello World!"
# echo "\nEnter Something: "
# # read INPUT
# echo "\nInput: $INPUT"
# echo "\n"

# cat -n a_1_a.sh

# cat > new_file.txt

# test -e a_1_a.sh

# T = test 10 -eq 10
# echo $t

a=0

while [ "$a" -lt 5 ]
do 
    echo -n "\n$a"
    a=`expr $a + 1`
done    