.PHONY:all
all:myload myexe 

myexe:myexe.c
	gcc -o $@ $^ -std=c99 

myload:myload.c
	gcc -o $@ $^ -std=c99

.PHONY:clean
clean:
	rm -f myload
