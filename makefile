all: calendar.exe

calendar.exe: calendar.o
	 gcc -o calendar.exe *.o

calendar.o: calendar.c
	 gcc -c *.c
     
clean:
	 rm *.o calendar.exe
