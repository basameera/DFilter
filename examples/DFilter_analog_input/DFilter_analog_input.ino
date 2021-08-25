#include <DFilter.h>
#include <util/delay.h>

DFilter df(0.5, 0.3, 0.2);

float avg = 0;
float analog_val = 0;

void setup() {
  Serial.begin(115200);
  pinMode(A0, INPUT);
  Serial.println("raw\tavg");
}

void loop() {
  analog_val = analogRead(A0);
  df.push(analog_val);
  avg = df.update();
  Serial.print(analog_val);
  Serial.print("\t");
  Serial.println(avg);
  _delay_ms(10);

}
