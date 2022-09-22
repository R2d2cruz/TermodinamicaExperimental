#define RB 9730.0
#define VT 4.65
#define LED 3
#define termoRes A5
#define GRADIENT -0.0022
#define SKY 0
#define BITSKY 41770.76
#define GRACETIME 60


/*
 * 10k = 9.84k
 * 
 * 
 * 10K:
 * 90c = 80 bit 915.73ohm
 * 0c = 770 bit 41770.76 ohm 
 * 
 */

 
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

float temp(float v)
{
  return ((GRADIENT * (rT(v) - BITSKY)) + SKY);
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
  Serial.println(temp(v));
  if(time() > GRACETIME && v < vB)
  {
    Serial.println("FINALE");
    digitalWrite(LED, HIGH);
    delay(120000);
  }
  delay(500);
}
