#!/bin/bash

nemu=obj/nemu/nemu
cmd="c\nq"

for file in $@; do
	printf "[$file]"
	logfile=`basename $file`-log.txt
	echo -e $cmd | /usr/bin/time -f '%e' -o time.log $nemu $file &> $logfile
	time_cost=`cat time.log`
	printf "($time_cost s): "
	rm time.log

	if (grep 'nemu: HIT GOOD TRAP' $logfile > /dev/null) then
		echo -e "\033[1;32mPASS!\033[0m"
		rm $logfile
	else
		echo -e "\033[1;31mFAIL!\033[0m see $logfile for more information"
		if (test -e log.txt) then
			echo -e "\n\n===== the original log.txt =====\n" >> $logfile
			cat log.txt >> $logfile
			rm log.txt
		fi
	fi
done
