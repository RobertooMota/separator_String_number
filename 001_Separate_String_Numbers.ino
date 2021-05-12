String words = "";
String value = "";
char info;

bool newInfo = false;

void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available()) separate();

}

void separate()
{
  while (Serial.available() > 0)
  {
    delay(10);
    info = Serial.read();

    if (isAlpha(info))
    {
      words += info;
    }
    else if (isAlphaNumeric(info))
    {
      value += info;
    }
    newInfo = true;
  }

  if (newInfo) newWords();

}

void newWords() {
  value.toInt();
  Serial.print("words: " + words + "   Numero: " + value + "\n\n");

  words = "";
  value = "";
  newInfo = false;
}
