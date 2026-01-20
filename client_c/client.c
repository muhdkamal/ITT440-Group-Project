#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

// Connects specifically to the C-Server Container name and Port 5002
#define SERVER_HOST "c-server-container"
#define SERVER_PORT 5002

int main() {
    int sock = 0;
    struct sockaddr_in serv_addr;
    struct hostent *he;
    char *message = "GET_SCORE";
    char buffer[2048] = {0};

    // 1. Create Socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    // 2. Resolve the container name to an IP address
    he = gethostbyname(SERVER_HOST);
    if (he == NULL) {
        printf("Could not resolve hostname: %s\n", SERVER_HOST);
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVER_PORT);
    memcpy(&serv_addr.sin_addr, he->h_addr_list[0], he->h_length);

    // 3. Connect to the C Server
    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("\nConnection Failed. Is the C-Server running?\n");
        return -1;
    }

    // 4. Send the request and read the response
    send(sock, message, strlen(message), 0);
    printf("Request sent to C Server...\n");
    
    read(sock, buffer, 2048);
    printf("\n--- C Server Response ---\n%s", buffer);

    close(sock);
    return 0;
}
