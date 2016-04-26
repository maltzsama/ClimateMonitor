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
    EthernetClient *networkCli;
    PubSubClient client;
    const String clientName;
    const String user;
    const String passwd;
    const IPAddress server;
    const uint16_t port;

  public:
    NetworkController() :
    clientName("arduinoClient-01"),
    user("admin"),
    passwd("admin"),
    server(192, 168, 1, 110),
    port(1883)
    { };

    static String getIPAddress();
    int mantainEthernetConnection();
    static bool connectEthernet();
    bool connectMqtt();
    static void callBackMqtt(char* topic, byte* payload, unsigned int length);
    bool reconnectMqtt();

};
