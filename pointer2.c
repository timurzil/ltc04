#include <stdlib.h>
#include <stdio.h>

int reverse_sort(const void *arg_1, const void *arg_2)
{
    int* first = (int*) arg_1;
    int* second = (int*) arg_2;
      
    if (*first < *second) return 1;
        else if (*first == *second) return 0;
            else return -1;

}

int double_sort(const void *arg_1, const void *arg_2)
{
    double* first = (double*) arg_1;
    double* second = (double*) arg_2;
   
    if (*first < *second) return 1;
        else if (*first == *second) return 0;
            else return -1;

}

void my_swap(void* p1, void* p2, int len)
{
    char* a = (char*) p1;
    char* b = (char*) p2;
    char tmp;
   //         printf("swap 0 %d %d\n", *a, *b);

    for (int n=0; n != len; ++n)
    {
        tmp = a[n];
        a[n] = b[n];
        b[n] = tmp;
     //printf("swap 1 %d %d\n", *a, *b);
    }
  //  printf("swap 0 %d %d %d\n", temp1,*(int*)p1, *(int*)p2);
 //   temp1 = *(int*)p1;
 //   temp2 = *(int*)p2;
  //  printf("swap 1 %d %d %d\n", temp1,*(int*)p1, *(int*)p2); 
  //  *(int*)p1 =  temp2;
  //  printf("swap 2 %d %d %d\n", temp1,*(int*)p1, *(int*)p2);
  //  *(int*)p2 = temp1;
  //  printf("swap 3 %d %d %d\n", temp1,*(int*)p1, *(int*)p2);
}

void my_qsort(void* my_object, int length, int element_size, int compare_fun(const void *arg_1, const void *arg_2))
{

    int i, j, n;
    int k = 0;
    void* p;
    void* e;
    void* s;
    void* temp;

    n = 0;
    k =(int) length / 2;
    if (k < 1) return;
    //printf("Variable k: %d\n", k);
   i = length;
   //j = -1;
    while (j < i) 
    {   
        p = my_object + (k-1) * element_size;
        i = length-1;
        j = 0;
        e =my_object + i * element_size;
        s = my_object + j * element_size;
        while ((compare_fun(e, p) == 1))
        {   
            i--;
     //       printf("Variables i: %d %d %d %d %d %d\n", i, j, length, *(int*) p,*(int*) e,k);
            e = my_object + i * element_size;
        }   



        while ((compare_fun(p, s) == 1) )
        {   
     //       printf("Variables j: %d %d %d %d %d\n", i, j, length, *(int*) p, *(int*) s);
            j++;
            s = my_object + j * element_size;
        }   

         // i = k ;
            //printf("Values to swap: %d %d\n", *(int*) e, *(int*) s);
        my_swap(e,s,element_size);
   //  printf("Values after swap: %d %d\n", *(int*) e, *(int*) s);

    
         
    }  

    my_qsort(my_object, k, element_size, *compare_fun);
    my_qsort(my_object + k * element_size, length - k, element_size, *compare_fun);

     
        
    }




void main()
{
    int arr[] = {1,7,6,3,4,11,9,10,2,15,8,14,5};
    double arr1[] = {1.3,7.7,6.4,3.333,4.66,11,9.7,10.4,2.77,15.8,8.6,14.6,5.6};
    //char* arr2[] = {"alex","John","serge","vlad"};
    int size_int = sizeof(int);
    int size_double = sizeof(double);

    //qsort(&arr, sizeof(arr)/size_int, size_int, *reverse_sort);

    my_qsort(&arr, sizeof(arr)/size_int, size_int, *reverse_sort);
    my_qsort(&arr1, sizeof(arr1)/size_double, size_double, *double_sort);

    for (int m=0;m<sizeof(arr)/size_int;m++)
    {
        printf("Sorted array: %d %d\n",m, arr[m]);
    }

    for (int m=0;m<sizeof(arr1)/size_double;m++)
    {
        printf("Sorted array: %d %.3f\n",m, arr1[m]);
    }

}