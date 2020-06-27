all: calendar.exe

calendar.exe: calendar.o
	 gcc -o calendar.exe calendar.o

calendar.o: calendar.c
	 gcc -c calendar.c
     
clean:
	 rm calendar.o calendar.exe
