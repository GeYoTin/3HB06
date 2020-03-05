#include <Arduino_FreeRTOS.h>
#define R_LED 3
#define G_LED 4
#define Y_LED 5
#define O_LED 6
#define PUSH_SW 2
#define POT A0

int display = 0;
int display_time = 500;
int mode = 0;
int pot_val = 0;


void setup() {
  xTaskCreate(Read_Switch, "Read push button switch", 128, NULL, 1, NULL);
  xTaskCreate(Read_Pot, "Read Potentiometer", 128, NULL, 1, NULL);
  xTaskCreate(Display_R_LED, "Red LED Task", 128, NULL, 1, NULL);
  xTaskCreate(Display_G_LED, "Grean LED Task", 128, NULL, 1, NULL);
  xTaskCreate(Display_Y_LED, "Yellow LED Task", 128, NULL, 1, NULL);
  xTaskCreate(Display_O_LED, "Orange LED Task", 128, NULL, 1, NULL);
  vTaskStartSchedular();
}

void Display_R_LED(void *pvParameters) {   
  pinMode(R_LED, OUTPUT);   
  while (1)   
  {     
    if(mode == 0)
    {
      if(display == 0)
      {
        digitalWrite(R_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(R_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
      display++;
    }
    else if(mode == 1)
    {
      if(display == 3)
      {
        digitalWrite(R_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(R_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
    else if(mode == 2)
    {
      if(display != 0)
      {
        digitalWrite(R_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(R_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    } 
  } 
}
 
void Display_G_LED(void *pvParameters) {   
  pinMode(G_LED, OUTPUT);   
  while (1)   
  {     
    if(mode == 0)
    {
      if(display == 1)
      {
        digitalWrite(G_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(G_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
    else if(mode == 1)
    {
      if(display == 2)
      {
        digitalWrite(G_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(G_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
    else if(mode == 2)
    {
      if(display >=2 && display <=6)
      {
        digitalWrite(G_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(G_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    } 
    else if(mode == 3)
    {
      if(display >=3 && display <=6)
      {
        digitalWrite(G_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(G_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
  } 
}

void Display_Y_LED(void *pvParameters) {   
  pinMode(Y_LED, OUTPUT);   
  while (1)   
  {     
    if(mode == 0)
    {
      if(display == 2)
      {
        digitalWrite(Y_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(Y_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
    else if(mode == 1)
    {
      if(display == 1)
      {
        digitalWrite(Y_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(Y_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
    else if(mode == 2)
    {
      if(display >=3 && display <=5)
      {
        digitalWrite(Y_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(Y_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    } 
    else if(mode == 3)
    {
      if(display >=2 && display <=6)
      {
        digitalWrite(Y_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(Y_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
  } 
}

void Display_O_LED(void *pvParameters) {   
  pinMode(O_LED, OUTPUT);   
  while (1)   
  {     
    if(mode == 0)
    {
      if(display == 3)
      {
        digitalWrite(O_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(O_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
    else if(mode == 1)
    {
      if(display == 0)
      {
        digitalWrite(O_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(O_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    }
    else if(mode == 2)
    {
      if(display == 4)
      {
        digitalWrite(O_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(O_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    } 
    else if(mode == 3)
    {
      if(display != 0)
      {
        digitalWrite(O_LED, HIGH);
        vTaskDelay(pdMS_TO_TICKS(display_time));
        digitalWrite(O_LED, LOW);
      }
      else
        vTaskDelay(pdMS_TO_TICKS(display_time));
    } 
  } 
}

void Read_Pot(void *pvParameters){
  while(1)
  {
    pot_val = analogRead(POT);
    delay_time = map(pot_val, 0, 1023, 50, 1500);  
  }
}

void Read_Switch(void *pvParameters){
  pinMode(PUSH_SW, INPUT);
  while(1){
    int sw_status = digitalRead(PUSH_SW);
    if(sw_status==LOW)
    {
      vTaskDelay(pdMS_TO_TICKS(10));
      sw_status = digitalRead(PUSH_SW);
      if(sw_status==LOW)
      {
        while(sw_status==LOW)
        {
          sw_status = digitalRead(PUSH_SW);  
        }
        mode++;
        display=0;
        if(mode>3)
          mode=0;
      }
    }
  }
}
 
void loop() { }
