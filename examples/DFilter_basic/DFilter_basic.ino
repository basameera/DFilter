#include <DFilter.h>

DFilter df(0.7, 0.2, 0.1);

float avg = 0;

void setup() {
  Serial.begin(115200);

  df.get_fifo();


  Serial.println("push 10");
  df.push(10);
  avg = df.update();
  Serial.println(avg);
  df.get_fifo();

  Serial.println("push 12");
  df.push(12);
  avg = df.update();
  Serial.println(avg);
  df.get_fifo();

  Serial.println("push 8");
  df.push(8);
  avg = df.update();
  Serial.println(avg);
  df.get_fifo();

  Serial.println("push 15");
  df.push(15);
  avg = df.update();
  Serial.println(avg);
  df.get_fifo();
}

void loop() {

}
