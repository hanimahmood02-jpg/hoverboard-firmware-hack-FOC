#ifndef CONFIG_H
#define CONFIG_H

#include "stm32f1xx_hal.h"

// ############################### VARIANT SELECTION ###############################
#if !defined(PLATFORMIO)
  #define VARIANT_ADC         
#endif
// ########################### END OF VARIANT SELECTION ############################

// ############################### DO-NOT-TOUCH SETTINGS ###############################
#define PWM_FREQ            20000     
#define DEAD_TIME              120    
#define DELAY_IN_MAIN_LOOP    5     
#define TIMEOUT                20     
#define A2BIT_CONV             50     

#define ADC_CONV_TIME_7C5       (20)  
#define ADC_CONV_CLOCK_CYCLES   (ADC_CONV_TIME_7C5)
#define ADC_CLOCK_DIV           (4)
#define ADC_TOTAL_CONV_TIME     (ADC_CLOCK_DIV * ADC_CONV_CLOCK_CYCLES) 
// ########################### END OF  DO-NOT-TOUCH SETTINGS ############################

#define BOARD_VARIANT           1         

// ############################### BATTERY SETTINGS ###############################
#define BAT_FILT_COEF           655       
#define BAT_CALIB_REAL_VOLTAGE  4800      
#define BAT_CALIB_ADC           1492      
#define BAT_CELLS               10        
#define BAT_LVL2_ENABLE         0         
#define BAT_LVL1_ENABLE         0         
#define BAT_DEAD_ENABLE         1         
#define BAT_BLINK_INTERVAL      80        

#define BAT_DEAD                (400 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE    
// ######################## END OF BATTERY ###############################

// ############################### TEMPERATURE ###############################
#define TEMP_WARNING_ENABLE     0         
#define TEMP_POWEROFF_ENABLE    0         
// ######################## END OF TEMPERATURE ###############################

// ############################### MOTOR CONTROL #########################
#define COM_CTRL        0               
#define SIN_CTRL        1               
#define FOC_CTRL        2               

#define OPEN_MODE       0               
#define VLT_MODE        1               
#define SPD_MODE        2               
#define TRQ_MODE        3               

#define MOTOR_LEFT_ENA                  
#define MOTOR_RIGHT_ENA                 

#define N_MOTORS                2

#define CTRL_TYP_SEL    FOC_CTRL        
#define CTRL_MOD_REQ    SPD_MODE        

#define I_MOT_MAX       6.0             
#define I_DC_MAX        5
#define N_MOT_MAX       900             

#define FIELD_WEAK_ENA  0               
// ########################### END OF MOTOR CONTROL ########################

// ############################## DEFAULT SETTINGS ############################
#define INACTIVITY_TIMEOUT        0       
#define BEEPS_BACKWARD            0       

#define SOFT_START
#define DEFAULT_RATE              20      
#define SOFT_START_MS             7000    
#define SPEED_RPM_REQ             700     
#define POWER_ON_RECOVERY         1       
#define CURRENT_SOFT_LIMIT        1       
#define VOLTAGE_DERATE_ENABLE     1       

#define DEFAULT_FILTER              6553  
#define DEFAULT_SPEED_COEFFICIENT   16384 
#define DEFAULT_STEER_COEFFICIENT   0     
// ######################### END OF DEFAULT SETTINGS ##########################

// ############################## INPUT FORMAT ############################
#ifdef VARIANT_ADC
  #define CONTROL_ADC         1           
  #define PRI_INPUT1            1, 0, 0, 4095, 0      
  #define PRI_INPUT2            1, 0, 0, 4095, 0      
  #define FLASH_WRITE_KEY       0x1001    
#endif
// ############################# END OF VARIANT_ADC SETTINGS #########################

#endif /* CONFIG_H */
