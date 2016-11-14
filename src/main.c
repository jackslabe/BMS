/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */

extern void xcptn_xmpl(void);


void SysClk_Init(void)
{

	      MC_CGM.AC3_SC.B.SELCTL = 0x01;		    //connect XOSC to the PLL0 input
	      MC_CGM.AC4_SC.B.SELCTL = 0x01;		    //connect XOSC to the PLL1 input

	      // Set PLL0 to 50 MHz with 40MHz XOSC reference
	      PLLDIG.PLL0DV.R = 0x3008100A;	     // PREDIV =  1, MFD = 10, RFDPHI = 8, RFDPHI1 = 6

	      MC_ME.RUN0_MC.R = 0x00130070;		    // RUN0 cfg: IRCON,OSC0ON,PLL0ON,syclk=IRC

	      // Mode Transition to enter RUN0 mode:
	      MC_ME.MCTL.R = 0x40005AF0;		    // Enter RUN0 Mode & Key
	      MC_ME.MCTL.R = 0x4000A50F;		    // Enter RUN0 Mode & Inverted Key
	      while (MC_ME.GS.B.S_MTRANS) {};		    // Wait for mode transition to complete
	      while(MC_ME.GS.B.S_CURRENT_MODE != 4) {};	    // Verify RUN0 is the current mode

	      // Set PLL1 to 200 MHz with 40MHz XOSC reference
	      PLLDIG.PLL1DV.R = 0x00020014;	     // MFD = 20, RFDPHI = 2

	      MC_ME.RUN_PC[0].R = 0x000000FE;		    // enable peripherals run in all modes
	      MC_ME.RUN0_MC.R = 0x001300F4;		    // RUN0 cfg: IRCON, OSC0ON, PLL1ON, syclk=PLL1

	      MC_CGM.SC_DC0.R = 0x80030000;    // PBRIDGE0/PBRIDGE1_CLK at syst clk div by 4 ... (50 MHz)

	      // Mode Transition to enter RUN0 mode:
	      MC_ME.MCTL.R = 0x40005AF0;		    // Enter RUN0 Mode & Key
	      MC_ME.MCTL.R = 0x4000A50F;		    // Enter RUN0 Mode & Inverted Key
	      while (MC_ME.GS.B.S_MTRANS) {};		    // Wait for mode transition to complete
	      while(MC_ME.GS.B.S_CURRENT_MODE != 4) {};	    // Verify RUN0 is the current mode
}

void InitPeriClkGen(void)
{
	      // MC_CGM.SC_DC0.R = 0x80030000;    // PBRIDGE0/PBRIDGE1_CLK at syst clk div by 4 ... (50 MHz)
	      MC_CGM.AC0_SC.R = 0x02000000;    // Select PLL0 for auxiliary clock 0
	      MC_CGM.AC0_DC0.R = 0x80090000;    // MOTC_CLK : Enable aux clk 0 div by 10 �(5 MHz)
	      MC_CGM.AC0_DC1.R = 0x80070000;    // SGEN_CLK : Enable aux clk 0 div by 8 �(6.25 MHz)
	      MC_CGM.AC0_DC2.R = 0x80010000;    // ADC_CLK : Enable aux clk 0 div by 2 �(25 MHz)
	      MC_CGM.AC6_SC.R = 0x04000000;    // Select PLL1 for auxiliary clock 6
	      MC_CGM.AC6_DC0.R = 0x80010000;    // CLKOUT0 : Enable aux clk 6 div by 2 �(100 MHz)
	      MC_CGM.AC10_SC.R = 0x04000000;    // Select PLL1 for auxiliary clock 10
	      MC_CGM.AC10_DC0.R = 0x80030000;    // ENET_CLK : Enable aux clk 10 div by 4 �(50 MHz)
	      MC_CGM.AC11_SC.R = 0x04000000;    // Select PLL1 for auxiliary clock 11
	      MC_CGM.AC11_DC0.R = 0x80030000;    // ENET_TIME_CLK : Enable aux clk 11 div by 4 �(50 MHz)
	      MC_CGM.AC5_SC.R = 0x02000000;    // Select PLL0 for auxiliary clock 5
	      MC_CGM.AC5_DC0.R = 0x80000000;    // LFAST_CLK : Enable aux clk 5 div by 1 �(50 MHz)
	      MC_CGM.AC2_DC0.R = 0x80010000;    // CAN_PLL_CLK : Enable aux clk 2 (PLL0) div by 2 �(25 MHz)
	      MC_CGM.AC1_DC0.R = 0x80010000;    // FRAY_PLL_CLK : Enable aux clk 1 (PLL0) div by 2 �(25 MHz)
	      MC_CGM.AC1_DC1.R = 0x80010000;    // SENT_CLK : Enable aux clk 1 (PLL0) div by 2 �(25 MHz)
}

static void GPIO_Init(void)
{
   SIUL2.MSCR[3].R = 0x32000000; 	//PA[0] GPIO - LED_CTRL1
   SIUL2.GPDO[3].R = 0x01;
}

void PIT_Init(void)
{
// PIT Timer Initialization
    PIT_0.MCR.B.MDIS = 0;               //Enable PIT_0 timers
    PIT_0.TIMER[0].LDVAL.R = 5999999;   // setup timer 0 for 5000000 cycles
    PIT_0.TIMER[0].TCTRL.B.TIE = 1;     // Timer interrupt enable
    PIT_0.TIMER[0].TCTRL.B.TEN = 1;     // start Timer
}//PIT_Init

void PIT_ISR(void)
{
    PIT_0.TIMER[0].TCTRL.B.TEN = 1;     // stop PIT_0 Timer
    SIUL2.GPDO[3].R = ~SIUL2.GPDO[3].R ;   ////PA[0] GPIO - LED
    PIT_0.TIMER[0].TFLG.B.TIF = 1;     // Clear PIT_0 interrupt flag
    PIT_0.TIMER[0].TCTRL.B.TEN = 1;     // sart PIT_0 Timer
}//PIT_ISR


int main(void)
{
	volatile int counter = 0;
	
	xcptn_xmpl ();              /* Configure and Enable Interrupts */
	SysClk_Init();

	PIT_Init();
	GPIO_Init();


	/* Loop forever */
	for(;;) {	   
	   	counter++;
	}
}
