int pir = 40;
int led = 41;
int ldr = A8;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);

  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);

  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);
  pinMode(30, OUTPUT);

  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);

  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);

  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);

  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);
//  pinMode(ldr, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(22, 0);
  analogWrite(23, 0);
  analogWrite(24, 0);

  analogWrite(25, 0);
  analogWrite(26, 0);
  analogWrite(27, 0);

  analogWrite(28, 0);
  analogWrite(29, 0);
  analogWrite(30, 0);

  analogWrite(31, 0);
  analogWrite(32, 0);
  analogWrite(33, 0);

  analogWrite(34, 0);
  analogWrite(35, 0);
  analogWrite(36, 0);

  analogWrite(37, 0);
  analogWrite(38, 0);
  analogWrite(39, 0);

  int pirRead = digitalRead(pir);
  int ldrRead = analogRead(ldr);
  
  Serial.print("pir is ");
  Serial.println(pirRead);

  Serial.print("ldr is ");
  Serial.println(ldrRead);

  if (pirRead == 1){
    if (ldrRead < 500) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  } else {
    digitalWrite(led,LOW);
  }
  delay(500);
}
