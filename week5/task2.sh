n=100
i=0
while [ $i -lt $n ]
do
	i=`expr $i + 1`
	if [ ! -e fsa.txt.lock ]; then

		if `ln fsa.txt fsa.txt.lock`; then
			t=$(tail -n 1 fsa.txt.lock)
			printf "$((t+1))\n" >> fsa.txt.lock
			rm fsa.txt.lock
		fi
	fi
done