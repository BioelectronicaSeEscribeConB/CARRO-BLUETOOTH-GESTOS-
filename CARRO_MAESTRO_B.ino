#include <MPU6050.h>//Libreria acelerometro
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // TX, RX
MPU6050 mpu;        //declaramos el sensor
int16_t ax, ay, az, gx, gy, gz; //variables del sensor

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);
  mpu.initialize();   //Iniciamos acelerometro
if (!mpu.testConnection()) { while (1); }
  }

void loop() 
{ 
     mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz); //obtenemos variables del sensor
 ax=-(ax/1000);    //ariba - abajo mapear monitor
 ay=(ay/1000);    //izquierda - derecha mapear monitor
 Serial.print(ax); 
 Serial.print(",");
 Serial.println(ay); 
    //ADELANTE
    if(ax<=-4 && ay>=-3 && ay<=3)
    {mySerial.write('1');}
    
    //ATRAS
      if(ax>=4 && ay>=-3 && ay<=3)
     { mySerial.write('2');}
     
     //DETE
      if(ax>=-3 && ax<=3 && ay>=-3 && ay<=3)
     {mySerial.write('5');}
        
//    //IZQUIERDA
    if(ay<=-4 && ax>=-3 && ax<=3)
     {mySerial.write('4'); }
//
//    //DERECHA
      if(ay>=4 && ax>=-3 && ax<=3)
     {mySerial.write('3');}


}


