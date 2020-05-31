CC=gcc
flag= -Wall -Wextra -Wundef -Werror -Wuninitialized -Winit-self
exec= Tarea3

Tarea3:	main.o card.o player.o 
	$(CC) $(flag) main.o -o Tarea3
	
main.o: main.c card.h player.h
	$(CC) $(flag) -o main.o main.c -c
	
card.o: card.h 
	$(CC) $(flag) -o card.o card.c -c 
	
player.o: player.h 
	$(CC) $(flag) -o player.o player.c -c 	
		
clean:
	rm -f *.o
	rm -f $(exec)
