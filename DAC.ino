int valSin;
int sensorValue;
int sensorLow = 100;
int sensorHigh = 0;
const int ledPin = 13;

void setup() 
  {
    Serial.begin(9600);
    DDRD = B11111111;
    pinMode(ledPin, OUTPUT);
    digitalWrite(ledPin, HIGH);
     
    while (millis() < 5000)
      {   
        sensorValue = analogRead(A1);
        
        if (sensorValue > sensorHigh) 
          {
            sensorHigh = sensorValue;
          }
          
        if (sensorValue < sensorLow)
          {
            sensorLow = sensorValue;
          }
     }
     
    digitalWrite(ledPin, LOW);
    
  }

void loop() 
  {
    while (digitalRead(8) == LOW && digitalRead(9) == LOW && digitalRead(10) == LOW)
      {
        PORTD = 255/2;
        
        digitalWrite(ledPin, HIGH);
        delay(100);
        Serial.println(analogRead(A0));
        
        digitalWrite(ledPin, LOW);
        delay(100);
        Serial.println(analogRead(A0));
      }
  
    while (digitalRead(8) == HIGH && digitalRead(9) == LOW && digitalRead(10) == LOW)
      {
        sensorValue=analogRead(A1);
        float i = 0;
    
        while (i < 255)
          {
            sensorValue=analogRead(A1);
            float pitch=map(sensorValue, sensorLow, sensorHigh, 6, 500);
          
            PORTD = i; 
            Serial.println(analogRead(A0));
            i = i + (pitch / 10);
          }
      
       if (i > 255)
          {
            i = 255;
          }
      
       while (i > 0)
       {
          sensorValue=analogRead(A1);
          float pitch=map(sensorValue, sensorLow, sensorHigh, 6, 500);
          
          i = i - (pitch / 10);
          
          if (i < 0)
            {
              i = 0;
            }
              
          PORTD = i;
          Serial.println(analogRead(A0));
        }   
    }

  while (digitalRead(9) == HIGH && digitalRead(8) == LOW && digitalRead(10) == LOW)
    {
          sensorValue=analogRead(A1);
          float i = 0;
      
          while (i < 255)
            {
              sensorValue=analogRead(A1);
              float pitch=map(sensorValue, sensorLow, sensorHigh, 5, 500);
          
              PORTD = i; 
              Serial.println(analogRead(A0));
              i = i + (pitch / 10);
            }    
     }

  while (digitalRead(10) == HIGH && digitalRead(8) == LOW && digitalRead(9) == LOW)
    { 
      sensorValue=analogRead(A1);
      float pitch=map(sensorValue, sensorLow, sensorHigh, 5, 1000);
      float i = 0;
      
      while (i < 360) 
        {
          sensorValue=analogRead(A1);
          float pitch=map(sensorValue, sensorLow, sensorHigh, 5, 1000);
          valSin = ((sin(i * DEG_TO_RAD) + 1) * 255) / 2;
          
          PORTD = valSin;        
          Serial.println(analogRead(A0));       
          i = i + (pitch/10);
        }
    }
  }
