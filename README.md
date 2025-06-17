# STM32F407 Scheduler Project:

A bare-metal task scheduler for STM32F407, built with timers and interrupts (no RTOS).

# FEATURES:

**Task Scheduler Library**
  - Register and deregister tasks  
  - Each task is driven by its own hardware timer for precise timing  

**Finite State Machines (FSM)**
  - Button Debounce **FSM** (states: Idle -> MaybePressed -> Pressed -> Released)  
  - **Sleep-Mode FSM** triggered by button interrupt

**Peripheral Drivers**
  - **SPI** driver for Winbond W25X20CL flash: read/write operations
  - **ADC** task reading internal temperature sensor
  - **USB CDC** for PC data logging

**Example Tasks**
  - LED blink task
  - Temperature-read task

## Hardware
**Microcontroller**: STM32F407VET6  
**Development Kit**: STM32F407VET6 Development Kit  
**Peripherals**:  
  - Winbond W25X20CL SPI flash  
  - Push-button on PA0 (EXTI)  
  - On-board LED (for blinking task)     

## Software
**IDE**: STM32CubeIDE  
**Toolchain**: ARM GCC 
**CubeMX Configuration**:  
  - Clocks set to 168 MHz via PLL  
  - Timers TIM2…TIM5 used for scheduling  


