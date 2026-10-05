# lesson 8 - stepper-motor-with-encoder

## components

1. (1) x Elegoo Uno R3
2. (1) x 830 tie-points breadboard
3. (1) x Rotary Encoder Module
4. (1) x ULN2003 stepper motor driver module
5. (1) x Stepper motor
6. (1) x Power supply module
7. (1) x 9V1A Adapter
8. (9) x F-M wires (Female to Male DuPont wires)
9. (1) x M-M wire (Male to Male jumper wire)

Learned to wire and control the rotary module together with the stepper motor. What was interesting was that the instructions provided was not the best case scenario for the components. Using delay made the movements choppy, instead of queueing actions using interupts. Learned how to set interupts using micros() which sets the time since the arduino started in MS. I can then cancel interruptions to reset variables, resume interuption when actions are happening.

![Demo Video](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExYm44N2hkaTZnZXgzZ3BsYnJvYzFldDN4dW5xemZlbnFtdW56Y2V4YiZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/5CkJEoua96f0jMGLGN/giphy.gif)