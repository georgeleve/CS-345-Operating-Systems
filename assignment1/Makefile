#           Makefile  for C shell             #   
# Georgios Gerasimos Leventopoulos  csd4152   #

cs345sh: cs345sh.o helpers.o
	gcc cs345sh.o helpers.o -o cs345sh.out

cs345sh.o: cs345sh.c 
	gcc -c cs345sh.c

helpers.o: helpers.c helpers.h
	gcc -c helpers.c

clean:
	@rm -f *.o *.out

