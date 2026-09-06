# Lesson 13 - ir-receiver

## Components
1. (1) x Elegoo Uno R3
2. (1) x IR receiver module
3. (1) x IR remote
4. (3) x F-M wires (Female to Male DuPont wires)

The lesson was surrounding the ir-receiver and remote modules. Got to work with switch statements, as well as for loop replacements for getting each button press printed. 
The main challenge was understanding that REPEAT, counts as a specific signal, meaning if uncatched it produced unpredictable results. The other issue was that I forgot to include irrecv.resume(), which without I could not get another button press in. 

![Demo video](https://media1.giphy.com/media/v1.Y2lkPTc5MGI3NjExdXAwNm1qaHd1eG8wc3MyZGowMWFyMHd5OTZ0Mmo0cTFhaG5xd3poOCZlcD12MV9pbnRlcm5hbF9naWZfYnlfaWQmY3Q9Zw/5SxKMZPa0tn69P8GQj/giphy.gif)
