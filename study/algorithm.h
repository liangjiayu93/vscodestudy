
#include <iostream>
#include <random>  //随机数头文件

int findOddnumberone(int arr[], int len);
int findOddnumbertwo(int arr[], int len, int &a, int &b);
int* generateRandomArry(int maxSize, int maxValue, int& len);
void printfArry(int* arr, int len);
void process(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

void quickSort(int arr[], int left, int right);
void swapArr(int arr[], int left, int right);
int partition(int arr[], int left, int right);

void heapInsert(int arr[], int index);
void heapify(int arr[], int index, int heapSize);
void heapSort(int arr[], int heapSize);