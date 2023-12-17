#!/bin/bash

while [ 1 ]
do
	make >/dev/null 2>&1
	clear
	./push_swap $1 > .tmp
	/bin/cat .tmp
	echo ""
	echo -n "Number of instructions: "
	wc -l .tmp | cut -d' ' -f1
	echo -n "Checker: "
	./checker $1 < .tmp
	sleep 0.1
done
