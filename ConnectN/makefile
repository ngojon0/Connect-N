connectn.out: main.o board.o playgame.o win.o input.o
	gcc -Wall -Werror -o connectn.out main.o board.o playgame.o win.o input.o

main.o : main.c
	gcc -Wall -Werror -c main.c

board.o: board.c
	gcc -Wall -Werror -c board.c

playgame.o : playgame.c
	gcc -Wall -Werror -c playgame.c

win.o : win.c
	gcc -Wall -Werror -c win.c

input.o : input.c
	gcc -Wall -Werror -c input.c

clean:
	rm -fr *.o *.out
