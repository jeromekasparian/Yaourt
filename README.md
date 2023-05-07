# README

** Préparez votre propre yaourt ! **

*** Recette ***
Utiliser de préférence du lait cru complet.
Chauffez le lait dans une casserole, jusqu'à 80°C. Outre un thermomètre, utilisez un anti-monte lait pour vous alerter en cas de débordement… et surveillez le tout "comme le lait sur le feu".

Une fois la température de 80°C atteinte, éteignez le feu, découvrez la casserole et laissez refroidir jusqu'à 56°C. Cette température est assez critique, le thermomètre équipé d'une sonnerie, décrit plus bas, est une aide précieuse pour ne pas refroidir trop longtemps.

Versez ensuite le lait dans des bocaux, ajoutez un peu d'ancien yaourt pour ensemencer (une demi-cuillerée à café pour un bocal de 3/4 de litre). Fermez les bocaux et placez-les dans une enceinte isolée. J'utilise une sacoche isoterme, à l'intérieur de la quelle je place les bocaux dans une vieille couverture en laine.

Après 24 heures, c'est prêt. Rangez les bocaux au réfrigérateur !

*** Le matériel ***
Anti-monte-lait : https://fr.wikipedia.org/wiki/Anti-monte-lait
Sacoche isotherme : https://www.picard.fr/produits/glaciere-coton-equitable-000000000000080137.html

Pour le thermomètre à alarme
- Arduino uno : https://store.arduino.cc/collections/boards/products/arduino-uno-rev3
- Screw shield : https://www.adafruit.com/product/196
- Shield écran : https://www.adafruit.com/product/716
- Capteur de température : https://www.adafruit.com/product/642
- Sonnerie : 
https://www.mouser.fr/ProductDetail/PUI-Audio/AI-1440-TWT-12V-R?qs=hFHXi4OlQrkvrXJe4cro%252BQ%3D%3D

*** Assemblage ***
- Assemblez le screwshield et installez-le sur l'Arduino
- Assemblez l'écran et installez-le sur le screwshield
- Connectez la sonnerie entre le GND et le pin 9 de l'Arduino
- Connectez le capteur de température : GND (noir) sur le pin 4, VCC (rouge) sur le pin 3, Signal (jaune) sur le pin 2. N'oubliez pas la résistance pull-up.
- flashez le code, c'est prêt à fonctionner

Librement inspiré de https://learn.adafruit.com/sous-vide-powered-by-arduino-the-sous-viduino
*************************************

** Cook your own yogurt! **

*** Recipe ***
Preferably use whole raw milk.
Heat the milk in a saucepan to 80°C. In addition to a thermometer, use a milk watcher to alert you in the event of an overflow... and monitor everything "like milk on the stove".

Once the temperature of 80°C has been reached, turn off the heat, uncover the pan and leave to cool down to 56°C. This temperature is quite critical, the thermometer equipped with a buzzer, described below, is a precious help not to cool too long.

Then pour the milk into jars, add a little old yoghurt to seed (half a teaspoon for a 3/4 liter jar). Close the jars and place them in an insulated enclosure. I use an insulated bag, inside which I place the jars in an old woolen blanket.

After 24 hours it's ready. Store the jars in the fridge!

*** Equipment ***
Milk watcher: https://en.wikipedia.org/wiki/Milk_watcher
Insulated bag: https://www.picard.fr/produits/glaciere-coton-equitable-000000000000080137.html

For the alarm thermometer
- Arduino uno: https://store.arduino.cc/collections/boards/products/arduino-uno-rev3
- Screwshield: https://www.adafruit.com/product/196
- Screen shield: https://www.adafruit.com/product/716
- Temperature sensor: https://www.adafruit.com/product/642
- Alarm buzzer :
https://www.mouser.fr/ProductDetail/PUI-Audio/AI-1440-TWT-12V-R?qs=hFHXi4OlQrkvrXJe4cro%252BQ%3D%3D

*** Assembly ***
- Assemble the screwshield and install it on the Arduino
- Assemble the screen and install it on the screwshield
- Connect the buzzer between the GND and pin 9 of the Arduino
- Connect the temperature sensor: GND (black) on pin 4, VCC (red) on pin 3, Signal (yellow) on pin 2. Don't forget the pull-up resistor.
- flash the code, it's ready to work

Freely adapted from https://learn.adafruit.com/sous-vide-powered-by-arduino-the-sous-viduino
