#include <wifi.h>
#include "mqtt.h"

const char *mqtt_server = MQTT_SERVER;

PubSubClient client(espClient);

handler vibrate_handler;
handler message_handler;

void mqtt_hanlder(char *topic,
                  byte *payload,
                  unsigned int length)
{
  if (length == 0)
    return;

  char message[length + 1];
  getMessageFromPayload(message, payload, length);

  if (strcmp(topic, MESSAGE_TOPIC) == 0)
  {
    message_handler(message);
  }
  else if (strcmp(topic, VIBRATE_TOPIC) == 0)
  {
    vibrate_handler(message);
  }
}

void setup_mqtt(handler handle_vibrate,
                handler handle_message)
{  
  vibrate_handler = handle_vibrate;
  message_handler = handle_message;
  client.setServer(mqtt_server, MQTT_PORT);
  client.setCallback(mqtt_hanlder);
}

void reconnect()
{
  while (!client.connected())
  {
    String clientId = CLIENT_ID;
    if (client.connect(clientId.c_str()))
    {
      client.subscribe(MESSAGE_TOPIC);
      client.subscribe(VIBRATE_TOPIC);
    }
    else
    {
      delay(5000);
    }
  }
}

void mqtt_loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  client.loop();
}

void getMessageFromPayload(char *message, byte *payload, unsigned int length)
{
  for (unsigned int i = 0; i < length; i++)
  {
    message[i] = payload[i];
  }
  message[length] = '\0';
}
