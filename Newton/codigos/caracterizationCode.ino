#define pt A5
#define term A4


void setup() {
  pinMode(6, OUTPUT);
  digitalWrite(6, HIGH);
  
  pinMode(4, OUTPUT);
  digitalWrite(4, HIGH);
  Serial.begin(9600);
}

float time()
{
  return (millis() / 1000.0);
}

void loop() {
  Serial.println(time());
  Serial.print("\t");
  Serial.print(analogRead(pt));
  Serial.print("\t");
  Serial.print(analogRead(term));
  Serial.print("\n");
  delay(500);
}