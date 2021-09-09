CFLAGS= -Wall -g -I -DNDEBUG
DEPS= ex22.h
ODIR=obj
# add -DNDEBUG to remove debug macros fro dbg.h
all: ex1 ex3 ex7 ex8 ex9 ex10 ex11 ex12 ex13 ex14 ex15 \
	ex16 ex16b ex17 ex18 ex19

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ex22_main: ex22_main.o ex22.o
	$(CC) -o ex22_main ex22_main.o ex22.o