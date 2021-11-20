#ifndef MQTT_ALL_EARS
#define MQTT_ALL_EARS

#include <PubSubClient.h>

#define MQTT_SERVER "192.168.1.74"

#define CLIENT_ID "AllEarsClient"
#define MESSAGE_TOPIC "message"
#define VIBRATE_TOPIC "vibrate"


typedef std::function<void(char *)> handler;
void setup_mqtt(handler handle_vibrate,
                handler handle_message);
void mqtt_loop();
void getMessageFromPayload(char* message, 
                            byte *payload, 
                            unsigned int length);

#endif