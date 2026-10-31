// LED Blink with configurable timing and serial logging
// Board: Arduino Uno

const uint8_t LED_PIN = 13;
const unsigned long ON_TIME_MS  = 500;
const unsigned long OFF_TIME_MS = 500;

unsigned long previousMillis = 0;
bool ledState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  Serial.begin(9600);
  Serial.println(F("LED blink started"));
}

void loop() {
  unsigned long now = millis();
  unsigned long interval = ledState ? ON_TIME_MS : OFF_TIME_MS;

  if (now - previousMillis >= interval) {
    previousMillis = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
    Serial.print(F("LED "));
    Serial.println(ledState ? F("ON") : F("OFF"));
  }
}
