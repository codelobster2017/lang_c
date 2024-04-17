#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <windows.h>
#define MAX_LENGTH_MONTH 44640 //Maximum number of minutes per month

struct sensor {
    uint8_t day;
    uint8_t month;
    uint8_t hour;
    uint8_t minute;
    uint16_t year;
    int8_t t;
};


void SortByT(struct sensor* info,int n);
void SortByDate(struct sensor* info,int n);
void print(struct sensor* info,int number);
void showHelp();
void processCSVFile(int *size, struct sensor *info, char* filename, int monthFilter);
void calculateStatistics(struct sensor* data, int size);
void printWarning();
void stopWarning();
