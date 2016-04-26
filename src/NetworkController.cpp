#include "NetworkController.h"

byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};

bool NetworkController::connectEthernet(){
  if (Ethernet.begin(mac) == 0) {
    return false;
  }
  return true;
}

int NetworkController::mantainEthernetConnection(){
  switch (Ethernet.maintain())
  {
    case 1:
      //renewed fail
      Serial.println("Error: renewed fail");
      return NetworkError;
      break;

    case 2:
      //renewed success
      Serial.println("Renewed success");
      getIPAddress();
      return NetworkRenewed;
      break;

    case 3:
      //rebind fail
      Serial.println("Error: rebind fail");
      return NetworkError;
      break;

    case 4:
      //rebind success
      Serial.println("Rebind success");

      //print your local IP address:
      getIPAddress();
      return NetworkSucess;
      break;

    default:
      return NetworkError;
      break;

  }
}

String NetworkController::getIPAddress(){
  String ipaddress;
  Serial.print("My IP address: ");
  for (byte thisByte = 0; thisByte < 4; thisByte++) {
    // print the value of each byte of the IP address:
    Serial.print(Ethernet.localIP()[thisByte], DEC);
    ipaddress += (Ethernet.localIP()[thisByte], DEC);
    Serial.print(".");
    ipaddress += '.';
  }
  Serial.println(ipaddress);
  return ipaddress;
}

bool NetworkController::connectMqtt(){
  NetworkController::connectEthernet();
  client.setServer(server, port);
  client.setCallback(NetworkController::callBackMqtt);

  return false;
}
void NetworkController::callBackMqtt(char* topic, byte* payload, unsigned int length){
  Serial.print("CallBack");
}

bool NetworkController::reconnectMqtt(){

  int idx = 0;
  while (!client.connected() || idx < 10) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient01","admin", "admin")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      client.publish("outTopic","hello world");
      // ... and resubscribe
      client.subscribe("inTopic");
      return true;
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      // delay(5000);
      return false;
    }
    idx++;
  }
}
