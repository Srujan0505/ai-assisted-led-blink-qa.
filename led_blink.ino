const uint8_t LED_PIN = 13;
const unsigned long ON_TIME_MS  = 500;
const unsigned long OFF_TIME_MS = 500;

unsigned long previousMillis = 0;
bool ledState = LOW;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
}

void loop() {
  unsigned long now = millis();
  unsigned long interval = ledState ? ON_TIME_MS : OFF_TIME_MS;

  if (now - previousMillis >= interval) {
    previousMillis = now;
    ledState = !ledState;
    digitalWrite(LED_PIN, ledState);
  }
}
