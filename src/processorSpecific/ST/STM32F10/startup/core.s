// These instructions define attributes of our chip and
// the assembly language we'll use:
.syntax unified
.cpu cortex-m3
.fpu softvfp
.thumb

// Global memory locations.
.global Reset_Handler

/*
 * The Reset handler. Called on reset.
 */
.type Reset_Handler, %function
Reset_Handler:
  // Set the stack pointer to the end of the stack.
  // The '_estack' value is defined in our linker script.
  LDR  r0, =_estack
  MOV  sp, r0

  // Set some dummy values. When we see these values
  // in our debugger, we'll know that our program
  // is loaded on the chip and working.
  LDR  r7, =0xDEADBEEF
  MOVS r0, #0
  main_loop:
    // Add 1 to register 'r0'.
    ADDS r0, r0, #1
    // Loop back.
    B    main_loop
.size Reset_Handler, .-Reset_Handler
