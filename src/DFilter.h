/*
    DFilter.h - Arduino IMU Library
    Copyright (c) 2021 Sameera

*/

#ifndef DFilter_h
#define DFilter_h

#include <Arduino.h>

#define ON true
#define OFF false

#define FIFO_SIZE 3

class DFilter
{
public:
    DFilter(float W1, float W2, float W3); //Constructor. attach pin to blink
    ~DFilter();

    get_fifo(void);
    push(float val);
    float getOutput() { return output_val; };
    float update(void);

    float w1, w2, w3;

private:
    float fifo_buff[FIFO_SIZE];
    float output_val;
};

#endif