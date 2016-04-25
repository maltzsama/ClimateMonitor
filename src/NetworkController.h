#include <Ethernet.h>
#include <EthernetClient.h>
#include <PubSubClient.h>
#include <Arduino.h>

enum NetworkStatus{
  NetworkError = 0,
  NetworkSucess = 1,
  NetworkRenewed = 2
};

class NetworkController {
  private:
    EthernetClient network;
    PubSubClient client;

  public:
    String getIPAddress();
    int mantainConnection();
    bool connect();
};
