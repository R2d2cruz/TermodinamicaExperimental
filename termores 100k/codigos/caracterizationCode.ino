#define RB 97800.0
#define VT 5.01
#define LED 3
#define termoRes A5
#define GRACETIME 60

int v = 0;
int vB;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
  vB = analogRead(analogRead(termoRes));
  digitalWrite(LED, LOW);
}

float vV(float v)
{
  return (v * 5.0 / 1023.0);
}

float rT(float v)
{
  float vp = vV(v);
  return(RB * vp / (VT - vp));
}

float time()
{
  return ((millis() / 100)/10.0);
}

void loop() {
  // put your main code here, to run repeatedly:
  v = analogRead(termoRes);
  Serial.print(time());
  Serial.print("\t");
  Serial.println(v);
  if(time() > GRACETIME && v < vB)
  {
    Serial.println("FINALE");
    digitalWrite(LED, HIGH);
    delay(120000);
  }
  delay(500);
}
