// model/Gestos.h
#pragma once
#include <Arduino.h>

enum Gesto {
    REPOSO  = 0,
    GESTO_1 = 1,
    GESTO_2 = 2,
    GESTO_3 = 3,
    GESTO_4 = 4,
    GESTO_5 = 5
};

static const uint8_t NUM_GESTOS = 6;
static const uint8_t NUM_SERVOS = 5;

static const uint8_t TABLA_GESTOS[NUM_GESTOS][NUM_SERVOS] = {
//   S0   S1   S2   S3   S4
  {   0,   0,   0,   0,   0 },  // REPOSO
  {  90,   0,   0,   0,   0 },  // GESTO_1
  {  90,  90,   0,   0,   0 },  // GESTO_2
  {  90,  90,  90,   0,   0 },  // GESTO_3
  {  90,  90,  90,  90,   0 },  // GESTO_4
  {  90,  90,  90,  90,  90 },  // GESTO_5
};