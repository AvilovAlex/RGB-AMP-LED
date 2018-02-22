int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int curColor = 0;
int But = 0;
int prefBut = 0;
int redCh = 0;
int grCh = 0;
int blCh = 0;

void setup() {
  pinMode(A1, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void curInc()
{
  curColor = (curColor + 1) % 3;
}

void loop() {
  int c = map(analogRead(A1), 0, 670, 0, 255);
  analogWrite(redPin, redCh);
  analogWrite(greenPin, grCh);
  analogWrite(bluePin, blCh);

  But = digitalRead(8);
  if ((prefBut == 0) && (But == 1))
    curInc();
  prefBut = But;

  switch (curColor) {
    case 0:
      redCh = c;
      break;
    case 1:
      grCh = c;
      break;
    default:
      blCh = c;
  }
}
