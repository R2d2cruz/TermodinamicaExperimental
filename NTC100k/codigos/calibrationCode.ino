#define RB 97800.0
#define VT 5.01
#define LED 3
#define termoRes A5


/*
 * 100k = 97.3 k
 * 10k = 9.84k
 * 
 * 
 * 10K:
 * 90c = 80 bit 915.73ohm
 * 0c = 770 bit 41770.76 ohm 
 * 
 * 
 * 100k:
 * 0c = 736 bit 332479.62
 * 90c = 80 bit 8932.86
 * 
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
  Serial.println(vV(v));
}
