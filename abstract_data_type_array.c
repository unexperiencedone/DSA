#include<stdio.h>
#include<stdlib.h>
int deleteRun = 0;
struct myArray{
    int total_size;
    int used_size;
    int *ptr;
};
void createArray(struct myArray* a, int tSize, int uSize){
    //(*a).total_size = tSize;
    //(*a).used_size = uSize;
    //(*a).ptr =  (int *) malloc(tSize*sizeof(int));// Dynamically allocating memory whenthe function is called it will allocate memory to the pointer malloc is used to allocate memory tsize is the size of the array and sizeof(int) is the size of the data type that is stored in the array they are multiplied to get the total size of the array tsize will ensure that the memory is allocated to the array according to the size we want of the array to be created and the sizeof(int) will ensure that the memory alloacted is in accordance with the memory required by that particular data type
    a -> total_size = tSize;
    a -> used_size = uSize;
    a -> ptr = (int *) malloc(tSize*sizeof(int)); // This is as same as the above code but here we are using the arrow operator to acces the members of the structure
    }

void show(struct myArray* a){
    for (int i = 0; i < a -> used_size; i++)
    {                       
        printf("%d\n",(a -> ptr)[i]);      
    }
    
}
void setVal(struct myArray* a){
    int n;
    for (int i = 0; i < a->used_size; i++)
    {
        printf("Enter element %d:\n",i);
        scanf("%d",&n);
        (a->ptr)[i] = n;
    }
    
}
void delete(struct myArray*a){
    int b;
    int deleted_index;
    int found =0;
    printf("Enter the element to be deleted: ");
    scanf("%d", &b);
    for (int i = 0; i < a->used_size; i++)
    {
        if(b == (a->ptr)[i]){
            i = deleted_index;
            found = 1;
            deleteRun = 1;
            for (int j = deleted_index; j < a->used_size - 1; j++)
            {
                (a->ptr)[j] = (a->ptr)[j+1];
            }
            printf("Successfully Deleted!\n");
            a-> used_size--;    
            break;
        }
    }
    if (!found){
        printf("No such element was found in the array.\n");
    }
    
}
int main(){
    struct myArray marks;
    createArray(&marks, 100, 5);
    setVal(&marks);
    printf("Now running show function. . .\n");
    show(&marks);
    char c;
    printf("Do you want to delete any element (y/n) ?\n");
    scanf(" %c",&c);// space in the string of the scanf func string is added to skip any newline character or any leftout element in the input buffer 
    if(c == 'y'){
        printf("Now running delete function.\n");
        delete(&marks);
    }
    if(!deleteRun){
        printf("Thank You for using myArray tool.\n");
    }
    else{
        printf("Updated Array:\n");
        show(&marks);
         printf("Thank You for using myArray tool.\n");
    }
    return 0;
}
