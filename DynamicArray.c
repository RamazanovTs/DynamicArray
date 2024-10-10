#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    size_t size;
    size_t capacity;
}DynamicArray;

DynamicArray* createArray();
void addElement(DynamicArray* array,int element);
void printArray(DynamicArray* array);
void removeElement(DynamicArray* array, int index);
int countElement(DynamicArray* array, int elem);

int main() {
    DynamicArray* array = createArray();
    int elem;
    int opt;

    while (1) {
        system("cls");
        printf("\n--- Dynamic Array Menu ---\n");
        printf("1 => Add Element\n");
        printf("2 => Print Array\n");
        printf("3 => Remove Element\n");
        printf("4 => Count Element\n");
        printf("5 => Exit\n");
        printf("--------------------------\n");
        printf("Choose an option: ");
        
        scanf("%d", &opt);
        
        switch (opt) {
            case 1:
                printf("Enter desired number: ");
                scanf("%d", &elem);
                addElement(array, elem);
                printf("Added %d to the array.\n", elem);
                break;

            case 2:
                printf("Current Array: ");
                printArray(array);
                break;

            case 3:
                printf("Enter index of element you want to remove: ");
                scanf("%d", &elem);
                removeElement(array, elem);
                break;

            case 4:
                printf("Enter integer you want to count: ");
                scanf("%d", &elem);
                int count = countElement(array, elem);
                printf("%d count is (%d)\n", elem, count);
                break;

            case 5:
                printf("Exiting program...\n");
                free(array->data);
                free(array);
                return 0;

            default:
                printf("Please enter a valid option!\n");
                break;
        }

        // Wait for user input before continuing
        printf("Press Enter to continue...");
        getchar();  // Consume leftover newline from previous input
        getchar();  // Wait for user to press Enter
    }
}


//Dynamic Array Functions

DynamicArray* createArray(){
    DynamicArray *array=malloc(sizeof(DynamicArray));
    array->size=0;
    array->capacity=4;
    array->data=malloc(sizeof(int)*array->capacity);
    return array;
}

void addElement(DynamicArray* array, int element) {
    if (array->size == array->capacity) {
        int* new_data = realloc(array->data, array->capacity * 2 * sizeof(int));
        if (new_data != NULL) {
            array->data = new_data;
            array->capacity *= 2;
        } else {
            printf("Memory allocation failed!\n");
            return;
        }
    }
    array->data[array->size] = element;
    array->size++;
}

void printArray(DynamicArray* array) {
    if (array->size == 0) {
        printf("Array is empty.\n");
        return;
    }

    printf("[");
    for (size_t i = 0; i < array->size; i++) {
        printf("%d", array->data[i]);
        if (i < array->size - 1) {
            printf(", ");
        }
    }
    printf("]\n");
}

void removeElement(DynamicArray* array, int index) {
    if (index < 0 || index >= array->size) {
        return;
    }
    for (int i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
    array->data[array->size] = 0;

    if (array->size<array->capacity/2 && array->capacity>4)
    {
        int new_cap=array->capacity/2;
        int *new_ptr=realloc(array->data,new_cap*sizeof(int));
        if (new_ptr!=NULL)
        {
            array->data=new_ptr;
            array->capacity=new_cap;
        }else{
            printf("Memory Allocation failed!\n");
        }
        
    }
    
}

int countElement(DynamicArray* array, int elem){
    int count=0;
    for (int i = 0; i < array->size; i++)
    {
        if (array->data[i]==elem)
        {
            count++;
        }
        
    }
    return count;
}

