#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <stdint.h>
#include <stdbool.h>
#include <functional>

#include <zephyr/net/net_ip.h>
#include <zephyr/net/http/client.h>

static constexpr uint32_t HTTP_CLIENT_RESPONSE_BUFFER_SIZE = 512;

typedef struct {
  uint8_t *header;
  uint32_t headerLength;
  uint8_t *body;
  uint32_t bodyLength;
  uint32_t totalSize;
  bool isComplete;
  uint16_t statusCode;
} HttpResponse;

class HttpClient {

public:
  std::function<void(HttpResponse *response)> callback;

  HttpClient(char *server, uint16_t port = 80);
  ~HttpClient();
  int get(const char *endpoint, std::function<void(HttpResponse *)> callback);
  int post(const char *endpoint,
           const char *data,
           uint32_t length,
           std::function<void(HttpResponse *)> callback);

private:
  int sock;
  char *server;
  uint16_t port;
  struct sockaddr socketAddress;
  uint8_t responseBuffer[HTTP_CLIENT_RESPONSE_BUFFER_SIZE];

};

#endif // HTTP_CLIENT_H
