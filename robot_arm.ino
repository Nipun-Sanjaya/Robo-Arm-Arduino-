#include <Servo.h> // servo library
//servo objects
Servo s1 = Servo();
Servo s2 = Servo();
Servo s3 = Servo();
Servo s4 = Servo();

#include <IRremote.h>// ir library
//ir object
IRrecv r = IRrecv(7);
decode_results d = decode_results(); //result object

//static position
int a1 = 90; // base
int a2 = 90; //up down
int a3 = 90;//frant back
int a4 = 90; // top
void setup() {
  r.enableIRIn();// start ir receive
  s1.attach(8); //base
  s2.attach(9); //right
  s3.attach(10);//left
  s4.attach(11);//top

  Serial.begin(9600);
}
void loop() {
  if (r.decode(&d)) {
    int v = d.value;
    Serial.println(v);

    //base
    if (v == 12495) {
      for (int i = 0; i < 10; i++) {
        a1 = a1 + 1;
        s1.write(a1);
        delay(100);
      }}
    if (v == 6375) {
      for (int i = 0; i < 10; i++) {
        a1 = a1 - 1;
        s1.write(a1);
        delay(100);
      }}
    //up down
    if (v == 31365) {
      for (int i = 0; i < 10; i++) {
        a2 = a2 + 1;
        s2.write(a2);
        delay(100);
      }}
    if (v == 4335) {
      for (int i = 0; i < 10; i++) {
        a2 = a2 - 1;
        s2.write(a2);
        delay(100);
      }}
    //front back
     if (v == 14535) {
      for (int i = 0; i < 10; i++) {
        a3 = a3 + 1;
        s3.write(a3);
        delay(100);
      }}
    if (v == 23205) {
      for (int i = 0; i < 10; i++) {
        a3 = a3 - 1;
        s3.write(a3);
        delay(100);
      }}
    //catch and release
     if (v == 17085) {
      for (int i = 0; i < 10; i++) {
        a4 = a4 + 1;
        s4.write(a4);
        delay(100);
      }}
    if (v == 19125) {
      for (int i = 0; i < 10; i++) {
        a4 = a4 - 1;
        s4.write(a4);
        delay(100);}}
    r.resume();  }}
