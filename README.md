### CPSC 581 - Project 3

Arduino Based Project where we aim to solve an everyday problem.
Our chose every day problem applies particularly to deaf and
hard of hearing people.

# I Am all Ears

Source code for the D1 Mini board with the espressif8266 platform.
Using Arduino framework.


## Dependencies

- ESP8266WiFi
- Wire
- LiquidCrystal_I2C
- PubSubClient

## Custom libraries

Within `lib` you will find four libraries: `wifi`, `mqtt`, `lcd`, and `vibrate`. 
They provide functionality for dealing with their respective fields.

Each library has it's configuration definitions within their respective header file.

### `wifi` - `lib/wifi`

Simple library that continously attempts to connect to the wifi.
Define `SSID` and `PASSPHRASE` accordingly.

### `mqtt` - `lib/mqtt`

Used to connect to a mqtt server, and subscribe to two channels: one for messages to display on the lcd, and the other for a direction in which to vibrate.
Define `MQTT_SERVER` and `MQTT_PORT` accordingly.

#### Server Setup

Utilize `MESSAGE_TOPIC` and `VIBRATE_TOPIC` to name the topic channels
accordingly.

The directions available for vibrate are:

- `up`
- `down`
- `middle`

send messages to the `VIBRATE_TOPIC` topic accordingly.

### `lcd` - `lib/lcd`

Used to print messages to the LCD screen. 

### `vibrate` - `lib/vibrate`

Used to vibrate the motor.