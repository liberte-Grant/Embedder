#ifndef NETWORK_H
#define NETWORK_H

#include <stdint.h>
#include <functional>
#include <zephyr/net/net_if.h>
#include <zephyr/net/net_mgmt.h>

class Network {
public:
  static Network& getInstance();

  void start();
  void onGotIP(std::function<void(const char *)> callback);

  std::function<void(const char *)> callback;

private:
  Network();
  ~Network();

  static Network instance;
  struct net_mgmt_event_callback mgmtEventCb;
  struct net_if *netIface;
};

#endif // NETWORK_H
