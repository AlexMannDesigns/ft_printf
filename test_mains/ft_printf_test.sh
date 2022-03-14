if [ $1 = 'clean' ]; then
	/bin/rm -f *.o
	/bin/rm -f tests tests_memory
	exit 1
fi

if [ $1 = 'make' ]; then
	make re -C ../
	exit 1
fi

if [ $1 = 'comp' ]; then
	make comp_dev -C ../
	exit 1
fi

if [ $1 = 'all' ]; then
	./ft_printf_test.sh 1
	./ft_printf_test.sh 2
	./ft_printf_test.sh 3
	./ft_printf_test.sh 4
	./ft_printf_test.sh 5
	./ft_printf_test.sh 6
	./ft_printf_test.sh 7
	./ft_printf_test.sh 8
	exit 1
fi

TESTMAIN="tests_main_0$1"
gcc -Wall -Wextra -Werror -Wformat=0 -g -c -x c $TESTMAIN.test test_functions.test
gcc -g -o tests_printf $TESTMAIN.o test_functions.o -L ../ -lftprintf

if [ $1 -eq 1 ]; then

printf "\n\033[0;35m======================= BASIC CONVERSION TESTS =======================\033[0m\n\n"
printf "\033[0;36m\t\t  printf output\033[0m || \033[0;35mft_printf output\033[0m\n\n"
./tests_printf

fi

if [ $1 -eq 2 ]; then

printf "\n\033[0;35m======================= WIDTH & PRECISION TESTS =======================\033[0m\n\n"
printf "\033[0;36m\t\t  printf output\033[0m || \033[0;35mft_printf output\033[0m\n\n"
./tests_printf

fi

if [ $1 -eq 3 ]; then

printf "\n\033[0;35m======================= HASH (#) FLAG TESTS =======================\033[0m\n\n"
printf "\033[0;36m\t\t  printf output\033[0m || \033[0;35mft_printf output\033[0m\n\n"
./tests_printf

fi

if [ $1 -eq 4 ]; then

printf "\n\033[0;35m======================= ZERO (0) FLAG TESTS =======================\033[0m\n\n"
printf "\033[0;36m\t\t  printf output\033[0m || \033[0;35mft_printf output\033[0m\n\n"
./tests_printf

fi

if [ $1 -eq 5 ]; then

printf "\n\033[0;35m======================= PLUS (+) & SPACE ( ) FLAG TESTS =======================\033[0m\n\n"
printf "\033[0;36m\t\t  printf output\033[0m || \033[0;35mft_printf output\033[0m\n\n"
./tests_printf

fi

if [ $1 -eq 6 ]; then

printf "\n\033[0;35m======================= LENGTH MODS =======================\033[0m\n\n"
printf "\033[0;36m\t\t  printf output\033[0m || \033[0;35mft_printf output\033[0m\n\n"
./tests_printf

fi