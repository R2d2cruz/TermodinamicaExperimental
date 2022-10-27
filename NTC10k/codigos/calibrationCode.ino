#define RB 9730.0
#define VT 4.65
#define LED 3
#define termoRes A5


/*
 * 
 * 10K:
 * 90c = 80 bit 915.73ohm
 * 0c = 770 bit 41770.76 ohm 
 * 
 */


int v = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
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

void loop() {
  // put your main code here, to run repeatedly:
  v = analogRead(termoRes);
  Serial.print(v);
  Serial.print("\t");
  Serial.println(rT(v));
}
