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
