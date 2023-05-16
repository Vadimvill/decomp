#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#pragma pack(push, 1)
typedef struct {
    char signature[2];  // ��������� ����� (BM)
    int size;           // ������ ����� � ������
    int reserved;       // ����������������� ��������
    int dataOffset;    // �������� ������ ������������ ������ �����
    int headerSize;    // ������ ���������
    int width;          // ������ ����������� � ��������
    int height;         // ������ ����������� � ��������
    short planes;       // ���������� ����������
    short bitsPerPixel;  // ��� �� �������
    int compression;    // ������ ������
    int imageSize;     // ������ ������ �����������
    int xPixelsPerMeter;  // ���������� �� �����������
    int yPixelsPerMeter;  // ���������� �� ���������
    int numColors;     // ���������� ������ � �������
    int importantColors;   // ���������� ������ ������
} BMPHeader;
#pragma pack(pop)
#pragma pack(push, 1)
typedef struct {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
}Pixel;
#pragma pack(pop)
float SetValue(float a);
char isBMP(const char* path);
char is24BitBmp(BMPHeader* header);
void gammaCorrection(BMPHeader* header, const char* path, Pixel* pixel, double gamma);
void insertionSort(unsigned char arr[], int n);
Pixel** createCopy(Pixel** pixel, int col, int row);
void MediumFilter(BMPHeader* header, const char* path, Pixel* pixel, int size);
BMPHeader* readBMPHeader(const char* path);
Pixel* createStructurePixel(BMPHeader* header, const char* path);
void BmpToNegative(BMPHeader* header, const char* path, Pixel* pixel);
void SaveBmp(BMPHeader* header, const char* path, Pixel* pixel);
void BmpToWhitBlack(BMPHeader* header, const char* path, Pixel* pixel);