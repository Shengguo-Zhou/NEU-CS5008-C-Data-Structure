all: kk_client kk_server echo_client echo_server

kk_server: kk_server.c
	gcc kk_server.c -o kk_server

kk_client: kk_client.c
	gcc kk_client.c -o kk_client

run_kk_server: kk_server
	./kk_server

run_kk_client: kk_client
	./kk_client

echo_server: echo_server.c
	gcc echo_server.c -o echo_server

echo_client: echo_client.c
	gcc echo_client.c -o echo_client

run_echo_server: echo_server
	./echo_server

run_echo_client:
	./echo_client

clean: 
	rm *~ kk_server kk_client echo_server echo_client
