# Valid Water Recycling System
## Problem Definition
* Scarcity of water in Egypt has exacerbated in the last few years. There are main reasons of this problem will lead to a general problem in the whole country. The first problem is from each house, and caused by all of family members. Each person uses 1 British gallon per minute in shower, and the shower lasts from 7 to 10 minutes, so there is 8 Gallons used as an average, which is approximately 32 liters of water. The second problem is the water used in kitchens is considered an overrated consumption for water. It is a small scale of water waste. The large scale is water pollution, and misusing water sources in agriculture. Most of the farms in Egypt depend on traditional ways in planting farms, and it consumes large quantities of water.

* There is also additional problems face Egypt in this problem. The first one is rising population and rapid economic development in the countries of the Nile Basin. It effects on Egypt by decreasing water availability in the country. As a result, Egypt is facing an annual water deficit of around 7 billion cubic meters. In addition, United Nations is already warning that Egypt could run out of water by the year 2025.

* There is also additional problems face Egypt in this problem. The first one is rising population and rapid economic development in the countries of the Nile Basin. It effects on Egypt by decreasing water availability in the country. As a result, Egypt is facing an annual water deficit of around 7 billion cubic meters. In addition, United Nations is already warning that Egypt could run out of water by the year 2025.

## Problem Solution
* The idea of this project is to save most of the used water in shower, and the kitchens in residential buildings without demolishing the infrastructure of the water system in the buildings, which means that this water treatment system will be established parallel to the water system of the building. The main idea of the project is fast treating for water to use it again with the same purpose that has been already used for it before, with low cost in the used components, with smart control system enable the person to analysis the chemical characteristics of this water like PH, turbidity, and temperature to find out which treatment process needed to make this water valid. In addition, the treated water will be saved in a tank, and the rest of treated water can be used in other purposes surrounding the residential building. For instance, if the building is in a rural city, it can be used for agriculture unless this water will not harm the plants, or the soil.

_Click the below image to view the video_
[![Simulation Video](https://img.youtube.com/vi/Hcgp5Uokcdo/0.jpg)](https://www.youtube.com/watch?v=Hcgp5Uokcdo)

> The video refers to the simulation video of the process on a scale of an apartement.

*	The sequences of treatment process is arranged gradually to assure from each detail in the water, and do not make conflict with other process. And there is check analysis step before the end of process. The first step to move the water to the water treatment system, and the system analysis the water with specific sequences use the suitable treatment process (will be explained in the technicalities section). Finally, the water will be stored in the tank, or will not be stored if it is not valid. In case the tank is full, and there is treated water it will be moved in a water system to be used in other purpose.

## Methodology
* The first step in the system is transporting the water from the pipes by a motor for each apartment, and the water go through membrane with thickness with a suitable diameter for cell wall to prevent the big pieces of impurities to prevent its dissolving in the water. 

![impurities that membrane prevent](/images/membrane.png)

> Fig.1 refers to the impurities that membrane prevent.

* This amount of water is put in a tank, which refers that is about to be filled by using ultra sonic sensor, by identifying the height of water in the tank.

![ultrasonic sensor schematic](/images/ultrasonic.jpg)

> Fig.2 refers to the ultrasonic sensor schematic.

* The second step is the use of turbidity sensor. It is used to specify whether the water valid to be treated or not, and how the suitable process for filtration. The turbidity value in allowed water in drinking is 1 NTU (Nephelometric Turbidity Units), but it can be higher, and used in other purposes except drinking. But this water has to be treated with specific process.

![schematic of turbidity](/images/turbidity.png)

> Fig.3 refers to schematic of turbidity.

* So, if the turbidity value is from 3 to 5 NTU, the suitable process is reverse osmosis.

![reverse osmosis process for filtration](/images/reverseOsmosis.jpg)

> Fig.4 refers to reverse osmosis process for filtration

 But, in case the value of turbidity is from 1 to 3 NTU, it refers that is a soapy water, so the suitable process is a chemical reaction. It is a combination between Epsom salt, calcium carbonate, and acid. But if the turbidity value is greater than 5 NTU, this water is not valid, and it will be removed from the treatment process.
 
 * The third step in the filtration process is identifying the value of PH by PH sensor.
 
 ![schematic of PH sensor](/images/filteration.jpg)
 
 > Fig.5 refers to schematic of PH sensor.
 
It is allowed to use Water with tolerance in PH value from 6.5 to 8. If the value of PH is lower than 6.5, it refers that the acidity concentration is great so the water has to be normalized by NAOH using titration system, and the sensor will give continuous values. But if the value of PH is greater than 8, the base quantity in water is great, and it will be normalized by HCL BY titration.

* The final step is that the water is stored in a tank has the sane volume of the first tank, to reuse the water again in the same purposes.

### Software
#### Flowchart
![Flowchart](/images/flowchart.png)
#### Arduino C Code
```
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
```

## Business ##
### SWOT Analysis
![SWOT Analysis](/images/SWOT.png)
### Business Model
![Business Model](/images/BUSINESS_MODEL.png)
## Future Plans and Recommendations
* In case the project is able to produce recycled water it can be used in a large scale especially in rural towns, which means that it can be established a water distribution system to the farms, which its soil can adapt to this kind of recycled water. But it will be a traditional water distribution system with waste of water. As a result, the recycled water can be stored in tanks, and using agricultural drone for spraying farms to save more water. This idea is already applied in many countries, but it is applied in Egypt on small scales. As a result, the future plan for this project is to collect the detailed information about the components of the treated water, and find out which soils can use this water to make crops grow.

![Drone](/images/drone.png)

## References
* Amir Dakkak (2018). Egypt’s Water Crisis – Recipe for Disaster. [online] EcoMENA. Available at: https://www.ecomena.org/egypt-water/.
* How To Electronics. (2020). DIY Ph Meter using PH Sensor & Arduino with OLED Display. [online] Available at: https://how2electronics.com/ph-meter-using-ph-sensor-arduino-oled/ [Accessed 9 Oct. 2020].
* jesper landman (2020). Cleaning soapy water (Experiment). YouTube. Available at: https://www.youtube.com/watch?v=it-uybk6DQU [Accessed 10 Oct. 2020].
* Keyestudio Turbidity Sensor V1.0 (Black and Eco-friendly). (n.d.). [online] Available at: https://cdn.shopify.com/s/files/1/0672/9409/files/Turbidity_Sensor_user_manual.pdf?v=1592250252 [Accessed 9 Oct. 2020].
* Random Nerd Tutorials. (2019). Complete Guide for Ultrasonic Sensor HC - SR04. [online] Available at: https://randomnerdtutorials.com/complete-guide-for-ultrasonic-sensor-hc-sr04/.
* Reliance H. (2017). What is Reverse Osmosis (RO) and How You can Benefit From It. [online] Available at: https://reliancehomecomfort.com/ro-benefits/.
* Www.home-water-works.org. (n.d.). Showers | Home Water Works. [online] Available at: https://www.home-water-works.org/indoor-use/showers#:~:text=Showering%20to%20Savings&text=The%20average%20American%20shower%20uses.
