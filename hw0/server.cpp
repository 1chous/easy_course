#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>


int main() {
    int file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (file_descriptor == -1) {
        std::cerr << "Problems with socket creation" << std::endl;
        return 1;
    }

    struct sockaddr_in addr = {};
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8080);
    addr.sin_addr.s_addr = htonl(INADDR_ANY);

    int was_bind = bind(file_descriptor, (struct sockaddr *)&addr, sizeof(addr));
    if (was_bind == -1) {
        std::cerr << "Problems with bind" << std::endl;
        return 1;
    }

    int was_listen = listen(file_descriptor, 5);
    if (was_listen == -1) {
        std::cerr << "Problems with listening" << std::endl;
        return 1;
    }
    return 0;
}