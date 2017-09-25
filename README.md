# Recognition-of-Block-Coloured-Objects

Abstract

This program is the most basic form of object detection using predetermined parameters taken from the program 'Recognition of Objects Colour'. It is merely an expansion on the previous program whereby the objects HSV range was determined and then prompting the user to choose the specific colour to be recognised.

Procedure

- Once the Hue, Saturation & Value ranges are known of the object to be detected enter them in the 'inRange(   )' function.

- If the object falls within two ranges, like the red object, then two 'inRange(   )' functions will need to be used and then stored in seperate matrices.

- These two matrices will need to be added together to form one image. This is performed by the 'add(   )' function.

- Run the program. The user will be prompted to choose a colour to detect.

- Once a colour has been chosen it will displayed as a white object against a black background.

- To choose another object, stop the program and restart.
