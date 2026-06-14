# STM32 ARM Cortex-M4 Internals

Deep dive into ARM Cortex-M4 processor architecture and bare metal system 
programming on STM32F446RE. All projects are implemented from scratch without 
HAL or middleware abstraction directly at the register and assembly level.

## Hardware & Stack

| | |
|---|---|
| **Board** | STM32F446RE (Nucleo-64) |
| **Processor** | ARM Cortex-M4 @ 180MHz |
| **IDE** | STM32CubeIDE on Fedora Linux |
| **Toolchain** | ARM GCC |
| **Debug** | SWV ITM Data Console |

## Projects

| # | Project | Concepts |
|---|---------|----------|
| 001 | Operation Modes | Thread mode and Handler mode |
| 002 | Inline Assembly | Inline assembly, processor register access from C |
| 003 | Access Levels | Privileged vs unprivileged mode, CONTROL register, Thumb ISA |
| 004 | Bit Banding | Bit band region, atomic bit manipulation via alias addresses |
| 005 | Stack Exercise | PSP vs MSP, CONTROL register stack switching |
| 006 | USART3 Int Pend | Interrupt pending via software, NVIC ISPR register |
| 007 | Interrupt Priority | IPR register |
| 008 | Fault Gen | UsageFault, BusFault, MemManage fault generation and handlers |
| 009 | SVC Number | SVC instruction, extracting SVC number from opcode in handler |
| 010 | SVC Math | SVC based privileged math execution, service dispatcher |
| 011 | Round Robin Scheduler | Bare metal task scheduler, PendSV, SysTick, PSP context switch, task blocking |
| 012 | Custom Linker | Custom linker script, startup file, bare metal build with OpenOCD + semihosting |


