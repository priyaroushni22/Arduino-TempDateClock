#include<LiquidCrystal.h>
int  getKey();
void setDate();
void setTime();
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int row[4]={7, 6, 5, 4};
int col[4]={3, 2, 1, 0};
 int dayofweeks;
int day,month,year,hour,mint,seconds;
int dy[2],mnth[2],yar[4],hur[2],minu[2];
float celsius;
int temp = A0;
                                                   /////// set week of days  /////// 

int weekday(int year, int month, int day)
/* Calculate day of week in proleptic Gregorian calendar. Sunday == 0. */
{
  int dayofweeks;
  int adjustment, mm, yy;
  if (year<2000) year+=2000;
  adjustment = (14 - month) / 12;
  mm = month + 12 * adjustment - 2;
  yy = year - adjustment;
  dayofweeks = (day + (13 * mm - 1) / 5 +  yy + yy / 4 - yy / 100 + yy / 400) % 7;
  switch(dayofweeks){
case 1:
lcd.setCursor(11, 1);
lcd.print("Mon");
break;
case 2:
lcd.setCursor(11, 1);
lcd.print("Tue");
break;
case 3:
lcd.setCursor(11, 1);
lcd.print("Wed");
break;
case 4:
lcd.setCursor(11, 1);
lcd.print("Thur");
break;
case 5:
lcd.setCursor(11, 1);
lcd.print("Fri");
break;
case 6:
lcd.setCursor(11, 1);
lcd.print("Sat");
break;
case 0:
lcd.setCursor(11, 1);
lcd.print("Sun");

break;}  
  

}
                              ///////SET TIME FUNCTION///////
void setTime()
{
  int count;
  lmn:
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("RANGE 01->24");
lcd.setCursor(0, 1);
lcd.print("ENTER HOUR=");
  count=0;
while(count!=2)
{
hur[count]=getKey();
delay(500);
count++;
}
hour=(hur[0]*10)+(hur[1]);
if(!(hour<=24 && hour>=1))
{
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("INVALID HOURS!");
delay(1500);
goto lmn;
}
lmp:
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("RANGE 01->60");
lcd.setCursor(0, 1);
lcd.print("MINUTES=");
count=0;
while(count!=2)
{
minu[count]=getKey();
delay(500);
count++;
}
mint=(minu[0]*10)+(minu[1]);
if(!(mint<=60 && mint>=1))
{
lcd.clear();
lcd.setCursor(0, 0);
lcd.print("OUT OF RANGE!!");
delay(1500);
goto lmp;
}
}
void setup()
{
lcd.begin(16, 2);
pinMode(temp,INPUT);
for(int i=0;i<=3;i++)
{
pinMode(row[i], OUTPUT);
pinMode(col[i], INPUT);
}
for(int j=0;j<=3;j++)
digitalWrite(col[j], HIGH);
for(int k=0;k<=3;k++)
digitalWrite(row[k], HIGH);
setDate();
setTime();
lcd.clear();
}
                              ///////LOOP FUNCTION///
