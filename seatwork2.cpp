#include <iostream>
#include <assert.h>

using namespace std;
int main(){
    int *intarr[10];
    int i;

    for (i = 0; i<10; ++i){
        intarr[i] = new int;
        assert(intarr[i] != NULL);

        *intarr[i] = i + 1;
    }    

    for (i = 0; i<10; ++i){
        cout<<intarr[i] <<": "<<*intarr[i]<<endl;
    }
    
    for (i = 0; i<10; ++i){
        delete intarr[i];
    }
}