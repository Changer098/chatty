client : client.c
	gcc -std=gnu99 -I include client.c -o client
	
server : server.c llist.c user.c
	gcc -std=gnu99 -I include llist.c helpers.c user.c server.c -o server
	
clean :
	rm server
	rm client
