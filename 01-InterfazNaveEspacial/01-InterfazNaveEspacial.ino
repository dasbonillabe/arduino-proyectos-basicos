// Autor: Santiago Bonilla

int switchState = 0;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(2,INPUT);
}

void loop() {
  switchState = digitalRead(2);

  if (switchState == LOW) {
    // El botón no está pulsado
    digitalWrite(3,HIGH);  // LED verde
    digitalWrite(4,LOW);  // LED rojo
    digitalWrite(5,LOW);  // LED rojo
  }
  else {
    // El botón está pulsado
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);

    delay(250);  // Espera un cuarto de segundo
    
    // Permuta los LEDs
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);

    delay(250);  // Espera un cuarto de segundo
  }
}  // Vuelve al inicio del bucle
