#include<exception>
#include<errno.h>
#include<string.h>
#include"conn.h"
#include"log.h"
#include"fdwrapper.h"

conn::conn()
{
    m_srvfd=-1;
    m_clt_buf=new char [BUF_SIZE];
    if(!m_clt_buf)
    {
        throw std::exception();
    }
    m_srv_buf=new char [BUF_SIZE];
    if(!m_srv_buf)
    {
        throw std::exception();
    }
    reset();
}

conn::~conn()
{
    delete [] m_clt_buf;
    delete [] m_srv_buf;
}

void conn::init_client(int sockfd,const sockaddr_in& client_addr)
{
    m_clt_buf=sockfd;
    m_clt_address=client_addr;
}

void conn::init_server(int sockfd,const sockaddr_in& server_addr)
{
    m_srv_buf=sockfd;
    m_clt_address=server_addr;
}

void conn::reset()
{
    m_clt_read_idx=0;
    m_clt_write_idx=0;
    m_srv_read_idx=0;
    m_srv_write_idx=0;
    m_srv_closed=false;
    memset(m_clt_buf,'\0',BUF_SIZE);
    memset(m_srv_buf,'\0',BUF_SIZE);
}

RET_CODE conn:read_clt()
{
    int bytes_read=0;
    while(true){
        if(m_clt_read_idx>=BUF_SIZE)
        {
            log(LOG_ERROR,__FILE__,__LINE__,"%s","")
        }
    }
    
}