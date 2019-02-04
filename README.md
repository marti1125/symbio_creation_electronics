# Area de Electronica

Componentes
-----------

* Arduino
* NodeMCU
* Sensor Calidad Aire MQ135

![nodemcu](https://github.com/marti1125/symbio_creation_electronics/blob/master/esp8266_devkit_horizontal-01.png)


Mosquitto MQTT broker
----------------------

Algunas instrucciones para empezar

```
mosquitto -c /usr/local/etc/mosquitto/mosquitto.conf

brew services start mosquitto

mosquitto_sub -t "sensor/basura" -v

mosquitto_pub -t "sensor-basura" -m "ON"
```

**Recursos**

* [Primeros pasos MQTT](https://ricveal.com/blog/primeros-pasos-mqtt/)
* [Arduino MQTT](https://ricveal.com/blog/arduino-mqtt/)
* [NodeMCU MQTT Tutorial](https://www.teachmemicro.com/nodemcu-mqtt-tutorial/)
* [Tutorial sensores de gas MQ2, MQ3, MQ7 y MQ135](https://naylampmechatronics.com/blog/42_Tutorial-sensores-de-gas-MQ2-MQ3-MQ7-y-MQ13.html)


**Bibliotecas**

* [arduino-mqtt](https://github.com/256dpi/arduino-mqtt)
