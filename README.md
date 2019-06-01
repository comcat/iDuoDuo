iDuoDuo - Pet APRS Tracker
=======================================

![iDuoDuo Board V0.4](hardware/V0.4/iDuoDuo-APRS-Tracker-layout.png)

![My DuoDuo](doc/iDuoDuo.jpg)

![iDuoDuo prototype](doc/iDuoDuo-00.jpg)

![iDuoDuo V0.4](doc/iDuoDuo-01.jpg)

![iDuoDuo V0.4](doc/iDuoDuo-02.jpg)

![iDuoDuo V0.4](doc/iDuoDuo-03.jpg)


[*iDuoDuo Board*](http://jackslab.org/)


Features
-------------------
* ATMEGA328p MCU, Arduino compatible
* 1W VHF radio module ([SR_FRS_1WV](https://item.taobao.com/item.htm?id=21278567784))
* 1200 bauds AFSK using 8-bit PWM
* Sends out standard APRS position messages
* mini GPS module
* 18650 power supply
* Open Source hardware and firmware 


Pin map
-------------------
iDuoDuo board

* D3 is the audio out pin
* D4 is the PTT pin
* D12 is the PD pin of radio module
* D13 is the PWR_CTRL pin of the radio module

* D8 is the power on input pin
* D9 is the power on output pin


Repository Contents
-------------------
* hardware/ - All Eagle design files (.brd, .sch) and Gerber files of iDuoDuo Board 
* firmware/ - Firmware source files of the iDuoDuo


Product Versions
----------------
* [IDuoDuo-001](http://www.jackslab.org/) - Bare pcb.
* [IDuoDuo-002](http://www.jackslab.org/) - Geek Kit. Bare pcb plus chips, stackable headers, indicator LEDs, push buttons and resistors ...
* [IDuoDuo-003](http://www.jackslab.org/) - Complete iDuoDuo board.


License Information
-------------------
The hardware is released under [Creative Commons ShareAlike 4.0 International](https://creativecommons.org/licenses/by-sa/4.0/).

Distributed as-is; no warranty is given.
