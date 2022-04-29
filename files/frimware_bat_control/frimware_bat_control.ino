float data[8];
String message= "";
void setup() {
 
  Serial.begin(9600);

}

void loop() {
  String message= "";
  for (int i=0; i<4;i++){
    data[i]=analogRead(i);
    float s=18.8*(i+1);
    data[i]=data[i]/s;
//    Serial.print("cel ");
//    Serial.print(i);
//    Serial.print("= ");
//    Serial.print(data[i]);
//    Serial.print(" ");
    message=message + "cel-"+String(i+1)+" = "+String (data[i])+" ";
  }
  message=message +"_______________";
  for (int i=4; i<8;i++){
    data[i]=analogRead(i);
    float s=18.8*(i-3);
    data[i]=data[i]/s;
//    Serial.print("cel ");
//    Serial.print(i);
//    Serial.print("= ");
//    Serial.print(data[i]);
//    Serial.print(" ");
    message=message + "cel-"+String(i-3)+" = "+String (data[i])+" ";
  }
  
  Serial.println(message);

}
