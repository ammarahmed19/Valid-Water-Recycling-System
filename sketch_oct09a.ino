//##########################################################################################//
                         //******Global Variales Decleration******//
float ph;
long tank_level;
float ntu_value;
//##########################################################################################//
                         //******Pins Variables Decleration ******//

int ph_pin = A0;
int trigPin = 9;
int echoPin = 10;
int turbidity = A1;
int motor_relay = 7;
int water_switch = 6;
int Osmosis_in = 3;
int Osmosis_out=4;
int Chemicals_in= 13;
int Chemicals_out= 12;
int ph_in = 11;
int hcl_dropper = 8;
int naoh_dropper = 2;
int final_tank= 0;

//##########################################################################################//
void setup() {
  pinMode(ph_pin , INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin , INPUT);
  pinMode(motor_relay,OUTPUT );
  pinMode(hcl_dropper,OUTPUT);
  pinMode(naoh_dropper,OUTPUT);
  pinMode(water_switch,OUTPUT);
  pinMode(turbidity,INPUT);
  pinMode(Osmosis_in,OUTPUT);
  pinMode(Osmosis_out,OUTPUT);
  pinMode(Chemicals_in,OUTPUT);
  pinMode(Chemicals_out,OUTPUT);
  pinMode(ph_in,OUTPUT);
  pinMode(final_tank,OUTPUT);
  }
//########################################################################################//
void loop() {
  
  while(true){
    tank_level=Tank_capacity();
    if(tank_level<4.5){
      digitalWrite(water_switch,HIGH);
      digitalWrite(motor_relay,HIGH);
      delay(1000);
      }else{
       digitalWrite(water_switch,LOW);
       digitalWrite(motor_relay,LOW);
       delay(1000);
        break;
        }
      }
   ntu_value=Turbidity_clac();
   if (ntu_value>=3 && ntu_value<=5){
    Osmosis();
    delay(3000);
    }else if (ntu_value>=1 && ntu_value<=3){
      Chemicals();
      delay(3000);
      }else{
        PH_GO();
        delay(3000);
        }
   ph=PH_Calculate();
   if(ph<6.5){
    NAOH_add();
    }else if (ph>8){
      HCL_add();
      }
    delay(1000);
    final_t();
    
}
//############################################################################################//
                         //******To Calculate the Tank Capacity******//

int Tank_capacity(){
  long duration;
  int distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);// Sets the trigPin on HIGH state for 10 micro seconds
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
  distance= duration*0.034/2;// Calculating the distance
  return distance;
  }
  //#########################################################################################//
                         //******To Calculate Turbidity of water******//
int Turbidity_clac(){
      float ntu;
      float volt;
    volt = 0;
    for(int i=0; i<800; i++)
    {
        volt += ((float)analogRead(turbidity)/1023)*5;
    }
    volt = volt/800;
    volt = round_to_dp(volt,2);
    if(volt < 2.5){
      ntu = 3000;
    }else{
      ntu = -1120.4*square(volt)+5742.3*volt-4353.8; 
    }
   return ntu;
  }
float round_to_dp( float in_value, int decimal_place )
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;
  return in_value;
}
  //#########################################################################################//
                         //******To Make Reverse Osmosis******//
  void Osmosis(){
    digitalWrite(Osmosis_in,HIGH);
    delay(1000);
    digitalWrite(Osmosis_out,HIGH);
    float Liters = 10;
    float Minutes = (1/4)*Liters;
    float Seconds = Minutes*60;
    delay(Seconds*1000);
    }
//#########################################################################################//
                         //******To Make chemical reactoiions of filteration******//
  void Chemicals(){
    digitalWrite(Chemicals_in,HIGH);
    delay(1000);
    digitalWrite(Chemicals_out,HIGH);
    float Liters = 10;
    float Minutes = (1/4)*Liters;
    float Seconds = Minutes*60;
    delay(Seconds*1000);
    }
//#########################################################################################//
                         //******To skip any filteration processes******//
 void PH_GO(){
    digitalWrite(ph_in,HIGH);
    float Liters = 10;
    float Minutes = (1/4)*Liters;
    float Seconds = Minutes*60;
    delay(Seconds*1000);
    }
 
//#########################################################################################//
                         //******To Calculate PH of water******//

int PH_Calculate(){

  float avg_ph_value ; 
  int ph_list[10],temp_ph;
  float ph_value;
  
  for(int i=0;i<10;i++)       //Get 10 sample value from the sensor for smooth the value
  { 
    ph_list[i]=analogRead(ph_pin);
    delay(10);
  }
  for(int i=0;i<9;i++)        //sort the analog from small to large
  {
    for(int j=i+1;j<10;j++)
    {
      if(ph_list[i]>ph_list[j])
      {
        temp_ph=ph_list[i];
        ph_list[i]=ph_list[j];
        ph_list[j]=temp_ph;
      }
    }
  }
  avg_ph_value=0;
  for(int i=0;i<9;i++)                      //take the average value of 6 center sample
    avg_ph_value+=ph_list[i];
  ph_value=avg_ph_value*5.0/1024/6; //convert the analog into millivolt
  ph_value=3.5*ph_value;
  return ph_value; 
  }
//#################################################################################################//
                         //******To Add NAOH in case water is acidic******//
void NAOH_add(){
    while(true){
      delay(1000);
      ph=PH_Calculate();
      delay(1000);
      if(ph<6.5){
        digitalWrite(naoh_dropper,HIGH);
        delay(1000);
        digitalWrite(naoh_dropper,LOW);
        }else if(ph<=8&&ph>=6.5){
          digitalWrite(naoh_dropper,LOW);
          break;
          }else if(ph>6.5){
            HCL_add();
            break;
            }
      }
  }
//##############################################################################################//
                         //******To Add HCL in case water is basic******//
void HCL_add(){
    while(true){
      delay(1000);
      ph=PH_Calculate();
      delay(1000);
      if(ph>8){
        digitalWrite(hcl_dropper,HIGH);
        delay(1000);
        digitalWrite(hcl_dropper,LOW);
        }else if(ph<=8&&ph>=6.5){
          digitalWrite(hcl_dropper,LOW);
          break;
          }else if(ph<6.5){
            NAOH_add();
            break;
            }
      }
  }
//#########################################################################################//
                         //******to go to final tank******//
void final_t(){
      digitalWrite(final_tank,HIGH);
    float Liters = 10;
    float Minutes = (1/4)*Liters;
    float Seconds = Minutes*60;
    delay(Seconds*1000);
    }
