# Recognition-of-Block-Coloured-Objects

Abstract

This program is the most basic form of object detection using predetermined parameters taken from the program 'Recognition of Objects Colour'. It is merely an expansion on the previous program whereby the objects HSV range was determined and then prompting the user to choose the specific colour to recognise.

Procedure

- Once the Hue, Saturation & Value ranges are known of the object to be detected enter them in the 'inRange(   )' function.

- If the object falls within two ranges, like the red object, then two 'inRange(   )' functions will need to be used and then stored in seperate matrices.

- These two matrices will need to be added together to form one image. this is performed by the 'add(   )' function.


