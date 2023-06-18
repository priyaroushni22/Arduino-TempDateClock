#define datapin1 3
#define outDataCLKpin1 4
#define inDataCLKpin1 2

#define datapin2 6
#define outDataCLKpin2 7
#define inDataCLKpin2 5

#define datapin3 9
#define outDataCLKpin3 10
#define inDataCLKpin3 8

#define datapin4 12
#define outDataCLKpin4 13
#define inDataCLKpin4 11

#define datapin5 A4
#define outDataCLKpin5 A3
#define inDataCLKpin5 A5

#define datapin6 A1
#define outDataCLKpin6 A0
#define inDataCLKpin6 A2
void setup()
{
  pinMode(   datapin1    , OUTPUT);
  pinMode(outDataCLKpin1 , OUTPUT);
  pinMode(inDataCLKpin1  , OUTPUT);
  
  pinMode(   datapin2    , OUTPUT);
  pinMode(outDataCLKpin2 , OUTPUT);
  pinMode(inDataCLKpin2  , OUTPUT);
  
  pinMode(   datapin3    , OUTPUT);
  pinMode(outDataCLKpin3 , OUTPUT);
  pinMode(inDataCLKpin3  , OUTPUT);
  
  pinMode(   datapin4    , OUTPUT);
  pinMode(outDataCLKpin4 , OUTPUT);
  pinMode(inDataCLKpin4  , OUTPUT);
  
  pinMode(   datapin5    , OUTPUT);
  pinMode(outDataCLKpin5 , OUTPUT);
  pinMode(inDataCLKpin5  , OUTPUT);
  
  pinMode(   datapin6    , OUTPUT);
  pinMode(outDataCLKpin6 , OUTPUT);
  pinMode(inDataCLKpin6  , OUTPUT);
}
// numbers from 0 to 9 in 7segment like this ABCDEFG and dot 
int bits[]
{
 B11111100,    //  0
 B01100000,   //  1
 B11011010,   //  2
 B11110010,   //  3
 B01100110,   //  4
 B10110110,   //  5
 B10111110,   //  6
 B11100000,   //  7
 B11111110,   //  8
 B11110110,    //  9
};
int h =10; // variable 3ady
void loop()
{
  ///// this two loops for the hours 
  //// first loop to the first  7 segment in hours
  for(int i=0 ; i<2 ; i++)
    {
      digitalWrite(outDataCLKpin1,LOW);
      shiftOut(datapin1,inDataCLKpin1,LSBFIRST,bits[i]);
      digitalWrite(outDataCLKpin1,HIGH);
      //// second loop to the second 7 segment in hours
      for(int j=0 ; j<h ; j++)
      {
        digitalWrite(outDataCLKpin2,LOW);
        shiftOut(datapin2,inDataCLKpin2,LSBFIRST,bits[j]);
        digitalWrite(outDataCLKpin2,HIGH);
      ///// this two loops for the minutes 
      //// first loop to the first  7 segment in minutes
        for(int k=0 ; k<6 ; k++)
          {
            digitalWrite(outDataCLKpin3,LOW);
            shiftOut(datapin3,inDataCLKpin3,LSBFIRST,bits[k]);
            digitalWrite(outDataCLKpin3,HIGH);
          //// second loop to the second 7 segment in hours
      for(int l=0 ; l<10 ; l++)
                {
                  digitalWrite(outDataCLKpin4,LOW);
                  shiftOut(datapin4,inDataCLKpin4,LSBFIRST,bits[l]);
                  digitalWrite(outDataCLKpin4,HIGH);
                  // this two loops for the seconds 
            // first loop to the first  7 segment in seconds
                  for(int m=0 ; m<6 ; m++)
                      {
                        digitalWrite(outDataCLKpin5,LOW);
                        shiftOut(datapin5,inDataCLKpin5,LSBFIRST,bits[m]);
                        digitalWrite(outDataCLKpin5,HIGH);
                     // second loop to the second 7 segment in seconds
                        for(int n=0 ; n<10 ; n++)
                            {
                              digitalWrite(outDataCLKpin6,LOW);
                              shiftOut(datapin6,inDataCLKpin6,LSBFIRST,bits[n]);
                              digitalWrite(outDataCLKpin6,HIGH);
                      delay(1000);
                          }
                      }
                }
            }
        
          }
      h = 3 ; // when clock = 12 after that its return to the 0 0 0 0 0 0
      }
 }
