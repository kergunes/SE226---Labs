// Föyde verilen pin tanımlamaları (Değiştirilmedi)
const int LED1pin = 46; 
const int LED2pin = 45;
const int LED3pin = 44;
const int LED4pin = 43;

const int button1pin = 41; // ON/OFF Üstün Güç Butonu
const int button2pin = 40; // Mod Değiştiren Buton

// Sistem durum değişkenleri
bool systemOn = false;      // Sistem başlangıçta KAPALI
int mode = 0;               // Başlangıç modu Mode 0 (Sürekli yanık mod)

// Buton durum takibi
int lastButton1State = LOW;
int lastButton2State = LOW;

// Zamanlama ve Animasyon Değişkenleri
unsigned long lastActionTime = 0;
int stepCounter = 0;        
bool blinkState = true;

void setup() {
  pinMode(LED1pin, OUTPUT);
  pinMode(LED2pin, OUTPUT);
  pinMode(LED3pin, OUTPUT);
  pinMode(LED4pin, OUTPUT);
  
  pinMode(button1pin, INPUT);
  pinMode(button2pin, INPUT);
  
  Serial.begin(9600);
  
  allLedsOff();
}

void loop() {
  int currentButton1 = digitalRead(button1pin);
  int currentButton2 = digitalRead(button2pin);

  if (currentButton1 == HIGH && lastButton1State == LOW) {
    systemOn = !systemOn;
    
    if (!systemOn) {
      allLedsOff();
    } else {
      mode = 0; 
      stepCounter = 0;
      blinkState = true;
      lastActionTime = millis(); 
      
      digitalWrite(LED1pin, HIGH);
      digitalWrite(LED2pin, HIGH);
      digitalWrite(LED3pin, HIGH);
      digitalWrite(LED4pin, HIGH);
    }
    delay(50); 
  }
  lastButton1State = currentButton1;

  if (systemOn && currentButton2 == HIGH && lastButton2State == LOW) {
    mode++;
    
    if (mode > 3) {
      mode = 1;
    }
    
    stepCounter = 0;
    blinkState = true; 
    allLedsOff();
    
    lastActionTime = millis(); 
    
    delay(50); 
  }
  lastButton2State = currentButton2;

  if (systemOn) {
    
    if (mode == 0) {
      digitalWrite(LED1pin, HIGH);
      digitalWrite(LED2pin, HIGH);
      digitalWrite(LED3pin, HIGH);
      digitalWrite(LED4pin, HIGH);
    }
    
    else {
      unsigned long currentTime = millis();
      
      if (currentTime - lastActionTime >= 1000) {
        lastActionTime = currentTime; 
        
        if (mode == 1) {
          digitalWrite(LED1pin, blinkState);
          digitalWrite(LED2pin, blinkState);
          digitalWrite(LED3pin, blinkState);
          digitalWrite(LED4pin, blinkState);
          blinkState = !blinkState; 
        }
        
        else if (mode == 2) {
          allLedsOff();
          if (stepCounter == 0) digitalWrite(LED1pin, HIGH);
          else if (stepCounter == 1) digitalWrite(LED2pin, HIGH);
          else if (stepCounter == 2) digitalWrite(LED3pin, HIGH);
          else if (stepCounter == 3) digitalWrite(LED4pin, HIGH);
          
          stepCounter = (stepCounter + 1) % 4;
        }
        
        else if (mode == 3) {
          allLedsOff();
          if (stepCounter == 0) digitalWrite(LED4pin, HIGH);
          else if (stepCounter == 1) digitalWrite(LED3pin, HIGH);
          else if (stepCounter == 2) digitalWrite(LED2pin, HIGH);
          else if (stepCounter == 3) digitalWrite(LED1pin, HIGH);
          
          stepCounter = (stepCounter + 1) % 4;
        }
      }
    }
  }
}

void allLedsOff() {
  digitalWrite(LED1pin, LOW);
  digitalWrite(LED2pin, LOW);
  digitalWrite(LED3pin, LOW);
  digitalWrite(LED4pin, LOW);
}