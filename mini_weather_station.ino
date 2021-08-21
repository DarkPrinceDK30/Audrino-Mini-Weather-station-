 #include <LiquidCrystal.h>
  LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
  
  int sensor_Input;
  float temp;
  float temp2;
  void setup() {
  
    Serial.begin(9600);
    lcd.begin(16, 2);
  	pinMode(A1, INPUT);
  	pinMode(6, OUTPUT);
  }
  void loop() {
    measure_Temp();
    display_Temp();
    photo_resistor();
    press();
  }
  
  void measure_Temp()
  {
    sensor_Input = analogRead(A0);
    temp = (float)sensor_Input / 1024;
    temp = temp * 5;
    temp = temp - 0.5;
    temp = temp * 100;
    temp2=(temp*9/5)+32;
  }
  
  void display_Temp()
  {
    lcd.setCursor(0, 0);
    Serial.print("Temp. in Celcius: ");
    Serial.print(temp);
    Serial.println();
    lcd.print("Temp. in C * :  ");
    lcd.setCursor(5, 1);
    lcd.print(temp);
    delay(2000);
    Serial.print("Temp. in Faren: ");
    Serial.print(temp2);
    Serial.println();
    lcd.setCursor(0, 0);
    lcd.print("Temp. in F * :   ");
    lcd.setCursor(5, 1);
    lcd.print(temp2);
    delay(2000);
  }
  void photo_resistor()
{
  int sensorValue = analogRead(A1);
  Serial.println(sensorValue);
  analogWrite(6, map(sensorValue, 0, 1023, 0, 255));
  lcd.setCursor(0, 0);
  lcd.print("Photoristor:");
  lcd.setCursor(5, 1);
  lcd.print(sensorValue);
  delay(2000); 
    if(sensorValue>=300)
    {
      lcd.setCursor(0, 0);
      lcd.print("  It is sunny   ");
    	lcd.setCursor(5, 1);
    	lcd.print("Outside");
    }
    else
    {
      lcd.setCursor(0, 0);
      lcd.print("   It is dark   ");
    	lcd.setCursor(5, 1);
    	lcd.print("Outside");
    }
     delay(1000); 
    lcd.setCursor(0, 0);
  	lcd.print("                ");
  
    lcd.setCursor(0, 1);
  	lcd.print("                ");          
}
void press()
{
	int no_press=5,light_press=100,med_press=200;
  int press_read = analogRead(A2);
  Serial.println("Pressure pad reading : ");
  Serial.println(press_read);
  lcd.setCursor(0, 0);
  lcd.print("  Pressure ");
  lcd.setCursor(12, 0);
  lcd.print(press_read);
  if(press_read<no_press)
  {
    lcd.setCursor(0, 1);
  	lcd.print("  No Pressure   ");
  	Serial.println("No Pressure");
  }else if(press_read<light_press)
  {
    lcd.setCursor(0, 1);
  	lcd.print("  Low Pressure  ");
  	Serial.println("Low Pressure");
  }else if(press_read<med_press)
  {
    lcd.setCursor(0, 1);
  	lcd.print("Medium Pressure ");
  	Serial.println("Medium Pressure");
  }else
  {
    lcd.setCursor(0, 1);
  	lcd.print("  High Pressure ");
  	Serial.println("High Pressure");
  }
  delay(2000);
  
    lcd.setCursor(0, 0);
  	lcd.print("                ");
  
    lcd.setCursor(0, 1);
  	lcd.print("                ");
}
    