void loop()
{
 int febucheck;
  while(1){ 
    lcd.noCursor();
  weekday(year, month, day);
  lcd.setCursor(0, 0);
  lcd.print(hour);
  lcd.print(":");
  lcd.print(mint);
  lcd.print(":");  
  lcd.setCursor(6, 0); 
  seconds++; 
  lcd.print(seconds);
  if(seconds==60)
    {
      seconds=0;
      mint++;    
      lcd.clear();  
  }
  if(mint==60)
    {
      mint=0;
      hour++;
      lcd.clear();
    }
    if((month==1 || month==3 || month==5 || month==7 || month==8 || month==10 )&& day==31 && 
    hour==24)
    {
      day=1;
      seconds=0;
      mint=0;
      hour=0;
      month++;
      lcd.clear();
    }
    if(month==12 && day==31 && hour==24)
    {
      month=1;
      day=1;
      seconds=0;
      mint=0;
      hour=0;
      year++;
      lcd.clear();
      if(year>2000)
      febucheck=year-2000;
      else if(year<2000)
      febucheck=2000-year;
      else
      febucheck=0;
    }
    if(month==2 && (febucheck%4)==0 && day==29 && hour==24)
    {
      day=1;
      seconds=0;
      mint=0;
      hour=0;
      month++; 
      lcd.clear();
    }
    else if(month==2 && (febucheck%4)!=0 && day==28 && hour==24)
    {
      day=1;
      seconds=0;
      mint=0;
      hour=0;
      month++;
      lcd.clear();
    }
    else{}
    if(hour==24)
    {
      hour=0;
      day++;
      lcd.clear();
    }
  lcd.setCursor(0, 1);
  lcd.print(day);
  lcd.print("/");
  lcd.print(month);
  lcd.print("/");
  lcd.print(year);
  celsius = analogRead(temp)*0.004882814;
  celsius = (celsius - 0.5) * 100.0;
  	
  	lcd.setCursor(10,0);
    lcd.print(celsius);
	lcd.print(" C");
  	delay(1000);	
  int set=getKey1();
  if(set==1)
          {
              lcd.clear();
              delay(500);
              setDate();
              setTime(); 
              lcd.clear();
          }
  }
}
                             ////////SET DATE FUNCTION/////
void setDate()
{
  int count,febcheck;
  xyz:
  lcd.setCursor(0, 0);
  lcd.print("Range 1900-3000");
  lcd.setCursor(0, 1);
  lcd.print("YEAR = ");
  count=0;
  while(count!=4){
  yar[count]= getKey();
  delay(500);
  count++;
  }
  year=(yar[0]*1000)+(yar[1]*100)+(yar[2]*10)+yar[3];
  if(!(year<=3000 && year>=1900))
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INVALID YEAR!!");
    delay(1500);
    lcd.clear();
  goto xyz;
  }
  delay(1000);
  abc:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Range 01-->12");
  lcd.setCursor(0, 1);
  lcd.print("MONTH =");
  count=0;
  while(count!=2){
  mnth[count]= getKey();
  delay(500);
  count++;
  }
  month=(mnth[0]*10)+(mnth[1]);
  if(!(month<=12&&month>=1))
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INVALID MONTH!!");
  delay(1500);
  goto abc;
  }
  delay(1000);
  jkl:
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Range 01-->31");
  lcd.setCursor(0, 1);
  lcd.print("day =");
  count=0;
  while(count!=2){
  dy[count]= getKey();
  delay(500);
  count++;
  }
  day=(dy[0]*10)+(dy[1]);
  if(!(day<=31 && day>=1))
  {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INVALID DAY!!!");
  delay(1500);
  goto jkl;
  }
  if((month==4 || month==6 || month==9 || month==11) && day==31)
  {
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INVALID DAY!!!");
  lcd.setCursor(0, 1);
  lcd.print("30 DAYS MONTH!!");
  delay(1500);
  goto jkl;
  }
  febcheck=(yar[2]*10)+(yar[3]);
  if(month==2 && (febcheck%4)==0 && day>29)
  {
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INVALID DAY!!!");
  lcd.setCursor(0, 1);
  lcd.print("29 DAYS FEBRUARY");
  delay(1500);
  goto jkl;
  }
   if(month==2 && (febcheck%4)!=0 && day>28)
  {
   lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INVALID DAY!!!");
  lcd.setCursor(0, 1);
  lcd.print("28 DAYS FEBRUARY");
  delay(1500);
  goto jkl;
  }
}

                           ////////GET KEY FUNCTIOMN//////
