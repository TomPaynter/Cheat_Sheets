#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <thread>


class TCP_Server {

private:
    int sockfd, newsockfd;
    socklen_t clilen;
    uint8_t rx_buffer[1000];
    int rx_buffer_pos;
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    std::mutex rx_buff_mut;
    std::thread tcp_listener;

public:
    TCP_Server(int portno) {
        sockfd =  socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0)
            std::cout << "TCP server: ERROR opening socket" << std::endl;

        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_addr.s_addr = INADDR_ANY;
        serv_addr.sin_port = htons(portno);

        if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
            std::cout << "TCP server: ERROR on binding" << std::endl;

        listen(sockfd,5);
        clilen = sizeof(cli_addr);
        std::cout <<"TCP server: waiting for connection "<<std::endl;

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);

        if (newsockfd < 0)
           std::cout <<"TCP server: ERROR on accept" << std::endl;

        std::cout <<"TCP server: got connection from " << inet_ntoa(cli_addr.sin_addr) << " port "
                                                    <<  (int) ntohs(cli_addr.sin_port) << std::endl;

        rx_buffer_pos = 0;

        std::thread tcp_listener_dummy(&TCP_Server::tcp_listen, this, newsockfd);
        tcp_listener.swap(tcp_listener_dummy);

    }

    ~TCP_Server() {
        close(newsockfd);
        close(sockfd);
        tcp_listener.join();
    }

    void tcp_listen(int socket) {
        uint8_t temp_buff[250], n;

        while(1) {
            n = read(socket, temp_buff, 250);
            rx_buff_mut.lock();
            std::memcpy(&rx_buffer[rx_buffer_pos], &temp_buff[0], n* sizeof(uint8_t));
            rx_buffer_pos = rx_buffer_pos + n;
            rx_buff_mut.unlock();
        }
    }

    uint8_t tcp_read(uint8_t *buffer) {

        rx_buff_mut.lock();
        int i = rx_buffer_pos;
        rx_buff_mut.unlock();

        if (i == 0) {
            return 0;
        }

        else {
            rx_buff_mut.lock();
            std::memcpy(buffer, rx_buffer, rx_buffer_pos * sizeof(uint8_t));
            int i = rx_buffer_pos;
            rx_buffer_pos = 0;
            rx_buff_mut.unlock();
            return i;
        }

    }

    void tcp_send(uint8_t *buffer, uint8_t length) {
        send(newsockfd, buffer, length, 0);
    }
};

/*
int main(int argc, char *argv[])
{
    TCP_Server tcp_server(9999);

    uint8_t bob[100] = "heyo!!!! :D";
    uint8_t jill[100];


    while(1) {
        //tcp_server.tcp_send(bob, 11);

        uint8_t n = tcp_server.tcp_read(jill);

        if (n > 0) {
            for(int u = 0; u < n; u++)
            std::cout << jill[u];

            std::cout << std::endl;
        }

       std::cout << "." << std::endl;

        usleep(5000000);
    }
}
*/