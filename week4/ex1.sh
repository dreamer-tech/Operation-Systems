#!/bin/bash
n=10
while [ "$n" -gt 0 ]
do
	./ex1
	n=`expr $n - 1 `
done
