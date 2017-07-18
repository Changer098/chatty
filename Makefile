client :
	gcc -std=c99 client.c -o client
	
server :
	gcc -std=c99 server.c llist.c -o server
	
clean :
	rm server
	rm client