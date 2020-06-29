#include "mbed.h"
#include "bbcar.h"

Ticker servo_ticker;
PwmOut pin9(D9), pin8(D8);
BBCar car(pin8, pin9, servo_ticker);
DigitalInOut pin10(D10);
Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);
DigitalOut led2(LED2);
DigitalOut led3(LED3);
Serial uart(D1,D0); // tx,rx OpenMV
Serial xbee(D12, D11); // Xbee
//Serial pc(USBTX,USBRX); // tx,rx
 



void turnleft(){
    while(1){
        car.turn(100 , 0.1);
        wait(1.8);
        led2 = 1;
        break;
    }
}
void turnright(){
    while(1){
        car.turn(100 , -0.1);
        wait(0.8);
        led2 = 1;
        break;
    }
}

int main() {
    xbee.printf("start\r\n");
    led3 = 0;
    parallax_ping  ping1(pin10);
    xbee.printf("straight\r\n");
    //pc.printf("%f\r\n" , (float)ping1 );
    car.turn(100 , 0.34);
    wait(4);
    wait(4);
    wait(2);
   while(1){
         if((float)ping1 < 15) {
             led1 = 0;
             car.stop();
             break; 
        }
         else{
             led1 = 1;
         }
         wait(0.3);
     }
     car.stop();
     wait(0.5);
    xbee.printf("back\r\n");
    car.turn(-100 , 0.34);
    wait(0.5);
    while( (float)ping1 < 18 ){
        car.turn(-100 , 0.32);
        wait(0.01);
     }
     car.stop();
     wait(1);
    xbee.printf("left\r\n");
    car.turn(100 , 0.1);
    wait(1.6);
    /*while( (float)ping1 < 50 || (float)ping1 > 150){ //100
        car.turn(100 , 0.1);
        led2 = 1;
        //pc.printf("%f\r\n" , (float)ping1 );
        //wait(.01);
    }*/
    led2 = 0; 
    xbee.printf("straight\r\n");
    /*turnleft();
    led2 = 0;*/
    led3 = 0;
    car.turn(100 , 0.34);
    wait(4);
    /*float x ;
    while(1){
        x = ping1.ping_cm(); 
        pc.printf("%f\r\n" , x );
        wait(.01);
    }*/
    while(1){
         if((float)ping1 < 18) {
             led1 = 0;
             car.stop();
             break; 
        }
         else{
             led1 = 1;
         }
         wait(0.3);
     }
    car.stop();
    wait(0.5);
    xbee.printf("car back\r\n");
    car.turn(-80 , 0.1);
        wait(2.2);
    car.turn(-100 , 0.34);
        wait(2);
    car.stop();
        wait(1);
    /*****************************************/
    //xbee.printf("straight\r\n");
    //car.turn(100 , 0.32);
    //wait(1);
    
    xbee.printf("straight\r\n");
    car.turn(100 , 0.34);
    wait(0.8);
    while(1){
         if((float)ping1 < 25) {
             led1 = 1;
             car.stop();
             break; 
        }
         else{
             led1 = 0;
         }
         wait(0.3);
     }
    xbee.printf("right\r\n");
    car.stop();
    wait(0.5);
    car.turn(50 , -0.1);
    wait(1.6);
    car.stop();
    wait(0.5);

    xbee.printf("straight\r\n");
    car.turn(100 , 0.34);
    wait(1.3);
    car.stop();
    wait(0.5);

    car.turn(-35 , -0.1);
    wait(1.4);
    car.stop();

    xbee.printf("take photo\r\n");
    char s[21];
    sprintf(s,"image_classification"); // sent the command to OpenMV for taking picture
    uart.puts(s); // sent the command by UART
    wait(2.5);
    xbee.printf("right\r\n");
    car.turn(50 , -0.1);
    wait(1.6);
    /*while( (float)ping1 < 35  || (float)ping1 > 136 ){ // 86
        car.turn(100 , -0.1);
        led2 = 1;
        wait(0.01);
     }*/
    /*turnright();
    led2 = 0;*/
    xbee.printf("straight\r\n");
    car.turn(100 , 0.34);
    wait(2);
    while(1){
         if((float)ping1 < 40) {
             led1 = 1;
             car.stop();
             break; 
        }
         else{
             led1 = 0;
         }
         wait(0.3);
     }
    car.stop();
    wait(2);
    xbee.printf("right\r\n");
    car.turn(50 , -0.1);
    wait(1.5);
    led3 = 1;
   /*while( (float)ping1 < 70  || (float)ping1 > 170 ){ // 120
        car.turn(100 , -0.1);
        led2 = 1;
     }*/
     //turnright();
     //led2 = 0;
     xbee.printf("straight\r\n");
     car.turn(100 , 0.34);
     wait(5);
     while(1){
         if((float)ping1 < 25) {
             led1 = 1;
             car.stop();
             break; 
        }
         else{
             led1 = 0;
         }
         wait(0.3);
     }
     car.stop();
     wait(0.5);
    xbee.printf("right\r\n");
    car.turn(50 , -0.1);
    wait(1.5);
    led3 = 0;
   /* while( (float)ping1 < 50  || (float)ping1 > 150 ){ // 100
        car.turn(100 , -0.1);
        led2 = 1;
     }*/

     //turnright();
     //led2 = 0;
     xbee.printf("straight\r\n");
     car.turn(100 , 0.34);
     wait(3.5);
     xbee.printf("scan\r\n");
     int k = 0;
     float data[40];
     for(k = 0; k < 40; k++)
    {
        data[k] = ping1;
        wait(0.02);
    }
    xbee.printf("right\r\n");
    car.turn(50 , -0.1);
    wait(1.6);
     led2 = 0;
     car.stop();
     wait(1);
    xbee.printf("back\r\n");
    car.turn(-35 , -0.1);
    wait(1.7);

    /*while( (float)ping1 < 30 || (float)ping1 > 70 ){ // 50
        car.turn(100 , 0.1);
        led2 = 1;
     }*/
     //turnleft();
     //led2 = 0;
    /*********************************************************/
    xbee.printf("straight\r\n");
    car.turn(100 , 0.34);
     wait(1);
     while(1){
         if((float)ping1 < 25) {
             led1 = 1;
             car.stop();
             break; 
        }
         else{
             led1 = 0;
         }
         wait(0.3);
     }
    xbee.printf("right\r\n");
    car.turn(50 , -0.1);
    wait(1.6);

    /*while( (float)ping1 < 80  || (float)ping1 > 120 ){ // 100
        car.turn(100 , -0.1);
        led2 = 1;
     }*/
    xbee.printf("straight\r\n");
    car.turn(100 , 0.34);
     wait(1);
     while(1){
         if((float)ping1 < 25) {
             led1 = 1;
             car.stop();
             break; 
        }
         else{
             led1 = 0;
         }
         wait(0.3);
     }
    for(int k = 0; k < 40; k++)
    {
        xbee.printf("%f\n\r",data[k]);
        wait(0.1);
    }
    float judge[40];
    int tri , rec , slop , other = 0;
    for(int k = 0; k < 20; k++)
    {
        judge[k] = data[k+1] - data[k];
        if(judge[k] > 0){
            tri++;
        }
        else if(judge[k] < 0){
            slop++;
        }
        else if(judge[k] == 0){
            rec++;
        }
        else {}
    }
    for(int k = 20; k < 40; k++)
    {
        judge[k] = data[k+1] - data[k];
        if(judge[k] > 0){
            other++;
        }
        else if(judge[k] < 0){
            tri++;
        }
        else if(judge[k] == 0){
            rec++;
        }
        else {}
    }
    if(tri > rec && tri > slop && tri > other){
        xbee.printf("triangle\r\n");
    }else if(rec > tri && rec > slop && rec > other){
        xbee.printf("rectangle\r\n");
    }else if(slop > tri && slop > rec && slop > other){
        xbee.printf("slop\r\n");
    }else if(other > tri && other > rec && other > slop)
    {
        xbee.printf("other\r\n");
    }else {
        xbee.printf("triangle\r\n");
    }
    

     car.stop();
     xbee.printf("end\r\n");
}
