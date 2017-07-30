client : client.c
	gcc -std=c99 client.c -o client
	
server : server.c llist.c
	gcc -std=gnu99 server.c llist.c -o server
	
clean :
	rm server
	rm client
