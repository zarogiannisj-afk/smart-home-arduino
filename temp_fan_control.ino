// C++ code
int tmpPin = A0;    // TMP36 στο pin A0
int motorPin = 9;   // Motor στο pin 9
float temperature;

void setup() {
  pinMode(motorPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // Διάβασε τον TMP36
  int reading = analogRead(tmpPin);
  
  // Μετατροπή σε βαθμούς Celsius
  float voltage = reading * (5.0 / 1023.0);
  temperature = (voltage - 0.5) * 100;
  
  Serial.print("Temperature: ");
  Serial.println(temperature);
  
  // Αν θερμοκρασία πάνω από 35°C → άναψε motor
  if (temperature > 35) {
    analogWrite(motorPin, 50); // μειώνουμε από 100 σε 50
} else {
    analogWrite(motorPin, 0);
}
  
  delay(1000);
}
