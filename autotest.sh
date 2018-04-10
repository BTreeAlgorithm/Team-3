#!/bin/bash
# the executable file btree and random should be in the same direction.
gcc btree.c -Wall -pg -o btree
gcc random.c -Wall -o random
echo Enter scale start at : &&
read start &&
echo Enter scale end at : &&
read end &&
echo Choose use the same value for repeat or not &&
echo d means differet Or s means same &&
read choice &&
if [[ $(find profiling -type d) ]]; then
    rm -r profiling
fi
mkdir profiling
# if [[ $(find $(pwpd) -name search.dat) ]]; then
#     touch search.dat
# fi
i=$start
repeat=100000
until [[ i -gt $end ]]; do
    ./random $i test.dat d
    ./random $repeat search.dat $choice
    ./btree s m search.dat
    gprof btree gmon.out > profiling/$i.dat
    i=$((3*$i))
    echo i=$i finished
done
# for i in {3000..3000..10}; do
#     #statements
#     ./random $i test.dat
#     ./random $i search.dat
#     ./btree s m search.dat
#     gprof btree gmon.out > profiling/$i.dat
#     echo i=$i finished
# done
