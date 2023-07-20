# Megan Holmes Firmware

This repo is a collection of all firmware related code I have written or used. The idea is to maximize how much code I can reuse across projects and controllers. I am using FreeRTOS for my RTOS, SCons as my build system, and Cppcheck for my linter. The linter is automatically called during the SCons build.

Controllers in use: STM32F013RB

## Individual projects:
### Hello World
Prints hello world on the console on Windows. This exists for when I was setting up SCons.

Project Specific Files: ```src/projectSpecific/helloWorld/```

Build command: ```scons --project=helloWorld```
