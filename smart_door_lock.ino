// C++ code
//
#include <Keypad.h>
#include <Servo.h>

// Servo
Servo myServo;

// Keypad
const byte ROWS = 4;
const byte COLS = 4;
char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {11, 12, 13, 6};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// HC-SR04
int trigPin = 9;
int echoPin = 10;
int mosPin = 8;

String inputCode = "";
String correctCode = "1234";
bool doorOpen = false;

void setup() {
  myServo.attach(7);
  myServo.write(0); // κλειστό
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(mosPin, OUTPUT);
  Serial.begin(9600);
}

bool waitingForCode = false;

void loop() {
  if (!waitingForCode) {
    // Μέτρηση απόστασης
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2;

    Serial.print("Distance: ");
    Serial.println(distance);

    if (distance < 50 && distance > 0) {
      Serial.println("Enter code:");
      waitingForCode = true;  // σταμάτα μετρήσεις
      inputCode = "";
    }
  } else {
    // Περιμένει κωδικό
    char key = keypad.getKey();
    if (key) {
      inputCode += key;
      Serial.println(inputCode);

      if (inputCode.length() == 4) {
        if (inputCode == correctCode) {
          Serial.println("Correct! Opening...");
          digitalWrite(mosPin, HIGH);
          myServo.write(90);
          delay(3000);
          myServo.write(0);
          digitalWrite(mosPin, LOW);
        } else {
          Serial.println("Wrong code!");
        }
        inputCode = "";
        waitingForCode = false;  // ξαναρχίζει μετρήσεις
      }
    }
  }
  delay(100);
}
