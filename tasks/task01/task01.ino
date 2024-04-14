int pinsCount = 5;
int pinsNumbers[] = {3, 5, 6, 9, 10};
int freqAmount[] = {50, 100, 500, 1000, 10000};

int states[] = {LOW, LOW, LOW, LOW, LOW};
int prevMicros[] = {0, 0, 0, 0, 0};


void setup() {
  for (int i = 0; i < pinsCount; i++){
    pinMode(pinsNumbers[i], OUTPUT);
  }
}

void loop() {
  int currentMicros = micros();
  for (int j = 0; j < pinsCount; j++){
    if (currentMicros - prevMicros[j] >= freqAmount[j]){
      prevMicros[j] = currentMicros;
      if (states[j] == LOW){
        states[j] = HIGH;
      }
      else{
        states[j] = LOW;
      }
      digitalWrite(pinsNumbers[j], states[j]);
    }
  }
}
