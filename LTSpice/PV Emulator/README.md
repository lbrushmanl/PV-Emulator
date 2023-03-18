The PV emulator 
Two controll loops this will only cover the constant current current suplly. As the divice is to be coneected to some type of power converter or the solar tracer high side current sensing was use (Also wanted to see if I could get it working with the opamps the UNI had).
I first built the current sense on vero board and started to test it. I initialy tryed to use the LM318 opamp as the simulation said it would work quite well however after tying it out I came to the concloution that this was not true I before getting the TL021 I tryed the LM741 which to my suprise worked it wasent the mos acurate at below 500mA but still worked. With the TL01 it worked flawlesly down to 10s of mA.

To test the current sense I first used a 40V PSU with some resistors as the load however to get a more acurate test I used my DC electronic load which I used to test currents form 50mA to 3A.

Image of test setup
![20230215_161003](https://user-images.githubusercontent.com/114579521/226091372-73fba003-9599-417d-a23f-f99499d7c2bb.jpg)


Next I built the power section. I first tested it with some resistors and used a pot to cahnge the current setpoint I then monited the current with my multimeter. This woked quite well untill I didcnected it from a resistor as the pass transitor and driver blew up. (I belive this was beacuse it was trying to pull 1A and the only path was through the driver transistor).
I thought for ages on how to stop this from happening and then came up with a very simple solution that was to put a resitor at the emitor of the drive transitor this limited the curret to about 100mA when there was no load conected.

Image of test
![20230216_160356](https://user-images.githubusercontent.com/114579521/226091740-89a42d25-ca18-44b8-91f3-510c68c16347.jpg)


Images of response tests this shows the output voltage and how fast it could change
![20230217_120346](https://user-images.githubusercontent.com/114579521/226092264-fee85b3f-fb78-4c15-8c4d-ab36f41917a8.jpg)
![20230217_120818](https://user-images.githubusercontent.com/114579521/226092269-d1e0c15e-c231-4a3f-845a-b6bc3f509027.png)
