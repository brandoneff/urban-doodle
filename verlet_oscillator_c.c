#include<stdio.h>

int main()
{
  int steps = 2500;
  float k = 1;
  float m = 1;
  int i;
  float ke;
  float pe;
  float te;
  float x = 1;
  float x_o;
  float x_n;
  float a;
  float v = 1;
  float dt = .01;
  float data[6][steps];
  x_o = x;
  x = x + dt * v;
    for (i = 0; i < steps; i++) {
      pe = .5 * k * (x * x);
      ke = .5 * m * (v * v);

      te = ke + pe;
      data[0][i] = pe;
      data[1][i] = ke;
      data[2][i] = pe + ke;
      data[3][i] = v;
      data[4][i] = x;
      data[5][i] = i * dt;
      a = -k * x / m;
      x_n = 2.0 * x - x_o + (dt * dt) * a;
      v = (x_n - x) / dt;
      x_o = x;
      x = x_n;
    }
    int n;
    int o;
    FILE *fp;
    fp=fopen("output.txt","w");
    for(o=0;o<steps;o++){
      fprintf(fp,"%f %f %f %f %f %f",data[0][o], data[1][o], data[2][o], data[3][o], data[4][o], data[5][o]);
      fprintf(fp,"%c",'\n');
   }

   fclose(fp);
   return 0;

}
