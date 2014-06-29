###KoSSR

A PWM controlled Solid State Relay. 8A at mains voltage, more with proper cooling, slightly based on the ACDimmer circuit by Robert Twomey (http://wiki.dxarts.washington.edu/groups/general/wiki/4dd69/AC_Dimmer_Circuit.html)

Originally designed to control a 120VAC 500W silicone heater mat for a 3d printer (http://github.com/mosfet/kossel-minimax)

The ATTiny45 reads an ADC pin sensing the PWM voltage from a control board, and a signal from the Zero-Cross sensing opto-isolator.

It uses these signals to control an opto-isolated triac (think mosfet for alternating current) in a controlled manner providing exact chopping of mains AC voltage.

Great for heating elements, dimming lightbulbs. More info can be found here: http://www.digikey.com/ca/en/techzone/lighting/resources/articles/Retrofit-LED-Bulbs-and-Drivers.html




**Basic BOM:**

Mouser Shopping Cart:

https://www.mouser.com/ProjectManager/ProjectDetail.aspx?AccessID=5bcadebf04

$6.39 for all parts except circuit board


*TODO:*

Add firmware support for 50hz and AREF comparison (rather than internal aref)

Hardware rc filter for PWM smoothing?