#include <math.h>
#include <stdio.h>

int main()
{
  //printf("I am a c code. Coding in atom is greta. Micahel doesnt know anyting\n");
  float k = 4.20; // constant
  float x_0 = 0; // equilibrium
  float x = 1; // displacement of the spring
  float v = 0; // velocity
  float force = -k * (x - x_0); // Hooke's Law
  float m = 1; // mass
  float a = force / m; // accelleration
  float w = 1; // frequency

  int n = 1000; // number of steps
  float dt = .1; // change in time

  float positions[n];
  float vel[n];
  float acc[n];
  float total_force[n];

  positions[0] = x;
  vel[0] = v;
  acc[0] = a;
  total_force[0] = force;

  for (int i = 1; i < 1000; i++){
    positions[i] = positions[i - 1] + vel[i - 1] * dt + (0.5 * acc[i - 1] * pow(dt, 2));
    total_force[i] = -k * (positions[i] - x_0);
    acc[i] = total_force[i] / m;
    vel[i] = vel[i - 1] + (dt * 0.5 * (acc[i - 1] + acc[i]));
  }
  //char word[] = "apple";
  //printf("%s %3.3f \n", word, k);

  for (int i =0; i <1000; i++){
    printf("%.3f\n", positions[i]);
  }
  return 0;
}
