// Motor 1 control pins
const int IN1 = 8;
const int IN2 = 9;
const int ENA = 10;  // PWM capable pin

// Motor 2 control pins
const int IN3 = 13;
const int IN4 = 12;
const int ENB = 11;  // PWM capable pin

const int speed = 255; // Max speed

void setup() {
  // Set motor pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);

  // Start serial communication (HC-05 connected to Arduino TX/RX)
  Serial.begin(9600);
  Serial.println("HC-05 ready. Send commands: F=forward, B=backward, L=left, R=right, S=stop, +=speed up, -=slow down");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();

    switch (command) {
      case 'F':
        Serial.println("Moving Forward");
        motorForward(speed);
        break;
      case 'B':
        Serial.println("Moving Backward");
        motorBackward(speed);
        break;
      case 'L':
        Serial.println("Turning Left");
        motorLeft(speed);
        break;
      case 'R':
        Serial.println("Turning Right");
        motorRight(speed);
        break;
      case 'S':
        Serial.println("Stopping");
        motorStop();
        break;
      case '+':
        Serial.println("Speed Up (not implemented, fixed max speed)");
        break;
      case '-':
        Serial.println("Speed Down (not implemented, fixed max speed)");
        break;
      default:
        Serial.println("Invalid command! Use F,B,L,R,S,+,-");
        break;
    }
  }
}

// Move both motors forward
void motorForward(int spd) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, spd);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, spd);
}

// Move both motors backward
void motorBackward(int spd) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, spd);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, spd);
}

// Turn left (Motor1 backward, Motor2 forward)
void motorLeft(int spd) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, spd);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, spd);
}

// Turn right (Motor1 forward, Motor2 backward)
void motorRight(int spd) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, spd);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, spd);
}

// Stop both motors
void motorStop() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 0);
}
