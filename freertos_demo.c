//*****************************************************************************
//
// freertos_demo.c - Simple FreeRTOS example.
//
// Copyright (c) 2009-2014 Texas Instruments Incorporated.  All rights reserved.
// Software License Agreement
//
// Texas Instruments (TI) is supplying this software for use solely and
// exclusively on TI's microcontroller products. The software is owned by
// TI and/or its suppliers, and is protected under applicable copyright
// laws. You may not combine this software with "viral" open-source
// software in order to form a larger program.
//
// THIS SOFTWARE IS PROVIDED "AS IS" AND WITH ALL FAULTS.
// NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT
// NOT LIMITED TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. TI SHALL NOT, UNDER ANY
// CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR CONSEQUENTIAL
// DAMAGES, FOR ANY REASON WHATSOEVER.
//
// This is part of revision 2.1.0.12573 of the DK-TM4C129X Firmware Package.
//
//*****************************************************************************

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_nvic.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "sensorlib/hw_tmp100.h"
#include "sensorlib/i2cm_drv.h"
#include "sensorlib/tmp100.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"
#include "driverlib/sysctl.h"
#include "grlib/grlib.h"
#include "drivers/frame.h"
#include "drivers/kentec320x240x16_ssd2119.h"
#include "drivers/pinout.h"
#include "drivers/touch.h"
#include "lwip_task.h"
#include "utils/ustdlib.h"


#include "FreeRTOS.h"
#include "task.h"
#include "queue.h"
#include "semphr.h"

uint32_t g_ui32SysClock;
tContext g_sContext;
xQueueHandle xQueue1;
xQueueHandle xQueue2;
xTaskHandle xHandle;
tTMP100 sTMP100;
tI2CMInstance g_sI2CMSimpleInst;
volatile bool g_bTMP100SimpleDone = true;



//*****************************************************************************
//
// Initialize FreeRTOS and start the initial set of tasks.
//
//*****************************************************************************

//
// The function that is provided by this example as a callback when TMP100
// transactions have completed.
void
I2CMSimpleIntHandler(void)
{
//
// Call the I2C master driver interrupt handler.
//
I2CMIntHandler(&g_sI2CMSimpleInst);
}

volatile bool g_bTMP100Done;
//
void TMP100Callback(void *pvCallbackData, uint_fast8_t ui8Status)
{
	//
	// See if an error occurred.
	//
	if(ui8Status != I2CM_STATUS_SUCCESS)
	{
		//
		// An error occurred, so handle it here if required.
		//
	}
	//
	// Indicate that the TMP100 transaction has completed.
	//
	g_bTMP100Done = true;
}

void vTimeTask( void * pvParameters )
{
        /* The parameter value is expected to be 1 as 1 is passed in the
           pvParameters value in the call to xTaskCreate() below. */
     configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
     int count = 0;
     const portTickType xDelay = 1000 / portTICK_RATE_MS;

     for( ;; )
     {
           count++;

           xQueueOverwrite( xQueue1,&count );
           vTaskDelay( xDelay );


     }
}

void vTemperatureTask( void * pvParameters )
{
        const portTickType xDelay = 1000 / portTICK_RATE_MS;
     	float fTemperature;
//     	tTMP100 sTMP100;
     	//
     	// Initialize the TMP100. This code assumes that the I2C master instance has already been initialized.
     	//
     	while(1){
     	g_bTMP100Done = false;
     	TMP100Init(&sTMP100, &g_sI2CMSimpleInst, 0x4a, TMP100Callback, 0);
     	while(!g_bTMP100Done)
     	{
     	}
     	//
     	// Configure the TMP100 for 12-bit conversion resolution.
     	//
     	g_bTMP100Done = false;
     	TMP100ReadModifyWrite(&sTMP100, TMP100_O_CONFIG, ~TMP100_CONFIG_RES_M,TMP100_CONFIG_RES_12BIT, TMP100Callback, 0);
     	while(!g_bTMP100Done)
     	{
     	}
     	//
     	// Loop forever reading data from the TMP100. Typically, this process
     	// would be done in the background, but for the purposes of this example it
     	// is shown in an infinite loop.
     	//

     		//
     		// Request another reading from the TMP100.
     		//
     		g_bTMP100Done = false;
     		TMP100DataRead(&sTMP100, TMP100Callback, 0);
     		while(!g_bTMP100Done)
     		{
     		}
     		//
     		// Get the new temperature reading.
     		//
     		TMP100DataTemperatureGetFloat(&sTMP100, &fTemperature);
     		//
     		// Do something with the new temperature reading.
     		//
     		xQueueOverwrite( xQueue2, &fTemperature);
     		vTaskDelay( xDelay );


     	}
}

