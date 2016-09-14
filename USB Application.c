// USB Application.cpp : Defines the entry point for the console application.
//

// DelcomDLLExampleC
#include "stdafx.h"
#include "stdio.h"
#include "DelcomDLL.h"
//extern "C" {
//#include "DelcomDLL.h"
//}

int main(int argc, char* argv[])
{
	DeviceNameStruct Names[10]; // array to hold the device names found
	printf("Delcom DLL Test Example C\n");
	int found = DelcomScanDevices(USBDELVI, Names, 10);
	if (found) {
		for (int i = 0; i<found; i++)
			printf("%s SN:%u\n", (char*)&Names[i],
			DelcomReadDeviceSerialNum((char*)&Names[i], NULL));
	}
	else
		printf("No USBDELVI devices found!\n");
	if (found) { // open the device
		HANDLE hUsb = DelcomOpenDevice((char*)&Names[0], 0); DelcomLEDControl(hUsb,
			REDLED, FLASH); DelcomCloseDevice(hUsb); // close the device
	}
	return(0);
}