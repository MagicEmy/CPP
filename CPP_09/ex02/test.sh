function run()
{
	if [OS == LINUX]
		./PmergeMe `shuf -i 0-1000000 -n $1 | tr "\n" " "`
	else



	# else
	# 	./PmergeMe `jot -r $1 0 1000000 | tr "\n" " "`
	# fi 

}

run 3000