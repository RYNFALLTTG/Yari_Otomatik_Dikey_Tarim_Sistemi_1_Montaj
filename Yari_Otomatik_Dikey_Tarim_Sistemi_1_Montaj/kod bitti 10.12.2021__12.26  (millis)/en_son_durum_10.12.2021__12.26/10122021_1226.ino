/******************************************************************************************************************************************************/
#include <Adafruit_AM2315.h>
#include <Wire.h> 
Adafruit_AM2315 am2315;

int r_temp_result=true;                
int r_hum_result=true;                // default olarak olan değer.   eğer false ise  true olanlar false, false olanlar true olarak mustafa urgan değiştirecek

unsigned long temp_hum_s_in_t=0;    
unsigned long son_zaman;             // sistemin ortak son zamanı    cengiz değiştirecek sisteme göre 

int t_h_s_val=0;        
float avg_t=0;         
float avg_h=0;         
int sum_t;
int sum_h;
float temperature,humidity;
/******************************************************************************************************************************************************/
void setup() {
/******************************************************************************************************************************************************/
Serial.begin(9600);
am2315.begin();  
/*******************************************************************************************************************************************************/           
}               

void loop() {

     /**************************************************************************************************************************************************/
  son_zaman=millis();                                            //son zaman değiştirilecek sistemin ortak zamanına göre
   
  if(son_zaman-temp_hum_s_in_t>=2000){                              

  am2315.readTemperatureAndHumidity(&temperature,&humidity);
  Serial.println("");
  Serial.print("Temp  *C= "); 
  Serial.println(temperature);
  Serial.print("Hum g/m3= "); 
  Serial.println(humidity);
  
  
  if(temperature<20 || temperature>25){    
    r_temp_result=false;    
  }
  else{
    r_temp_result=true;    
  }

  if(humidity<75 || humidity >85){      
    r_hum_result=false;
  }

  else{
  r_hum_result=true;
  }

  sum_t=sum_t+temperature;
  sum_h=sum_h+humidity;
  avg_t=sum_t/5;          // 5 kere ol. için
  avg_h=sum_h/5;          // 5 kere ol. için
  t_h_s_val=t_h_s_val+1;

  if(t_h_s_val==5){                                           // sistem 10 snde 1 kere ortalama yazıyor. sensör 2 snde 1 ölç. için 5 kere oluyor
    Serial.print("");
    Serial.print("Your avarage Room Temperature is :");
    Serial.println(avg_t);
    Serial.print("Your avarage Room Humidity is :");
    Serial.println(avg_h);
    t_h_s_val=0;
    avg_t=0;
    avg_h=0;
    sum_t=0;
    sum_h=0;
  }
  temp_hum_s_in_t=son_zaman;                    //son zaman değiştirilecek sistemin ortak zamanına göre
  }
                /*****************************************************************************************************************************************************/
  }
