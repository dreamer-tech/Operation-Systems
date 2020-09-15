#!/bin/bash

file_name="numbers.txt"  # file name we will use
file_lock="${file_name}.lock"  # lock to the file we will create

# all below is the critical region as we are reading from the file and writing to it
# consequently if there will be more than 1 read/write instruction at a time it will lead to a race condition
# for example there can be 2 equal numbers

until ln $file_name $file_lock  # wait until we can lock this file
do
  sleep 2
done	# creat a lock file to prevent race condition

last_number=$(tail -n 1 $file_name)  # take the last number from the file

last_number=$((last_number+1))  # increment the last number by one
echo $last_number >> "${file_name}"	 # append incremented last number to file

rm $file_lock		# remove lock file
