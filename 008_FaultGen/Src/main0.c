/*
 * main0.c
 *
 *  Created on: May 30, 2026
 *      Author: nachiket
 */
#include <stdint.h>
#include <stdio.h>

int func_divide(int x, int y);

int main(void)
{
	//1. Enable all configurable exceptions like usage fault, mem manage fault and bus fault
	uint32_t *pSHCRS=(uint32_t*)0xE000ED24; //System Handler Control and State Register address

	*pSHCRS|=(1<<16); //mem manage fault enabled
	*pSHCRS|=(1<<17); //bus fault enabled
	*pSHCRS|=(1<<18); //usage fault enabled

	//3. Enable divide by zero trap
	uint32_t *pCCR=(uint32_t *)0xE000ED14; //Configuration and Control Register basea addr
	*pCCR|=(1<<4); //enabling the divide by zero trap

	//4. Attempt to dovde by zero
	func_divide(10,0);

	for(;;);
}

int func_divide(int x, int y)
{
	return x/y;
}

//2. Implement the fault handlers
void HardFault_Handler(void)
{
	printf("Exception: Hard Fault\n");
	while(1);
}

void MemManage_Handler(void)
{
	printf("Exception: Mem manage fault\n");
	while(1);
}

void BusFault_Handler(void)
{
	printf("Exception: Bus Fault\n");
	while(1);
}

__attribute__ ((naked)) void UsageFault_Handler(void)
{
	//this extracted value of the msp is the
	//base addr of the stack frame which got saved during
	//the exception entry from thread mode to the handler mode
	asm ("MRS r0,MSP");
	asm ("B UsageFault_Handler_c");
	//value of r0 will be captured in the variable pBaseStackFrame
	//content of r0 becomes the argument 1 for the callee (the func being called)
}

void UsageFault_Handler_c(uint32_t *pBaseStackFrame)
{
	//asm ("MRS r0,MSP"); This is not used as the c function
	//When executed generates epilogue and prologue sequences which
	//modify the MSP value
	//register uint32_t msp_value asm("r0");
	//uint32_t *pMSP=(uint32_t *)msp_value;
	uint32_t *pUFSR=(uint32_t *)0xE000ED2A; //usage fault status register
	printf("Exception: Usage Fault\n");
	printf("USFR = %lx\n",((*pUFSR)&0xFFFF));
	printf("MSP = %p\n",pBaseStackFrame);
	printf("Value of R0 = %lx\n",pBaseStackFrame[0]);
	printf("Value of R1 = %lx\n",pBaseStackFrame[1]);
	printf("Value of R2 = %lx\n",pBaseStackFrame[2]);
	printf("Value of R3 = %lx\n",pBaseStackFrame[3]);
	printf("Value of R12 = %lx\n",pBaseStackFrame[4]);
	printf("Value of LR = %lx\n",pBaseStackFrame[5]);
	printf("Value of PC = %lx\n",pBaseStackFrame[6]);
	printf("Value of XPSR = %lx\n",pBaseStackFrame[7]);
	while(1);
}