int getKey()
{
int key=13;
int Readrow,Readcol;
while(key!=1 && key!=2 && key!=3 && key!=4 && key!=5 && key!=6 && key!=7 && key!=8 && key!=9 &&
key!=0)
{
digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[0]);
if((Readrow==LOW) && (Readcol==LOW))
{
lcd.print("1");
digitalWrite(row[0], HIGH);
return key=1;
}
digitalWrite(row[0], HIGH);
 
digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[1]);
if( (Readrow==LOW )&&( Readcol==LOW))
{
lcd.print("2");
digitalWrite(row[0], HIGH);
return key=2;
}
digitalWrite(row[0], HIGH);
digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[2]);
if( (Readrow==LOW) &&( Readcol==LOW))
{
lcd.print("3");
digitalWrite(row[0], HIGH);
return key=3;
}
digitalWrite(row[0], HIGH);
digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[3]);
if(( Readrow==LOW )&&( Readcol==LOW))
{
lcd.print("4");
digitalWrite(row[0], HIGH);
return key=4;
}
digitalWrite(row[0], HIGH);
for(int i=0;i<=3;i++)
{
digitalWrite(row[1], LOW);
Readrow=digitalRead(row[1]);
Readcol=digitalRead(col[i]);
if( (Readrow==LOW) && (Readcol==LOW))
{
lcd.print(4+(i+1));
digitalWrite(row[1], HIGH);
return key=(4+(i+1));
break;
}
}
digitalWrite(row[1], HIGH);
digitalWrite(row[2], LOW);
Readrow=digitalRead(row[2]);
Readcol=digitalRead(col[0]);
if( (Readrow==LOW )&& (Readcol==LOW))
{
lcd.print("9");
digitalWrite(row[2], HIGH);
return key=9;
}
digitalWrite(row[2], HIGH);
digitalWrite(row[2], LOW);
Readrow=digitalRead(row[2]);
Readcol=digitalRead(col[1]);
if( (Readrow==LOW) &&( Readcol==LOW))
{
lcd.print("0");
digitalWrite(row[2], HIGH);
return key=0;
}
digitalWrite(row[2], HIGH);
key=13;
}//While loop ends
return 0;
}//GetKey function ends

                           ////////GET KEY1 FUNCTIOMN//////
int getKey1()
{
int key=13;
int Readrow,Readcol;
  digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[0]);
if((Readrow==LOW) && (Readcol==LOW))
{
lcd.print("1");
digitalWrite(row[0], HIGH);
return key=1;
}
digitalWrite(row[0], HIGH);
 
digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[1]);
if( (Readrow==LOW )&&( Readcol==LOW))
{
lcd.print("2");
digitalWrite(row[0], HIGH);
return key=2;
}
digitalWrite(row[0], HIGH);
digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[2]);
if( (Readrow==LOW) &&( Readcol==LOW))
{
lcd.print("3");
digitalWrite(row[0], HIGH);
return key=3;
}
digitalWrite(row[0], HIGH);
digitalWrite(row[0], LOW);
Readrow=digitalRead(row[0]);
Readcol=digitalRead(col[3]);
if(( Readrow==LOW )&&( Readcol==LOW))
{
lcd.print("4");
digitalWrite(row[0], HIGH);
return key=4;
}
digitalWrite(row[0], HIGH);

for(int i=0;i<=3;i++)
{
digitalWrite(row[1], LOW);
Readrow=digitalRead(row[1]);
Readcol=digitalRead(col[i]);
if( (Readrow==LOW) && (Readcol==LOW))
{
lcd.print(4+(i+1));
digitalWrite(row[1], HIGH);
return key=(4+(i+1));
break;
}
}
digitalWrite(row[1], HIGH);
digitalWrite(row[2], LOW);
Readrow=digitalRead(row[2]);
Readcol=digitalRead(col[0]);
if( (Readrow==LOW )&& (Readcol==LOW))
{
lcd.print("9");
digitalWrite(row[2], HIGH);
return key=9;
}
digitalWrite(row[2], HIGH);
digitalWrite(row[2], LOW);
Readrow=digitalRead(row[2]);
Readcol=digitalRead(col[1]);
if( (Readrow==LOW) &&( Readcol==LOW))
{
lcd.print("0");
digitalWrite(row[2], HIGH);
return key=0;
}
digitalWrite(row[2], HIGH);
return 0;
}//GetKey function ends
