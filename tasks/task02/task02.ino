#include <TaskManagerIO.h>

int pinsCount = 5;
int pinsNumbers[] = {3, 5, 6, 9, 10};
int freqAmount[] = {50, 100, 500, 1000, 10000};

int states[] = {LOW, LOW, LOW, LOW, LOW};
int prevMicros[] = {0, 0, 0, 0, 0};


void setup() {
  for (int i = 0; i < pinsCount; i++){
    pinMode(pinsNumbers[i], OUTPUT);
  }

  taskid_t taskZero = taskManager.scheduleFixedRate(
    freqAmount[0],
    [] {
      if (states[0] == LOW){
        states[0] = HIGH;
      }
      else{
        states[0] = LOW;
      }
      digitalWrite(pinsNumbers[0], states[0]);
    },
    TIME_MICROS
  );

  taskid_t taskOne = taskManager.scheduleFixedRate(
    freqAmount[1],
    [] {
      if (states[1] == LOW){
        states[1] = HIGH;
      }
      else{
        states[1] = LOW;
      }
      digitalWrite(pinsNumbers[1], states[1]);
    },
    TIME_MICROS
  );

  taskid_t taskTwo = taskManager.scheduleFixedRate(
    freqAmount[2],
    [] {
      if (states[2] == LOW){
        states[2] = HIGH;
      }
      else{
        states[2] = LOW;
      }
      digitalWrite(pinsNumbers[2], states[2]);
    },
    TIME_MICROS
  );

  taskid_t taskThree = taskManager.scheduleFixedRate(
    freqAmount[3],
    [] {
      if (states[3] == LOW){
        states[3] = HIGH;
      }
      else{
        states[3] = LOW;
      }
      digitalWrite(pinsNumbers[3], states[3]);
    },
    TIME_MICROS
  );

  taskid_t taskFour = taskManager.scheduleFixedRate(
    freqAmount[4],
    [] {
      if (states[4] == LOW){
        states[4] = HIGH;
      }
      else{
        states[4] = LOW;
      }
      digitalWrite(pinsNumbers[4], states[4]);
    },
    TIME_MICROS
  );
}

void loop() {
  taskManager.runLoop();
}