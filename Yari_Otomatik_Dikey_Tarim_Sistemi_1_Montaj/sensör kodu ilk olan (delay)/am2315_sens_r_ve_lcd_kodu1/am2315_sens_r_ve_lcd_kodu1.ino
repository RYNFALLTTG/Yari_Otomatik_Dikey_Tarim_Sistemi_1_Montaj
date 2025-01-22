
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Adafruit_AM2315.h>

LiquidCrystal_I2C lcd(0x27,16,2);
Adafruit_AM2315 am2315;

void setup() {
                               /**/ 
  Serial.begin(9600);
  Serial.println("AM2315 Temperature, Humidity Sensor!");
  Serial.println("Calculating...");
  
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(2,0);
  lcd.print("AM2315 Temp");
  lcd.setCursor(0,1);
  lcd.print("Humidity Sensor");
   delay(1000);
  lcd.clear();
  lcd.setCursor(0,3);
  lcd.print("Calculating...");
  

 if (! am2315.begin()) {
     lcd.setCursor(0,0);
     lcd.print("Sensor not found");
     lcd.setCursor(0,1);
     lcd.print("Chk wire,pullups");
     while (1);
  }
delay (2050);
}                            /**/



/*********************************************************************************/

void loop() {

 float temperature,humidity;


/***************************************************************************/
   if (! am2315.readTemperatureAndHumidity(&temperature,&humidity)) {
    
    Serial.println("Failed to read data from AM2315");
    lcd.setCursor(0,0);
    lcd.print("Failed to read");
    lcd.setCursor(0,1);
    lcd.print("data from AM2315");
     return;
  }
/***************************************************************************/
  
                                  /**/
   
  lcd.init();
  lcd.backlight();
  
  lcd.setCursor(0,0);
  lcd.print("Temp  *C  =");
  lcd.setCursor(11,0);
  lcd.print(temperature);
  
  lcd.setCursor(0,1);
  lcd.print("Hum. g/m3 =");
  lcd.setCursor(11,1);
  lcd.print(humidity);
                                  /**/
                                  /**/
  Serial.println("");
  Serial.print("Temp  *C= "); 
  Serial.println(temperature);
  Serial.print("Hum g/m3= "); 
  Serial.println(humidity);
                                  /**/
 
  delay(2050);

}

       //  CODED BY :     ( MUSTAFA USTA   /   200313004  / KTO KARATAY UNIVERSITY MECHATRONİC ENGİNEERİNG 1. CLASS )
