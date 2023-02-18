libmymath.a:sub.o add.o
	ar -rc $@ $^
%.o:%.c
	gcc -c $<

.PHONY:clean
clean:
	rm -rf libmymath.a *.o output

.PHONY:output 
output:
	mkdir output 
	cp *.h output 
	cp libmymath.a output
