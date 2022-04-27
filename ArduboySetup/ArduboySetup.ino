int AButton = 7;
int BButton = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(AButton, INPUT);
  pinMode(BButton, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(digitalRead(AButton));
}
