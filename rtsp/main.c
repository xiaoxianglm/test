#include "mytcp.h"
#include "myrtsp.h"
#include "myrtsp_session.h"
#include "myrtsp_rtp.h"
#include <stdio.h>
#include <stdlib.h>

int strat()
{

	int fd = 0;
	rtsp_t *s;
	char host[32];
	char *mrl;
	char path[128];
	int port = 554;
	char *server;
	rtsp_session_t * rtsp_session;
	sprintf(host,"%s","192.168.1.11");
	mrl = (char *)malloc (128);
	sprintf(mrl,"%s","rtsp://192.168.1.11:554/user=admin_password=tlJwpbo6_channel=1_stream=0.sdp?real_stream");
	sprintf(path,"%s","/user=admin_password=tlJwpbo6_channel=1_stream=0.sdp?real_stream");

	fd = connect2Server(host,port);
	if(fd < 0)
	{
		printf("connect2Server error\n");
	}
	rtsp_session = rtsp_session_start(fd,&mrl,path,host,port,&port,0,"admin","admin");


	return 0;
}


int main(int argc,char *argv[])
{
	strat();
	return 0;
}
