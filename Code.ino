int pin_A1 = 2;
int pin_A2 = 3;
int pin_B1 = 4;
int pin_B2 = 5;
int A_PWM = 9;
int B_PWM = 10;
int speed = 180;
int speed1 = 0;
int speed2 = 0;
char x;

void setup() {
  Serial.begin(9600);
  pinMode(pin_A1, OUTPUT);
  pinMode(pin_A2, OUTPUT);
  pinMode(pin_B1, OUTPUT);
  pinMode(pin_B2, OUTPUT);
  pinMode(A_PWM, OUTPUT);
  pinMode(B_PWM, OUTPUT);
}

void loop() {
  if (Serial.available()) {
    x = Serial.read();
  }

  speed1 = speed;
  speed2 = speed;

  if (x == 'S' || x == 'R' || x == 'D') {
    speed1 = 0;
  } else if (x == 'I' || x == 'J') {
    speed1 = 0.5 * speed;
  }

  if (x == 'S' || x == 'L' || x == 'D') {
    speed2 = 0;
  } else if (x == 'G' || x == 'H') {
    speed2 = 0.5 * speed;
  }

  analogWrite(A_PWM, speed1);
  analogWrite(B_PWM, speed2);

  if (x == 'B' || x == 'H' || x == 'J' || x == 'S') {
    backward();
  } else if (x == 'F' || x == 'L' || x == 'R' || x == 'G' || x == 'I') {
    forward();
  }

  if (x == '0') {
    speed = 0;
  } else if (x == '1') {
    speed = 100;
  } else if (x == '2') {
    speed = 120;
  } else if (x == '3') {
    speed = 140;
  } else if (x == '4') {
    speed = 160;
  } else if (x == '5') {
    speed = 180;
  } else if (x == '6') {
    speed = 200;
  } else if (x == '7') {
    speed = 220;
  } else if (x == '8') {
    speed = 240;
  } else if (x == '9') {
    speed = 250;
  }
}


void forward() {
  digitalWrite(pin_A1, HIGH);
  digitalWrite(pin_A2, LOW);
  digitalWrite(pin_B1, HIGH);
  digitalWrite(pin_B2, LOW);
}

void backward() {
  digitalWrite(pin_A1, LOW);
  digitalWrite(pin_A2, HIGH);
  digitalWrite(pin_B1, LOW);
  digitalWrite(pin_B2, HIGH);
}
