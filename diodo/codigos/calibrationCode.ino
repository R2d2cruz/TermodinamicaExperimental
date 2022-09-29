#define VT 4.65
#define LED 3
#define termoRes A5

int v = 0;

void setup() {
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

float vV(float v)
{
  return (v * 5.0 / 1023.0);
}

void loop() {
  v = analogRead(termoRes);
  Serial.print(v);
  Serial.print("\t");
  Serial.println(vV(v));
}
