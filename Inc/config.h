#ifndef CONFIG_H
#define CONFIG_H

#include "stm32f1xx_hal.h"

// ############################### VARIANT SELECTION ###############################
// تم تفعيل VARIANT_ADC ليتناسب مع التحكم عبر المقاومة المتغيرة أو الدخل التماثلي
#if !defined(PLATFORMIO)
  #define VARIANT_ADC         
#endif
// ########################### END OF VARIANT SELECTION ############################


// ############################### DO-NOT-TOUCH SETTINGS ###############################
#define PWM_FREQ            20000     // 20 كيلو هرتز لتشغيل صامت تماماً (FOC)
#define DEAD_TIME              120    // زيادة زمن الحماية للموسفتات
#define DELAY_IN_MAIN_LOOP    5     
#define TIMEOUT                20     
#define A2BIT_CONV             50     

#define ADC_CONV_TIME_7C5       (20)  
#define ADC_CONV_CLOCK_CYCLES   (ADC_CONV_TIME_7C5)
#define ADC_CLOCK_DIV           (4)
#define ADC_TOTAL_CONV_TIME     (ADC_CLOCK_DIV * ADC_CONV_CLOCK_CYCLES) 
// ########################### END OF  DO-NOT-TOUCH SETTINGS ############################

#define BOARD_VARIANT           1         

// ############################### BATTERY (إعدادات المحول 48 فولت) ###############################
#define BAT_FILT_COEF           655       
#define BAT_CALIB_REAL_VOLTAGE  4800      // معايرة لجهد 48 فولت
#define BAT_CALIB_ADC           1492      
#define BAT_CELLS               10        
#define BAT_LVL2_ENABLE         0         
#define BAT_LVL1_ENABLE         0         // إطفاء التنبيهات المزعجة للمحول
#define BAT_DEAD_ENABLE         1         
#define BAT_BLINK_INTERVAL      80        

// حماية الجهد للمحول
#define BAT_DEAD                (400 * BAT_CELLS * BAT_CALIB_ADC) / BAT_CALIB_REAL_VOLTAGE    // فصل عند 40 فولت لحماية المحول
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

// تفعيل مخارج كلا المحركين للعمل معاً بكارت واحد مدمج
#define MOTOR_LEFT_ENA                  
#define MOTOR_RIGHT_ENA                 

// تشغيل المخارج لـ (محركين) لتغذية الجانبين الأيمن والأيسر معاً
#define N_MOTORS                2

// تفعيل التشغيل الصامت وتثبيت السرعة
#define CTRL_TYP_SEL    FOC_CTRL        
#define CTRL_MOD_REQ    SPD_MODE        

// قيود التيار لحماية محول 300 واط
#define I_MOT_MAX       6.0             // تيار المحرك الآمن
#define I_DC_MAX        5
// تيار الدخل الأقصى للمحول
#define N_MOT_MAX       900             // السرعة القصوى المسموحة

#define FIELD_WEAK_ENA  0               // إطفاء لإبقاء المحرك صامتاً
// ########################### END OF MOTOR CONTROL ########################


// ############################## DEFAULT SETTINGS ############################
#define INACTIVITY_TIMEOUT        0       // منع الإغلاق التلقائي
#define BEEPS_BACKWARD            0       

// إعدادات الإقلاع الناعم (Soft Start) لحماية منظومة التشغيل والملفات
#define SOFT_START
#define DEFAULT_RATE              20      // إقلاع ناعم جداً (Ramp)
#define SOFT_START_MS             7000    // الوصول للسرعة خلال 7 ثوانٍ
#define SPEED_RPM_REQ             700     // السرعة المطلوبة للمروحة
#define POWER_ON_RECOVERY         1       // العمل تلقائياً عند وصل الكهرباء
#define CURRENT_SOFT_LIMIT        1       
#define VOLTAGE_DERATE_ENABLE     1       

#define DEFAULT_FILTER              6553  
#define DEFAULT_SPEED_COEFFICIENT   16384 
#define DEFAULT_STEER_COEFFICIENT   0     // إلغاء التوجيه لجعل المحركين يدوران بنفس التزامن
// ######################### END OF DEFAULT SETTINGS ##########################


// ############################## INPUT FORMAT ############################
#ifdef VARIANT_ADC
  #define CONTROL_ADC         1           
  #define PRI_INPUT1            1, 0, 0, 4095, 0      // التحكم بالسرعة عبر المقاومة المتغيرة الأولى
  #define PRI_INPUT2            1, 0, 0, 4095, 0      // ربط المقاومة المتغيرة لتدوير المحرك الثاني متزامناً مع الأول
  #define FLASH_WRITE_KEY       0x1001    
#endif
// ############################# END OF VARIANT_ADC SETTINGS #########################

#end

