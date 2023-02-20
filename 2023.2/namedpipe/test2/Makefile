.PHONY:all
all:client server

client:client.c
	gcc -o $@ $^ -std=c99

server:server.c
	gcc -o $@ $^ -std=c99 


.PHONY:clean
clean:
	rm -f client server

