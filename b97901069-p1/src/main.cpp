#include "fileIO.h"
#include "sortfuc.h"
#include <cstring>
using namespace std;
int main(int argc,char*argv[])
{
    fileIO myfileIO;
    string input_path=argv[2];
    string output_path=argv[3];
    myfileIO.setInputFilePath(input_path);
    myfileIO.setOutputFilePath(output_path);
    myfileIO.readFile();
    sortfuc mysort;
    if(strcmp(argv[1],"-IS")==0){
	mysort.insertionSort(myfileIO.data);
    }
    else if(strcmp(argv[1],"-MS")==0){
	mysort.mergeSort(myfileIO.data);
    }
    else if(strcmp(argv[1],"-HS")==0){
	mysort.heapSort(myfileIO.data);
    }    
    myfileIO.outputFile();

    return 0;
}
