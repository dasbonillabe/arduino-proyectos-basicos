// Autor: Santiago Bonilla

const int sensorPin = A0;
const float baselineTemp = 20.0;

void setup() {
  Serial.begin(9600);  // Abre un puerto en serie 9600 bits por segundo
  for (int pinNumber = 2; pinNumber<5; pinNumber++){
    pinMode(pinNumber,OUTPUT);
    digitalWrite(pinNumber,LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor value: ");
  Serial.print(sensorVal);

  // Convierte la lectura del ADC a voltaje
  float voltage = sensorVal*(5.0/1024);
  Serial.print(" , Volts: ");
  Serial.print(voltage);

  // Convierte el voltaje a temperatura en grados
  // float temperature = (voltage - 0.5)*100.0;
  float temperature = 36.0*(voltage - 5.0)+125.0;
  Serial.print(", degrees C: ");
  Serial.println(temperature);

  if(temperature < baselineTemp){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  } else if(temperature >= baselineTemp+2 && temperature < baselineTemp+4) {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);    
  } else if(temperature >= baselineTemp+4 && temperature < baselineTemp+6) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);    
  } else if(temperature >= baselineTemp+6) {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);    
  }
  delay(1);
}
