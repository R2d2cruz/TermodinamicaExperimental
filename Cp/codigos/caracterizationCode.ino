#define RB 9730.0
#define VT 4.65
#define LED 3
#define termoRes A5
 
int v = 0;
int vB;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  vB = analogRead(termoRes);
  digitalWrite(LED, HIGH);
}

float vV(float v)
{
  return (v * 5.0 / 1023.0);
}

float time()
{
  return (millis() / 1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  v = analogRead(termoRes);
  Serial.print(time());
  Serial.print("\t");
  Serial.println(vV(v));
  delay(500);
}
