#ifndef CONN_H
#define CONN_H

#include<arpa/inet.h>
#include<fdwrapper.h>

class conn
{
public:
    conn();
    ~conn();
    void init_client(int sockfd,const sockaddr_in & client_addr);
    void init_server(int sockfd,const sockaddr_in & server_addr);
    void reset();
    RET_CODE read_client();
    RET_CODE write_client();
    RET_CODE read_server();
    RET_CODE write_server();
public:
    static const int BUF_SIZE=2048;
    char* m_clt_buf;
    int m_clt_read_idx;
    int m_clt_write_idx;
    sockaddr_in m_clt_address;
    int m_cltfd;

    char * m_srv_buf;
    int m_srv_read_idx;
    int m_srv_write_idx;
    sockaddr_in m_srv_address;
    int srvfd;

    bool m_srv_closed;
}

#endif