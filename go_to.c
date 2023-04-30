#include <kipr/botball.h>
double bias_x;
double bias_y;
float velX;
float velY;
int positionX;
int positionY;
int angle;
double oldGyro;
double conversion = 10/1024;
int timeInterval = 10;
double oldGyro;

int lspeed = 700;
int rspeed = 700;

int findBias(){
	//Stop the motors to make bot stand still
	ao();
	msleep(100);
	
	//Find the average noise
	int i = 0;
	double avg_x = 0;
  double avg_y = 0;
	while(i < 50){
		avg_x += accel_x();
    avg_y += accel_y();
		msleep(1);
		i++;
	}
	bias_x = avg_x/50;
  bias_y = avg_y/50;
	return bias_x;
  return bias_y;
}

//outputs velocity in m/s
int findVelocity(int time) {
  int i = 0;
  while(i < time) {
    velX += accel_x()*conversion/1000;
    velY += accel_y()*conversion/1000;
     msleep(1);
  }
  
  return velX;
  return velY;
}

int findPosition(int time) {
  int i = 0;
  while(i < time) {
    velX += velX()/1000;
    velY += accel_y()/1000;
     msleep(1);
  }
  
  return posX;
  return posY;
}

int findGBias(){
	//Stop the motors to make bot stand still
	ao();
	msleep(100);
	
	//Find the average noise
	int i = 0;
	double avg = 0;
	while(i < 50){
		avg += gyro_z();
		msleep(1);
		i++;
	}
	bias = avg / 50.0;
	return bias;
}

int readGyro(){
	return gyro_z() - bias;
}

int findAngle(int time) {
  int i = 0;
  int currentGyro = oldGyro;
  while (i < time) {
    int newGyro = oldGyro;
    newGyro = readGyro();  
    angle += 0.5*(newGyro-oldGyro)*timeInterval/1000 + oldGyro * timeInterval/1000;
  }
}

void goTo(int x, int y, int angle) {
  
}
 
int main(){
  
  
  return 0;
}
