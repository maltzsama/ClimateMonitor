#include "NetworkController.h"

byte mac[] = {0x00, 0xAA, 0xBB, 0xCC, 0xDE, 0x02};

bool NetworkController::connect(){
  if (Ethernet.begin(mac) == 0) {
    return false;
  }
  return true;
}

int NetworkController::mantainConnection(){
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
