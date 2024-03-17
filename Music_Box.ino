/************************************************************************************************************************************
                                
                                   
                                   Arduino-based Monophonic Synthesizer 

                                   By Brett Anley 
                                   
*************************************************************************************************************************************/


void DBGT();// function 

const int altaveu = 2; // Speaker on Pin 2 

const int BUTTON = 4; //The Button is connected to pin 4
const int BUTTON2 = 7; //The Button is connected to pin 7
const int BUTTON3 = 8; //The Button is connected to pin 8
const int BUTTON4 = 10; //The Button is connected to pin 10
const int BUTTON5 = 12; //The Button is connected to pin 12
const int BUTTON6 = 13; //The Button is connected to pin 13


const int SOFT_POT_PIN = 0; // Pin connected to softpot wiper
const int GRAPH_LENGTH = 40; // Length of line graph
int hz; // Used for Green Button 
int hz2;  // Used for Red Button 
int hz3; // Used for Blue Button 
int hz4; // Used for Yellow Button 
int hz5; // Used for Green 2 Button 

void setup() 
{
 Serial.begin(9600); //Start Serial Communication
 pinMode(altaveu, OUTPUT); // Set speakerPin as an output 
 pinMode (BUTTON, INPUT); //Set button as input 
 pinMode (BUTTON2, INPUT); //Set button as input 
 pinMode (BUTTON3, INPUT); //Set button as input 
 pinMode (BUTTON4, INPUT); //Set button as input 
 pinMode (BUTTON5, INPUT); //Set button as input 
 pinMode (BUTTON6, INPUT); //Set button as input 
 pinMode(SOFT_POT_PIN, INPUT);
}

void loop() 
{
 
  int softPotADC = analogRead(SOFT_POT_PIN); // Read in the soft pot's ADC value
 
 if ( softPotADC >= 0 && softPotADC <= 60)
  {
    hz = 131; // Used for Green Button 
    hz2 = 956 ; // Used for Red Button 
    hz3 = 131; // Used for Blue Button 
    hz4 = 500; // Used for Yellow Button 
    hz5 = 131; // Used for Green 2 Button 
  }


  if (softPotADC >= 100 && softPotADC <= 180)
  {
    hz = 393; // Used for Green Button 
    hz2 = 1014 ; // Used for Red Button 
    hz3 =  262;// Used for Blue Button 
    hz4 = 1000; // Used for Yellow Button 
    hz5 = 262; // Used for Green 2 Button 
  }
  
   if ( softPotADC >= 210 && softPotADC <= 300)
  {
    hz = 786; // Used for Green Button 
    hz2 = 1136 ; // Used for Red Button 
    hz3 =  393;// Used for Blue Button 
    hz4 = 1500; // Used for Yellow Button 
    hz5 = 393; // Used for Green 2 Button 
  }

 if (softPotADC >= 320 && softPotADC <= 430)
  {
    hz = 1479; // Used for Green Button 
    hz2 = 1275;  // Used for Red Button 
    hz3 =  524;// Used for Blue Button 
    hz4 = 2000; // Used for Yellow Button 
    hz5 = 524; // Used for Green 2 Button 
  }

 if ( softPotADC >= 450 && softPotADC <= 650)
  {
    hz = 2000; // Used for Green Button 
    hz2 =1432 ; // Used for Red Button 
    hz3 = 655; // Used for Blue Button 
    hz4 = 2500; // Used for Yellow Button 
    hz5 = 655; // Used for Green 2 Button 
  }

 if ( softPotADC >= 690 && softPotADC <= 1023)
  {
    hz = 3333; // Used for Green Button 
    hz2 = 1519 ;// Used for Red Button 
    hz3 = 786; // Used for Blue Button 
    hz4 = 3500; // Used for Yellow Button 
    hz5 = 786; // Used for Green 2 Button 
  }


/****************************************  Print a line graph: Used for calibration and postion testing of softPot******************************
   int softPotPosition = map(softPotADC, 0, 1023, 0, GRAPH_LENGTH); // Map the 0-1023 value to 0-40
  Serial.print("<"); // Starting end
  for (int i=0; i<GRAPH_LENGTH; i++)
  {
    if (i == softPotPosition) Serial.print("|");
    else Serial.print("-");
  }
  Serial.println("> (" + String(softPotADC) + ")");

  delay(500);

/**********************************************************************************************************/
  
if (digitalRead(BUTTON) == LOW)
 {
 digitalWrite(altaveu, LOW);
 }
 else
 {
 digitalWrite(altaveu, HIGH);

  DBGT(); // Calls on the DBGT function 
 }



if (digitalRead(BUTTON2) == LOW)
 {
 digitalWrite(altaveu, LOW);
 }
 else
 {
 digitalWrite(altaveu, HIGH);

   tone(altaveu, hz, 100);
   delay (100);
   noTone(altaveu);
 
    } 
   
 
if (digitalRead(BUTTON3) == LOW)
 {
 digitalWrite(altaveu, LOW);
 }
 else
 {
 digitalWrite(altaveu, HIGH);

   tone(altaveu, hz2, 100);
   delay (500);
   noTone(altaveu);
 
    } 

if (digitalRead(BUTTON4) == LOW)
 {
 digitalWrite(altaveu, LOW);
 }
 else
 {
 digitalWrite(altaveu, HIGH);

   tone(altaveu, hz3,100);
   delay (500);
   noTone(altaveu);
 
    } 

if (digitalRead(BUTTON5) == LOW)
 {
 digitalWrite(altaveu, LOW);
 }
 else
 {
 digitalWrite(altaveu, HIGH);

   tone(altaveu, hz4 );
   delay (700);
   noTone(altaveu);
 
    } 

   if (digitalRead(BUTTON6) == LOW)
 {
 digitalWrite(altaveu, LOW);
 }
 else
 {
 digitalWrite(altaveu, HIGH);

   tone(altaveu, hz5,100 );
   delay (200);
   noTone(altaveu);
 
 
   } 
   
}
