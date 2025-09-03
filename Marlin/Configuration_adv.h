/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware
 * ...
 */

#ifndef CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H
#define CONFIGURATION_ADV_H_VERSION 020000

// @section temperature

// (kept OEM thermal protection, watchdog, etc.)

#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD 30
  #define THERMAL_PROTECTION_HYSTERESIS 10
  #define WATCH_TEMP_PERIOD 20
  #define WATCH_TEMP_INCREASE 2
#endif

#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD 180
  #define THERMAL_PROTECTION_BED_HYSTERESIS 5
  #define WATCH_BED_TEMP_PERIOD 600
  #define WATCH_BED_TEMP_INCREASE 1
#endif

#if ENABLED(PIDTEMP)
  //#define PID_EXTRUSION_SCALING
#endif

#define AUTOTEMP
#if ENABLED(AUTOTEMP)
  #define AUTOTEMP_OLDWEIGHT 0.98
#endif

//#define SHOW_TEMP_ADC_VALUES

// AD595 calibration (leave OEM)
#define TEMP_SENSOR_AD595_OFFSET 0.0
#define TEMP_SENSOR_AD595_GAIN   2.0

/**
 * Controller Fan (kept OEM)
 */
#define USE_CONTROLLER_FAN
#if ENABLED(USE_CONTROLLER_FAN)
  #define CONTROLLER_FAN_PIN FAN3_PIN
  #define CONTROLLERFAN_SECS 60
  #define CONTROLLERFAN_SPEED 255
#endif

#define FAN_KICKSTART_TIME 100
//#define FAN_MIN_PWM 50

// Extruder auto fans (leave OEM pins/off)
#define E0_AUTO_FAN_PIN -1
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED   255

// Part-Cooling Fan Multiplexer (OEM)
#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1

// Case light (OEM off)
//#define CASE_LIGHT_ENABLE

//===========================================================================
//============================ Mechanical Settings ==========================
//===========================================================================

// Dual X Steppers — must be OFF with dual X carriage
//#define X_DUAL_STEPPER_DRIVERS

// Y dual steppers (OEM)
#define Y_DUAL_STEPPER_DRIVERS
#if ENABLED(Y_DUAL_STEPPER_DRIVERS)
  #define INVERT_Y2_VS_Y_DIR true
#endif

// Z dual steppers + dual endstops (OEM)
#define Z_DUAL_STEPPER_DRIVERS
#if ENABLED(Z_DUAL_STEPPER_DRIVERS)
  #define Z_DUAL_ENDSTOPS
  #if ENABLED(Z_DUAL_ENDSTOPS)
    #define Z2_USE_ENDSTOP _ZMAX_
    #define Z_DUAL_ENDSTOPS_ADJUSTMENT  0
  #endif
#endif

/**
 * Dual X Carriage (IDEX)
 */
#define DUAL_X_CARRIAGE
#if ENABLED(DUAL_X_CARRIAGE)
  // The first X-carriage homes to MIN; the second homes to MAX
  #define X2_MIN_POS 5
  #define X2_MAX_POS 530
  #define X2_HOME_DIR 1
  #define X2_HOME_POS X2_MAX_POS

  // Use FULL CONTROL so G28 X0 / G28 X1 do what we tested
  #define DEFAULT_DUAL_X_CARRIAGE_MODE DXC_FULL_CONTROL_MODE

  // Auto-park parameters (kept OEM in case you switch modes)
  #define TOOLCHANGE_PARK_ZLIFT   2
  #define TOOLCHANGE_UNPARK_ZLIFT 2

  #define DEFAULT_DUPLICATION_X_OFFSET 225
#endif

// Homing bump (OEM)
#define X_HOME_BUMP_MM 5
#define Y_HOME_BUMP_MM 5
#define Z_HOME_BUMP_MM 2
#define HOMING_BUMP_DIVISOR {2, 2, 4}
//#define QUICK_HOME
//#define HOME_Y_BEFORE_X

#define AXIS_RELATIVE_MODES {false, false, false, false}

// Step pulse width (OEM)
#define MINIMUM_STEPPER_PULSE 3

// HEATERS_PARALLEL (OEM off)
//#define HEATERS_PARALLEL

// Buffers (OEM)
#if ENABLED(SDSUPPORT)
  #define BLOCK_BUFFER_SIZE 16
#else
  #define BLOCK_BUFFER_SIZE 16
#endif

// Serial (OEM)
#define MAX_CMD_SIZE 96
#define BUFSIZE 6
#define TX_BUFFER_SIZE 32
//#define RX_BUFFER_SIZE 1024
//#define SERIAL_XON_XOFF
//#define EMERGENCY_PARSER
//#define NO_TIMEOUTS 1000
//#define ADVANCED_OK

// Firmware Retract (OEM off)
//#define FWRETRACT

// Advanced Pause (OEM off)
//#define ADVANCED_PAUSE_FEATURE

// TMC / L6470 sections (left OEM — off unless you enable in your build)

// I2C BUS (OEM)
//#define EXPERIMENTAL_I2CBUS
#define I2C_SLAVE_ADDRESS  0

// Spindle/Laser (OEM off)
//#define SPINDLE_LASER_ENABLE

// Debug, auto-report, capabilities
//#define PINS_DEBUGGING
#define AUTO_REPORT_TEMPERATURES
#define EXTENDED_CAPABILITIES_REPORT

// Volumetric (OEM off)
//#define VOLUMETRIC_DEFAULT_ON

//#define NO_WORKSPACE_OFFSETS

#define PROPORTIONAL_FONT_RATIO 1.0
#define FASTER_GCODE_PARSER

// Custom user menus (OEM off)
//#define CUSTOM_USER_MENUS

// I2C Position Encoders & MAX7219 sections left OEM

#endif // CONFIGURATION_ADV_H
