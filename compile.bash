#!/bin/bash

file=verlet_oscillator_c.c
gcc ${file} -o v
./v
rm v

echo Compiled ${file}