void vDisplayTask( void * pvParameters )
{
        /* The parameter value is expected to be 1 as 1 is passed in the
           pvParameters value in the call to xTaskCreate() below. */
     configASSERT( ( ( uint32_t ) pvParameters ) == 1 );
    // int count = 0;
    const portTickType xDelay = 500 / portTICK_RATE_MS;
    int time;
            float ftemp;
            int temp;
     for( ;; )
     {
          // count++;
    	 xQueuePeek(xQueue1, &time, 1);
    	         xQueuePeek(xQueue2, &ftemp, 1);
           char sec[20];
           usprintf(sec, "Time: %d", time);
           if (time<6 || time >9 ){
           GrStringDraw(&g_sContext, sec, -1,120, 108, 1);
          vTaskDelay( xDelay );
           }
           char ctemp[20];
           temp = ftemp*10;
           usprintf(ctemp, "Temperature: %d.%d", temp/10, temp%10);
           GrStringDraw(&g_sContext, ctemp, -1,120, 140, 1);



     }
}


/* Function that creates a task. */
//void vOtherFunction( void )
//{
//portBASE_TYPE xReturned;
//
//
//    [/code-comment]/* Create the task, storing the handle. */[/code-comment]
//    xReturned =      /* Used to pass out the created task's handle. */
//
//    if( xReturned == pdPASS )
//    {
//        /* The task was created.  Use the task's handle to delete the task. */
//        vTaskDelete( xHandle );
//    }
//}


int
main(void)
{
    //
    // Run from the PLL at 120 MHz.
    //
    g_ui32SysClock = MAP_SysCtlClockFreqSet((SYSCTL_XTAL_25MHZ |
                                             SYSCTL_OSC_MAIN |
                                             SYSCTL_USE_PLL |
                                             SYSCTL_CFG_VCO_480),
                                            configCPU_CLOCK_HZ);

    //
    // Initialize the device pinout appropriately for this board.
    //
    PinoutSet();

    //
    // Initialize the display driver.
    //
    Kentec320x240x16_SSD2119Init(g_ui32SysClock);

    //
    // Initialize the graphics context.
    //
    GrContextInit(&g_sContext, &g_sKentec320x240x16_SSD2119);

    //
    // Draw the application frame.
    //
    FrameDraw(&g_sContext, "PiSOwZP - TMP100 & WWW");

    //
    // Make sure the main oscillator is enabled because this is required by
    // the PHY.  The system must have a 25MHz crystal attached to the OSC
    // pins.  The SYSCTL_MOSC_HIGHFREQ parameter is used when the crystal
    // frequency is 10MHz or higher.
    //
    SysCtlMOSCConfigSet(SYSCTL_MOSC_HIGHFREQ);

    SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C6);
    I2CMInit(&g_sI2CMSimpleInst, I2C6_BASE, INT_I2C6, 0xff, 0xff, 80000000);


#if (RUN_HTTP_SERVER)   //Change this constant in lwip_task.h if you want to run the HTTP server
    //
    // Create the lwIP tasks.
    //

    if(lwIPTaskInit() != 0)
    {
        GrContextForegroundSet(&g_sContext, ClrRed);
        GrStringDrawCentered(&g_sContext, "Failed to create lwIP tasks!", -1,
                             GrContextDpyWidthGet(&g_sContext) / 2,
                             (((GrContextDpyHeightGet(&g_sContext) - 24) / 2) +
                              24), 0);
        while(1)
        {
        }
    }

#endif




    //Create your tasks here...
    xTaskCreate(        vTimeTask,       /* Function that implements the task. */
                        "Time",          /* Text name for the task. */
                        1024,      /* Stack size in words, not bytes. */
                        ( void * ) 1,    /* Parameter passed into the task. */
                        3,/* Priority at which the task is created. */
                        NULL );

    xTaskCreate(        vTemperatureTask,       /* Function that implements the task. */
                            "Temperature",          /* Text name for the task. */
                            1024,      /* Stack size in words, not bytes. */
                            ( void * ) 1,    /* Parameter passed into the task. */
                            4,/* Priority at which the task is created. */
                            NULL );

    xTaskCreate(        vDisplayTask,       /* Function that implements the task. */
                            "Display",          /* Text name for the task. */
                            1024,      /* Stack size in words, not bytes. */
                            ( void * ) 1,    /* Parameter passed into the task. */
                            2,/* Priority at which the task is created. */
                            NULL );


    xQueue1 = xQueueCreate( 10, sizeof(int ) );
    xQueue2 = xQueueCreate( 10, sizeof(float ) );
    //
    // Start the scheduler.  This should not return.
    //
    vTaskStartScheduler();

    //
    // In case the scheduler returns for some reason, print an error and loop
    // forever.
    //
    GrContextForegroundSet(&g_sContext, ClrRed);
    GrStringDrawCentered(&g_sContext, "Failed to start scheduler!", -1,
                         GrContextDpyWidthGet(&g_sContext) / 2,
                         (((GrContextDpyHeightGet(&g_sContext) - 24) / 2) + 24),
                         0);
    while(1)
    {
    }
}
