#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>


int main() {
    int file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (file_descriptor == -1) {
        std::cerr << "Problems with client socket creation" << std::endl;
        return 1;
    }

    sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    int was_connect = connect(file_descriptor, (struct sockaddr *)&addr, sizeof(addr));
    if (was_connect == -1) {
        std::cerr << "Problems with connect" << std::endl;
        return 1;
    }

    char str[4];
    ssize_t cnt_read = read(file_descriptor, str, 3);
    if (cnt_read != 3) {
        std::cerr << "Problems with read" << std::endl;
        return 1;
    }
    str[3] = '\0';
    if (strcmp(str, "OK\n") != 0) {
        std::cerr << "Return value is not OK" << std::endl;
        return 1;
    }
    close(file_descriptor);
    return 0;
}