#!/bin/bash
# the executable file btree and random should be in the same direction.
gcc btree.c -Wall -pg -o btree
gcc random.c -Wall -o random
echo Choose what you want to implement: insert--i, delete--d, or seach--s &&
read func &&
if [[ $(find profiling -type d) ]]; then
	rm -r profiling
fi
mkdir profiling
for i in {10..1000..10}; do
    #statements
    ./random $i
    ./btree $func $RANDOM
    gprof btree gmon.out > profiling/$i.dat
    echo i=$i finished
done
