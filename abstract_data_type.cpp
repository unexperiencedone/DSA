#include<iostream>
using namespace std;

struct myArray{
    int used_size;
    int total_size;
    int *ptr;
};

void createArray(myArray*a,int  used_size,int total_size){
    a->total_size = total_size;
    a->used_size = used_size;
    a->ptr = new int [a->total_size];
}

void dataEntry(myArray*a){
    cout<<"Now running data entry . . . . \n";
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<"\nEnter the element: "<< i <<endl;
        cin>>(a->ptr)[i];
    }
}
void show(myArray*a){
    cout<<"\nNow runninng show function. . . .\n";
    for (int i = 0; i < a->used_size; i++)
    {
        cout<<(a->ptr)[i]<<" ";
    }
    
}
    

int main(){
    myArray *a = new myArray;
    int used_size;
    int total_size;

    cout<<"\nEnter the total space to be alloacated to the array: ";
    cin>>total_size;

    cout<<"\nEnter the no. of elements for this current entry: ";
    cin>>used_size;

    cout<<"\nNow running the create Array function . . . . \n";
    createArray(a,used_size,total_size);
    dataEntry(a);
    show(a);

    delete[] a->ptr;
    delete[] a;
    return 0;
}