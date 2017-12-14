#ifndef MY_RTSP_SESSION_H
#define MY_RTSP_SESSION_H

#include <stdint.h>

#define REAL_HEADER_SIZE 4096

struct real_rtsp_session_t {
  /* receive buffer */
  uint8_t *recv;
  int recv_size;
  int recv_read;

  /* header buffer */
  uint8_t header[REAL_HEADER_SIZE];
  int header_len;
  int header_read;

  int rdteof;

  int rdt_rawdata;
};

typedef struct rtsp_session_s rtsp_session_t;

rtsp_session_t *rtsp_session_start(int fd, char **mrl, char *path, char *host,
  int port, int *redir, uint32_t bandwidth, char *user, char *pass);

int rtsp_session_read(rtsp_session_t *session, char *data, int len);

void rtsp_session_end(rtsp_session_t *session);

#endif /* MY_RTSP_SESSION_H */
