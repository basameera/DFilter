/*
 DFilter.h - Arduino IMU Library
 Copyright (c) 2021 Sameera


*/

#include <Arduino.h>
#include "DFilter.h"

// Constructor
DFilter::DFilter(float W1, float W2, float W3)
{
    w1 = W1;
    w2 = W2;
    w3 = W3;

    for (uint8_t x = 0; x < FIFO_SIZE; x++)
    {
        fifo_buff[x] = 0;
    }
    output_val = 0;
}

// Destructor
DFilter::~DFilter()
{
}

DFilter::get_fifo(void)
{
    for (uint8_t x = 0; x < FIFO_SIZE; x++)
    {
        Serial.println(fifo_buff[x]);
    }
}

// push
DFilter::push(float val)
{
    fifo_buff[2] = fifo_buff[1];
    fifo_buff[1] = fifo_buff[0];
    fifo_buff[0] = val;
}

// update
float DFilter::update(void)
{
    output_val = (fifo_buff[0] * w1) + (fifo_buff[1] * w2) + (fifo_buff[2] * w3);
    return output_val;
}