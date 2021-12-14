#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */  
#include <mqueue.h>
#include <sys/msg.h>
#include <sys/ipc.h>


int main( int argc, char const *argv[])
{
    int p1,p2,priority=0,msgid;
    char ch,buff1[50],buff2[20];
   p1= mq_open("/dictionary.txt",O_RDONLY);
    if(p1 == -1)
    {
        perror("error opening\n");
        exit(1);
    }
    
    p2=mq_open("destination.txt",O_WRONLY|O_RDONLY);
        if(msgrcv(msgid,buff2,&p1,ch,0)=='m')
       {
          write(p2,buff2,20);
        }

   close(p1);
   close(p2);
   return 0;
    
}