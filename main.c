#include <stdio.h>
#include "sensor.h"


int main(int argc, char** argv) {
    int size = 0;
    struct sensor data[MAX_LENGTH_MONTH];
    
    if (argc < 2) {
        showHelp();
        return 1;
    }
    printf("\n");
    
    char* filename = NULL;
    int monthFilter = 0;

    for (int i = 1; i < argc; ++i) {
        if (strcmp(argv[i], "-h") == 0) {
            showHelp();
            return 0;
        }
        else if (strcmp(argv[i], "-f") == 0 && i + 1 < argc) {
            filename = argv[i + 1];
        }
        else if (strcmp(argv[i], "-m") == 0 && i + 1 < argc) {
            monthFilter = atoi(argv[i + 1]);
            if(monthFilter <= 0 || monthFilter > 12)
            {
                printWarning();
                printf("Please enter the correct date of the month");
                stopWarning();
                return 2;
            }
        }
    }
    
    if (filename == NULL) {
        printWarning();
        printf("Error: Missing input file argument.\n");
        stopWarning();
        return 1;
    }
    
    processCSVFile(&size, data, filename, monthFilter);
    
    return 0;
}
