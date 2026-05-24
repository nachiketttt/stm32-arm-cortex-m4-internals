# Privilege Levels & Thumb ISA Demo

A bare-metal STM32 program that demonstrates:

- Dropping from **privileged → unprivileged** Thread Mode by writing to the CONTROL register
- How **Handler Mode** (ISR) is always privileged regardless of Thread Mode's privilege level
- What happens when you call a function via a **hardcoded address without bit 0 set**, the processor expects Thumb ISA and triggers a **HardFault**
- Software-triggering an interrupt via **STIR/ISER0** directly (only works from privileged mode)

