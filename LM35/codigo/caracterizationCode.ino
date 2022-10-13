// C++ code
//

/*
La proporcion del lm35 es de 500/1023 v/c, ya que en la
simulacion se usa un lm36, no es la misma proporcion. 
*/
float proporcion = 500.0/1023.0;

void setup()
{
  Serial.begin(9600);
}

float t(int v)
{
  return (proporcion * v);
}

float time()
{
  return (millis() / 1000.0);
}

void loop()
{
  Serial.print(time());
  Serial.print("	");
  Serial.println(t(analogRead(A0)));
  delay(100); // Delay a little bit to improve simulation performance
}