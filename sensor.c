#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
struct sensor {
    uint8_t day;
    uint8_t month;
    uint8_t hour;
    uint8_t minute;
    uint16_t year;
    int8_t t;
};

void calculateStatistics(struct sensor* data, int size, int month);


void cgangeIJ(struct sensor* info, int i, int j) {
    struct sensor temp;
    temp = info[i];
    info[i] = info[j];
    info[j] = temp;
}
void printWarning()
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED);
}
void stopWarning()
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
}
void SortByT(struct sensor* info, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (info[i].t >= info[j].t)
                cgangeIJ(info, i, j);
}

unsigned int DateToInt(struct sensor* info) {
    return info->year << 16 | info->month << 8 | info->day;
}

void SortByDate(struct sensor* info, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i; j < n; ++j)
            if (DateToInt(info + i) >= DateToInt(info + j))
                cgangeIJ(info, i, j);
}



void print(struct sensor* info, int number) {
    printf("===================================\n");
    for (int i = 0; i < number; i++)
        printf("%04d-%02d-%02d t=%3d\n",
            info[i].year,
            info[i].month,
            info[i].day,
            info[i].t
        );
}

void processCSVFile(int* size, struct sensor* info, char* filename, int monthFilter) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printWarning();
        printf("Error: Unable to open file %s\n", filename);
        stopWarning();
        return;
    }
    
    char line[100];
    int index = 0;
    int i     = 0;
    int month = 0;
    int r;
    while(!feof(file))
    {
        int result;
        if ((result = fscanf(file, "%hu;%hhu;%hhu;%hhu;%hhu;%d", &info[index].year, &info[index].month, &info[index].day, &info[index].hour, &info[index].minute, &info[index].t)))
        {
            if(info[index].month != 0 && month  == 0)
            {
                month == info[index].month;
            }
            
            

            if(monthFilter <= 0)
            {
                if(info[index].month != 0 && monthFilter >= 0 && (month != info[index].month))
                {
                    calculateStatistics(info, index, month);
                    month = info[index].month;
                    info[0].year = info[index].year;
                    info[0].month = info[index].month;
                    info[0].day = info[index].day; 
                    info[0].hour  = info[index].hour;
                    info[0].minute = info[index].minute;
                    info[0].t = info[index].t;
                    index = 0;
                }
            }
            
            if (result != 6 && info[index].month >= month) 
            {
                int res;
                int value;
                char valueStr[4];
                
                for (int i = 0; i < 1; i++) 
                {
                    if((res = fscanf(file, "%lld;", &value)) == 0)
                    {
                        fscanf(file, "%s;", &valueStr);
                        printWarning();
                        printf("Warning: Invalid line %d format in file %s (element %d) | invalid value = %s\n", index, filename, result + i + 1, valueStr);
                        stopWarning();
                    }
                    
                }
                
                fscanf(file, "%*[^\n]");
            } 
            else 
            {
                if(monthFilter <= 0 || monthFilter == info[index].month)
                {
                    index++;
                    i++;
                    *size = index;
                }
            }
            
        }
    }
    
    calculateStatistics(info, index, monthFilter);
    fclose(file);
}

void calculateStatistics(struct sensor* data, int size, int month) {
    if (size == 0) {
        return;
    }
    float sum = 0;
    int min_temp = data[0].t;
    int max_temp = data[0].t;
   

    for (int i = 0; i < size; i++) {
        sum += data[i].t;
        if (data[i].t < min_temp) {
            min_temp = data[i].t;
        }

        if (data[i].t > max_temp) {
            max_temp = data[i].t;
        }
    }
    float average_temp = sum / size;

    printf("========================\n");
    printf("Statistics: Month: %d\n", month);
    printf("Average Temperature: %.2f\n", average_temp);
    printf("Min Temperature: %d\n", min_temp);
    printf("Max Temperature: %d\n", max_temp);
    printf("========================\n");
}
void showHelp() {
    printf("Program Usage:\n");
    printf("./sensor_program [-h] [-f filename] [-m monthFilter]\n\n");
    printf("Options:\n");
    printf("-h                  : Show help message\n");
    printf("-f filename         : Specify input CSV file\n");
    printf("-m monthFilter      : Filter data for a specific month (1-12)\n\n");
    printf("Example:\n");
    printf("./sensor_program -f data.csv -m 5\n");

}



