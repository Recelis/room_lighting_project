int pir = 40;
int led = 41;
int ldr = A8;

int x = 0; // green
int y = 0; // blue
int z = 0; // red
int inside_room = false;

int x_save = x;
int y_save = y;
int z_save = z;


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
  randomSeed(analogRead(ldr));
  x = random(0, 255);
  y = random(0, 255);
  z = random(0, 255);

  x_save = x;
  y_save = y;
  z_save = z; 
//  pinMode(ldr, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  analogWrite(22, z);
  analogWrite(23, x);
  analogWrite(24, y);

  analogWrite(25, z);
  analogWrite(26, x);
  analogWrite(27, y);

  analogWrite(28, z);
  analogWrite(29, x);
  analogWrite(30, y);

  analogWrite(31, z);
  analogWrite(32, x);
  analogWrite(33, y);

  analogWrite(34, z);
  analogWrite(35, x);
  analogWrite(36, y);

  analogWrite(37, z);
  analogWrite(38, x);
  analogWrite(39, y);

  int pirRead = digitalRead(pir);
  int ldrRead = analogRead(ldr);
  
  Serial.print("pir is ");
  Serial.println(pirRead);

  Serial.print("ldr is ");
  Serial.println(ldrRead);
  if (inside_room)
  {
    x_save = x;
    y_save = y;
    z_save = z;
    x = 150;
    y = 105;
    z = 0;
  }
  else 
  {
    int ranSpeed = random(0, 10);
    Serial.print("random speed");
    Serial.println(ranSpeed);
    x = x_save;
    y = y_save;
    z = z_save; 
    x = x + ranSpeed;
    y = y + ranSpeed;
    z = z + ranSpeed;
    
    if (x >= 255)
      x = 0;
    if (y >= 255)
      y = 0;
    if (z >= 255)
      z = 0;
    x_save = x;
    y_save = y;
    z_save = z;
  }
  if (pirRead == 1){
    
    inside_room = true;
    if (ldrRead < 500) {
      digitalWrite(led, HIGH);
    } else {
      digitalWrite(led, LOW);
    }
  } else {
    inside_room = false;
    digitalWrite(led,LOW);
  }
  Serial.println(x);
  Serial.println(y);
  Serial.println(z);
  delay(0);
}
