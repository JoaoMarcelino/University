svar: sharedvariable_posix.o
	gcc -Wall -pthread sharedvariable_posix.c -o svar
sharedvariable_posix.o:	sharedvariable_posix.c
		gcc -c  sharedvariable_posix.c  -pthread

clean: 
	  $(RM) svar

