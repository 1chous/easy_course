#include <iostream>
#include <sys/socket.h>
#include <unistd.h>


int main() {
    int file_descriptor = socket(AF_INET, SOCK_STREAM, 0);
    if (file_descriptor == -1) {
        std::cerr << "Problems with socket creation" << std::endl;
        return 1;
    }
    return 0;
}