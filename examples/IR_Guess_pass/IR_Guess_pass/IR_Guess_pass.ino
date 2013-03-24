//Brute force into password protected chanel in a satelite receiver by trying to guess the password.
//May take days and won't stop when it guesses the password, never the less fun to see it working

#include <IRremote.h>

IRsend irsend;

//Raw IR timings for several buttons, these were obtained with https://github.com/shirriff/Arduino-IRremote/blob/master/examples/IRrecvDump/IRrecvDump.ino

unsigned int digits[10][68]={
{9000,4450,600,550,600,550,550,550,600,500,650,500,650,450,600,1650,600,500,650,500,650,500,600,500,600,500,650,500,600,500,650,1600,650,500,650,450,650,500,600,500,650,500,600,500,600,550,650,450,650,500,600,1600,650,1600,650,1650,600,1600,650,1650,600,1600,600,1650,650,1600,600},
{9000,4500,550,550,600,500,600,550,600,500,600,550,600,500,600,1650,600,550,550,550,600,550,600,500,550,550,650,500,600,550,550,1650,650,500,600,1650,600,500,650,500,550,550,600,550,550,550,650,450,600,550,600,500,600,1700,550,1650,650,1600,650,1600,600,1650,650,1600,650,1600,600},
{9000,4500,600,500,600,550,600,500,600,500,600,550,600,550,550,1650,600,550,600,500,600,550,600,550,550,550,600,500,600,550,600,1650,550,550,600,550,600,1650,550,550,600,500,650,500,600,500,600,550,600,550,550,1650,600,550,550,1700,600,1650,550,1700,550,1700,600,1600,600,1700,550},
{9000,4450,600,550,600,550,550,550,550,550,600,550,600,500,650,1600,600,500,600,550,600,550,550,550,600,500,600,550,600,500,600,1700,550,550,600,1650,600,1650,600,500,600,500,650,500,600,550,550,550,600,500,650,500,550,550,600,1700,550,1650,600,1650,600,1650,550,1700,600,1650,550},
{9050,4450,600,550,600,500,600,500,600,550,600,550,550,550,600,1650,550,550,600,550,600,550,550,550,600,500,600,550,600,500,600,1650,600,550,600,500,600,550,550,1650,600,550,600,500,600,550,600,500,600,550,600,1650,600,1650,600,500,600,1650,600,1650,600,1650,550,1700,600,1650,550},
{9000,4450,600,550,600,550,550,550,600,500,600,550,600,500,600,1650,600,550,600,500,600,550,550,550,600,550,600,500,600,500,600,1700,550,550,600,1650,550,550,600,1650,550,600,600,500,600,550,550,550,600,550,600,500,550,1700,600,550,550,1650,600,1650,600,1650,600,1650,600,1650,600},
{9000,4500,600,500,650,450,600,550,600,550,600,500,600,550,600,1650,600,500,600,500,600,550,600,550,550,550,600,500,650,500,600,1650,600,500,600,550,550,1700,550,1700,600,500,550,550,600,550,600,550,550,550,550,1700,600,500,600,500,600,1700,600,1650,550,1650,600,1650,650,1650,550},
{9050,4450,550,550,600,550,600,550,550,550,550,550,600,550,600,1650,550,550,650,500,600,500,600,550,550,550,600,550,550,550,600,1650,600,550,550,1650,600,1650,600,1650,600,550,600,500,600,550,550,550,600,550,550,550,550,550,600,550,600,1650,600,1650,550,1700,600,1650,550,1700,600},
{9050,4450,650,500,650,500,600,500,600,500,650,500,600,500,650,1600,600,550,600,500,650,500,600,500,600,550,600,500,600,500,600,1700,600,500,600,500,650,500,600,500,600,1650,650,500,600,500,600,550,600,500,600,1650,600,1650,600,1650,600,500,650,1600,650,1600,600,1650,650,1600,650},
{9050,4450,650,500,600,500,600,550,600,500,650,500,550,550,600,1650,600,550,550,550,600,550,600,500,600,500,600,550,600,500,650,1650,600,500,600,1650,600,500,600,500,650,1600,650,500,600,500,650,500,600,500,650,500,600,1650,600,1650,600,500,650,1600,600,1650,600,1650,600,1650,600}
};

unsigned int but_okay[68]={9050,4450,600,550,550,550,600,500,600,550,600,500,650,500,550,1700,600,500,600,550,550,550,600,550,600,500,550,550,600,550,550,1700,600,500,600,1650,600,550,600,1650,550,1700,600,500,600,550,600,500,600,500,600,550,600,1650,550,550,600,550,600,1650,550,1700,600,1650,550,1700,550};

int choose_channel(int x,int y, int z)
{
irsend.sendRaw(digits[x],68,32);delay(1000);
//irsend.sendRaw(digits[y],68,32);delay(1000);  //just dialing 8 and waiting a while gets me to 801
//irsend.sendRaw(digits[z],68,32);delay(5000);
};


 
void setup()
{
Serial.begin(9600);
Serial.println("Bulsat Bruteforce");
choose_channel(8,0,1);//set the chanel
irsend.sendRaw(but_okay,68,32);delay(5000);
}

void loop()
{

for (int q=1;q<=9;q++)
{
for (int w=0;w<=9;w++)
{
for (int e=0;e<=9;e++)
{
for (int t=0;t<=9;t++)
{
Serial.print("Current Password: ");
Serial.print(q);
Serial.print(w);
Serial.print(e);
Serial.println(t);

irsend.sendRaw(digits[q],68,32);delay(300);
irsend.sendRaw(digits[w],68,32);delay(300);
irsend.sendRaw(digits[e],68,32);delay(300);
irsend.sendRaw(digits[t],68,32);delay(300);
irsend.sendRaw(but_okay,68,32);delay(5000);
choose_channel(8,0,1); delay(5000); //get to the chanel again, if password didn't match we get a blank page

};//End of for (int t=0;t<=9;$t++)
};//End of for (int e=0;e<=9;$e++)
};//End of  for (int w=0;w<=9;$w++)
};//End of for (int q=0;q<=9;$q++)
};//End of void loop()