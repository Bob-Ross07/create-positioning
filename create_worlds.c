#include <kipr/wombat.h>
int arm1;
int arm2;
int up;

int claw;
int wrist;
int open;
int close;

//wrist values for different tower heights
int low;
int high;

int rspeed;
int lspeed;



//drive forward a given distance while setting up the arm to grab cube/botgal
void forward_set(int distance) {
  set_servo_position(claw, open);
  msleep(100);
  set_create_total_distance(0);
  while(get_create_total_distance() < distance*10){
    create_drive_direct(rspeed, lspeed);
    if(gmpc(arm1) < up-50) {
      mav(arm1, upspeed);
      mav(arm2, upspeed);
      
      msleep(10);
    }
    
    else if(gmpc(arm1) < up+50) {
      mav(arm1, upspeed);
      mav(arm2, upspeed);
      msleep(10);
    }
  }
}
  
