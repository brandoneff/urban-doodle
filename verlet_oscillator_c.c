#include<stdio.h>

int main()
{
  int steps = 2500; // Number of timesteps
  float k = 1; // Spring constant
  float m = 1; // Mass of spring
  int i; 
  
  // Variables to hold output quantities (Kinetic Energy, Potential Energy, Total Energy)
  float ke;
  float pe;
  float te;
  float x = 1;
  float x_o;
  float x_n;
  float a; // Acceleration
  float v = 1; // Initialize velocity
  float dt = .01; // Timestep (dt)
  float data[6][steps];

  // Initialize position and update position based on the initial velocity
  x_0 = x;
  x = x + dt * v;

  // We will write a for loop that will repeat for the number of specified timesteps (steps)
  for (i = 0; i < steps; i++) {

      // Update the potential energy according to hookes law
      // Update the kinetic energy according to magic (0.5mv^2)
      pe = .5 * k * (x * x);
      ke = .5 * m * (v * v);

      // Total Energy is just kinetic energy plus potential energy
      te = ke + pe;

      // Initialize a 2D array where each of the columns hold output
      // 0th column -> Potential Energy
      // 1th column -> Kinetic Energy
      // 2nd column -> Total Energy
      // 3rd column -> Velocity
      // 4th column -> Position
      // 5th column -> Time

      data[0][i] = pe;
      data[1][i] = ke;
      data[2][i] = pe + ke;
      data[3][i] = v;
      data[4][i] = x;
      data[5][i] = i * dt;
      
      // See velocity verlet algorithm
      a = -k * x / m; // Update acceleration
      x_n = 2.0 * x - x_0 + (dt * dt) * a;
      v = (x_n - x) / dt; //Update current velocity
      x_0 = x; // Update current position
      x = x_n;
    }
    int n;
    int o;
    FILE *fp;
    fp=fopen("output.txt","w");
    fprintf(fp, "Potential Energy  Kinetic Energy  Total Energy  Velocity  Position  time\n");
    for(o=0;o<steps;o++){
      fprintf(fp,"%f %f %f %f %f %f",data[0][o], data[1][o], data[2][o], data[3][o], data[4][o], data[5][o]);
      fprintf(fp,"%c",'\n');
   }

   fclose(fp);
   return 0;

}
