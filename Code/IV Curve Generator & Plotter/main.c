
//Link to ploting code https://github.com/InductiveComputerScience/pbPlots
//Link to PV IV curve equations https://www.researchgate.net/publication/271583193_Modeling_of_photovoltaic_module_and_experimental_determination_of_serial_resistance
#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include "pbPlots.h"
#include "supportLib.h"

//Chateristics of the solar panel
#define Voc 21.0f //Open circuit voltage
#define Isc 0.6f //Short circuit current
#define Vm 17.0f //Max power point voltage
#define Im 0.55f //Max power point current

int main(void)
{

	double currentLUT[400];
	double voltageLUT[400];
	double C2 = 0;
	double C1 = 0;
	double C2Voc = 0;

	C2 = ((Vm/Voc) - 1) / (log(1 - (Im / Isc)));
	printf("%f \n", C2);
	C1 = (1 - (Im / Isc)) * exp((-Vm) / (C2 * Voc));
	printf("%f \n", C1);

	C2Voc = C2 * Voc;

	

	for (int voltageIndex = 0; voltageIndex < 400; voltageIndex++) {
		double outputCurrent = Isc * (1 - C1 * (exp(voltageIndex*0.1 / C2Voc) - 1)); //Gives the current for a given voltage
		voltageLUT[voltageIndex] = voltageIndex*0.1;
		currentLUT[voltageIndex] = outputCurrent;
		printf("Current %f Voltage %d\n", outputCurrent, voltageIndex);
    }

//Below is not my code. This is used to plot the IV curve roughly
	_Bool success;

	RGBABitmapImageReference *canvasReference = CreateRGBABitmapImageReference();
	StringReference *errorMessage = CreateStringReference(L"", 0);
	success = DrawScatterPlot(canvasReference, 600, 400, voltageLUT, 400, currentLUT, 400, errorMessage);

	if(success){
		size_t length;
		double *pngdata = ConvertToPNG(&length, canvasReference->image);
		WriteToFile(pngdata, length, "example1.png");
		DeleteImage(canvasReference->image);
	}else{
		fprintf(stderr, "Error: ");
		for(int i = 0; i < errorMessage->stringLength; i++){
			fprintf(stderr, "%c", errorMessage->string[i]);
		}
		fprintf(stderr, "\n");
	}

	FreeAllocations();

	return success ? 0 : 1;

    for (int index = 0; index < 4095; index++) {
        printf("Current %hu", currentLUT[index]);
    }

}

