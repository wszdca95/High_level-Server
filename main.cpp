#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <vector>

#include "log.h"
#include "conn.h"
#include "mgr.h"
#include "processpool.h"

using std::vector;

static const char* version = "1.0";
static void usage(const char* prog)
{
    log(LOG_INFO,__FILE__,__LINE__,"usage:%s [-h] [-v] [-f config_file]",prog);
}

int main(int argc,char* argv[])
{
    char cfg_file[1024];
    memset(cfg_file,'\0',100);
    int option;
    while((option=getopt(argc,argv,"f:xvh"))!=-1)
    {
        switch(option)
        {
            case 'x':
            {
                set_loglevel(LOG_DEBUG);
                break;
            }
        }
    }
}