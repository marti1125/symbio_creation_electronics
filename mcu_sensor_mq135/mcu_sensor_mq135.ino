int pin_mq = 13;
int pin_mq_a = 2;

int sensorValue;

void setup() { 
  Serial.begin(9600);
 // pinMode(pin_mq_a, INPUT);
}


void loop() {

  sensorValue = analogRead(0);       // read analog input pin 0

  float voltaje = sensorValue * (5.0 / 1023.0); //Convertimos la lectura en un valor de voltaje

  Serial.print("AirQua:");
  Serial.print(sensorValue);
  Serial.print("    voltaje:");
  Serial.println(voltaje);
  delay(100);
  
  
  /*boolean mq_estado = digitalRead(pin_mq);//Leemos el sensor
  if(mq_estado) //si la salida del sensor es 1
  {
    Serial.println("Sin presencia de alcohol");
  }
  else //si la salida del sensor es 0
  {
    Serial.println("Alcohol detectado");
  }
  delay(100);*/
  
  /*int adc_MQ = analogRead(pin_mq_a); //Lemos la salida analógica del MQ
  float voltaje = adc_MQ * (5.0 / 1023.0); //Convertimos la lectura en un valor de voltaje

  Serial.print("adc:");
  Serial.print(adc_MQ);
  Serial.print("    voltaje:");
  Serial.println(voltaje);
  delay(100);*/

  /*int adc_MQ = analogRead(pin_mq_a); //Lemos la salida analógica  del MQ
  float voltaje = adc_MQ * (5.0 / 1023.0); //Convertimos la lectura en un valor de voltaje
  float Rs=1000*((5-voltaje)/voltaje);  //Calculamos Rs con un RL de 1k
  double alcohol=0.4091*pow(Rs/5463, -1.497); // calculamos la concentración  de alcohol con la ecuación obtenida.
  //-------Enviamos los valores por el puerto serial------------
  Serial.print("adc:");
  Serial.print(adc_MQ);
  Serial.print("    voltaje:");
  Serial.print(voltaje);
  Serial.print("    Rs:");
  Serial.print(Rs);
  Serial.print("    alcohol:");
  Serial.print(alcohol);
  Serial.println("mg/L");
  delay(100);*/
  
  
}
