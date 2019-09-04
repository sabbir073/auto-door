int input1 = A3; //input pin for switch and signal module
int output1 = 11; // door close signal
int output2 = 12; //door open signal
int val = 0; //variable to calculate analogdata
int led = 13;

void setup() 
{
  Serial.begin(9600); // declared serial
  pinMode(input1, INPUT); // set analogpin input mood as input
  pinMode(output1, OUTPUT); // set door close signal as output
  pinMode(output2, OUTPUT); //set door open signal as output
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() 
{
  val = analogRead(input1); //reading the value of analog pin
  Serial.println(val);
  delay(50); // little delay to maintain signal
  if(val > 500) //calculating analog value
  {
    digitalWrite(output2, LOW);
    delay(50); //little delay to maintain signal
    digitalWrite(output1, HIGH); //if analog pin sending signal turn on door close
    delay(5000); //little delay to maintain signal
    digitalWrite(output1, LOW);
    delay(50); //little delay to maintain signal
  }
  else if (val < 500)
  {
    digitalWrite(output1, LOW);
    delay(50); //little delay to maintain signal
    digitalWrite(output2, HIGH); //if analog pin sending signal turn off door close
    delay(5000); //little delay to maintain signal
    digitalWrite(output2, LOW);
    delay(50); //little delay to maintain signal
  }
}
