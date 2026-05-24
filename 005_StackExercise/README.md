# 005_StackExercise

Program that demonstrates switching from the Main Stack Pointer (MSP) to the Process Stack Pointer (PSP) in Thread Mode, then triggering a supervisor call exception.

- Carving out separate MSP and PSP regions in SRAM manually
- Switching to PSP in Thread Mode by writing to the CONTROL register
- How Handler Mode (SVC) always reverts to MSP regardless of Thread Mode's stack
- Firing a software exception via `SVC` instruction

