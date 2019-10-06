byte sensorPin=A0, outputPin1=11, outputPin2=10, closeSwitch=9, openSwitch=8, controlPin=7;
int sensorRead=0, outputRead1=0, outputRead2=0, closeRead=0, openRead=0, control=0;
int in1=0, dtime=5000;
int in=0;
void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(closeSwitch, INPUT_PULLUP);
  pinMode(openSwitch, INPUT_PULLUP);
  pinMode(controlPin, INPUT_PULLUP);
  pinMode(2, OUTPUT);
  digitalWrite(2, LOW);
}
void loop()
{
  sensorRead=analogRead(sensorPin);
  control=digitalRead(controlPin);
  if(sensorRead<600 && in1==0 && in==0) 
  {
    delay(dtime);
    openGate();
    in1=1;
  }
  else if(sensorRead>600 && in1==1)
  {
    closeGate();
    in1=0;
  }

  if(control==0 && in==0)
  {
    delay(200);
    openGate();
    in=1;
  }
  else if(control==0 && in==1)
  {
    delay(200);
    closeGate();
    in=0;
  }
 
}

void openGate()
{
  openRead=digitalRead(openSwitch);
    while(openRead==HIGH) 
    {
      digitalWrite(outputPin1, HIGH),
      digitalWrite(outputPin2, LOW);
      openRead=digitalRead(openSwitch);
    }
    digitalWrite(outputPin1,LOW);
}

void closeGate()
{
  closeRead=digitalRead(closeSwitch);
    while(closeRead==HIGH) 
    {
      digitalWrite(outputPin1, LOW),
      digitalWrite(outputPin2, HIGH);
      closeRead=digitalRead(closeSwitch);
    }
    digitalWrite(outputPin2,LOW);
}
