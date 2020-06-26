#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>
#include <wiringPi.h>

#define BUF_SIZE 100
#define MAX_CLNT 256

void* handle_clnt(void* arg);
void send_msg(char* msg, int len);
void error_handling(char* msg);

int led = 2;

int clientCount = 0;
int clientSockArray[MAX_CLNT];
pthread_mutex_t mutex;

int main(int argc, char* argv[])
{
	wiringPiSetup();

	pinMode(led, OUTPUT);

	int serv_sock, clnt_sock;
	struct sockaddr_in serv_adr, clnt_adr;
	socklen_t clnt_adr_sz;
	pthread_t t_id;

	// help message
	if (argc != 2) {
		printf("Usage : %s <port>\n", argv[0]);
		exit(1);
	}

	pthread_mutex_init(&mutex, NULL);
	serv_sock = socket(PF_INET, SOCK_STREAM, 0);

	memset(&serv_adr, 0, sizeof(serv_adr));
	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);
	serv_adr.sin_port = htons(atoi(argv[1]));

	if (bind(serv_sock, (struct sockaddr*)&serv_adr, sizeof(serv_adr)) == -1)
		error_handling("bind() error");
	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	while (1) {
		clnt_adr_sz = sizeof(clnt_adr);
		clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_adr, &clnt_adr_sz);

		pthread_mutex_lock(&mutex);

		clientSockArray[clientCount++] = clnt_sock;

		pthread_mutex_unlock(&mutex);

		pthread_create(&t_id, NULL, handle_clnt, (void*)&clnt_sock);
		pthread_detach(t_id);

		printf("Connected client IP: %s \n", inet_ntoa(clnt_adr.sin_addr));
	}

	close(serv_sock);

	return 0;
}

void* handle_clnt(void* arg) {
	int clnt_sock = *((int*)arg);
	int str_len = 0, i;
	char msg[BUF_SIZE];
	char* token;

	while ((str_len = read(clnt_sock, msg, sizeof(msg))) != 0) {

		if (str_len == 0) {
			continue;
		} else if (msg[str_len - 1] == '\n') {
			msg[str_len - 1] = '\0';
		} else {
			msg[str_len] = '\0';
		}

		token = strtok(msg, " ");
		printf("token: 0x");
		for (int i = 0; i < strlen(token); ++i) {
			printf("%02x", token[i]);
		}
		printf("\n");
		if (!strcmp(token, "led")) {
			token = strtok(NULL, " ");
			printf("token: 0x");
			for (int i = 0; i < strlen(token); ++i) {
				printf("%02x", token[i]);
			}
			printf("\n");
			if (!strcmp(token, "on")) {
				send_msg("server: led on\n", strlen("server: led on\n"));
				digitalWrite(led, 1);
			} else if (!strcmp(token, "off")) {
				digitalWrite(led, 0);
				send_msg("server: led off\n", strlen("server: led off\n"));
			}
		}
	}

	pthread_mutex_lock(&mutex);

	for (i = 0; i < clientCount; ++i) {
		if (clnt_sock == clientSockArray[i]) {
			while (i++ < clientCount - 1) {
				clientSockArray[i] = clientSockArray[i + 1];
			}

			break;
		}
	}
	--clientCount;

	pthread_mutex_unlock(&mutex);

	close(clnt_sock);

	return NULL;
}

void send_msg(char* msg, int len) {
	pthread_mutex_lock(&mutex);

	for (int i = 0; i < clientCount; ++i) {
		write(clientSockArray[i], msg, len);
	}

	pthread_mutex_unlock(&mutex);
}

void error_handling(char* msg) {
	fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}
