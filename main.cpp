// Include header file for standard input/output stream library
#include <iostream>
using namespace std;
#include <exception>
// Your implementation of the add functions starts here...
// void add(... array1, ... n1, .... array2, ... n2, ... array3, ...n3)
// {
//    ...
// }
void populateArray(int* buff, int len)  {
    for(int i=0; i <len; i++)   {
        *(buff+i) = i;
    }
}

void dumpArray(int* buff, int len)  {
    for(int i=0; i <len; i++)   {
        std::cout << *(buff+i) << "\t";
    }
    std::cout << std::endl;
}

int sum(int* buff, int len) {
    if(len < 0) throw runtime_error("Array length must be larger than 0");
    int val = 0;
    for(int i = 0; i < len; i++)   {
        val += *(buff+i);
    }
    return val;
}

void add(int* array1, int n1, int* array2, int n2, int** array3, int& n3)    {
    if(n1 <0 || n2 <0)  throw runtime_error("Array lengths must be positive or zero");
    if(array1 == nullptr || array2 == nullptr || array3 == nullptr)  throw runtime_error("Arrays must not point to nullptr");
    if(*array3 == nullptr)  throw runtime_error("Array 3 must not dereference to nullptr");

    n3 = std::max(n1,n2);
    *array3 = new int[n3];
    for(int i = 0; i < std::min(n1, n2); i++)   {
        *((*array3)+i) = *(array1+i) + *(array2+i);
    }
    if(n1 != n2)    {
        if(n1<n2)   {
            for(int i = std::min(n1,n2); i < n2; i++)   {
            *((*array3)+i) = *(array2+i);
            }
        }
        else{
            for(int i = std::min(n1,n2); i < n1; i++)   {
            *((*array3)+i) = *(array1+i);
            }
        }
    }
    n3 = sum(*array3, n3);
}

// The global main function that is the designated start of the program
int main(int argc, char *argv[]){

    // Read integer values n1 and n2 from the command line
    int n1, n2;
    if (argc > 2) {
        // If command line arguments are available, use them
        n1 = std::atoi(argv[1]);
        n2 = std::atoi(argv[2]);
        std::cout << "args received" << std::endl;
    } else {
        // If not, use these default values
        n1 = 10;
        n2 = 15;
    }
    // std::cout << n1 << "\t" << n2 << std::endl;
    // Allocate and initialize integer arrays array1 and array2
    // ...
    int* array1 = new int[n1];
    populateArray(array1, n1);

    int* array2 = new int[n2];
    populateArray(array2, n2);

    int n3 = 0;
    int* array3;
    add(array1, n1, array2, n2, &array3, n3);
    dumpArray(array1, n1);
    dumpArray(array2, n2);
    dumpArray(array3, std::max(n1,n2));
    std::cout << "n3: " << n3 << std::endl;

    delete[] array1;
    delete[] array2;
    delete[] array3;
    // Test your add function
    // ...

    // Return code 0 to the operating system (= no error)
    return 0;
}