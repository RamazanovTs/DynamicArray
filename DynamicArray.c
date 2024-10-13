#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *data;
  size_t size;
  size_t capacity;
} DynamicArray;

DynamicArray *CreateArray() {
  DynamicArray *array = malloc(sizeof(DynamicArray));
  if (!array) {
    printf("Error in memory allocation!\n");
    return NULL;
  }

  array->size = 0;
  array->capacity = 4;

  array->data = malloc(sizeof(int) * array->capacity);
  if (!array->data) {
    free(array);
    printf("Error in memory allocation!\n");
    return NULL;
  }

  return array;
}

void freeArray(DynamicArray **array) {
  if (array && *array) {
    free((*array)->data);
    (*array)->data = NULL;
    free(*array);
    *array = NULL;
  }
}

void expandArray(DynamicArray *array) {
  if (!array) {
    printf("Array not found!\n");
    return;
  }

  size_t new_capacity = array->capacity * 2;
  int *new_data = realloc(array->data, sizeof(int) * new_capacity);
  if (new_data) {
    array->data = new_data;
    array->capacity = new_capacity;
  } else {
    printf("Could not reallocate memory!\n");
  }
}

void shrinkArray(DynamicArray *array) {
  if (!array) {
    printf("Array not found!\n");
    return;
  }

  size_t new_capacity = array->capacity / 2;
  int *new_data = realloc(array->data, sizeof(int) * new_capacity);
  if (new_data && new_capacity >= 4) {
    array->data = new_data;
    array->capacity = new_capacity;
  } else {
    printf("Could not reallocate memory!\n");
  }
}

void addElement(DynamicArray *array, int element) {
  if (!array) {
    printf("Array not found!\n");
    return;
  }

  if (array->size == array->capacity) {
    expandArray(array);
  }
  if (array->size < array->capacity) {
    array->data[array->size++] = element;
  }
}

void removeElement(DynamicArray *array, size_t index) {
  if (!array) {
    printf("Array not found!\n");
    return;
  }

  if (index < array->size) {
    for (size_t i = index; i < array->size - 1; i++) {
      array->data[i] = array->data[i + 1];
    }
    array->size--;
    array->data[array->size] = 0;

    if (array->size < array->capacity && array->capacity > 4) {
      shrinkArray(array);
    }
  } else {
    printf("Invalid index!\n");
  }
}

int getElement(DynamicArray *array, size_t index) {
  if (!array) {
    printf("Array not found!\n");
    return 0;
  }

  if (index < array->size) {
    return array->data[index];
  } else {
    printf("Index out of range!\n");
    return 0;
  }
}

void setElement(DynamicArray *array, size_t index, int element) {
  if (!array) {
    printf("Array not found!\n");
    return;
  }

  if (index < array->size) {
    array->data[index] = element;
  } else {
    printf("Index out of range!\n");
  }
}

int findElement(DynamicArray *array, int element) {
  if (!array) {
    printf("Array not found!\n");
    return -1;
  }

  for (size_t i = 0; i < array->size; i++) {
    if (element == array->data[i]) {
      return i;
    }
  }
  printf("Element not found!\n");
  return -1;
}

void printArray(DynamicArray *array) {
  if (!array) {
    printf("Array not found!\n");
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

int countElement(DynamicArray *array, int element) {
  if (!array) {
    printf("Array not found!\n");
    return -1;
  }

  int count = 0;
  for (size_t i = 0; i < array->size; i++) {
    if (array->data[i] == element) {
      count++;
    }
  }
  return count;
}

int getSize(DynamicArray *array) {
  if (!array) {
    printf("Array not found!\n");
    return -1;
  }
  return array->size;
}

int getCapacity(DynamicArray *array) {
  if (!array) {
    printf("Array not found!\n");
    return -1;
  }
  return array->capacity;
}

void copyArray(void *dest, void *source, size_t numByte) {
  if (!dest || !source) {
    printf("Null pointer in copyArray!\n");
    return;
  }

  char *d = (char *)dest;
  char *s = (char *)source;

  for (size_t i = 0; i < numByte; i++) {
    d[i] = s[i];
  }
}

void reverseArray(DynamicArray *array) {
  if (!array) {
    printf("Array not found!\n");
    return;
  }
  DynamicArray *temp_arr = CreateArray();
  if (!temp_arr) {
    return;
  }
  for (int i = array->size - 1; i >= 0; i--) {
    addElement(temp_arr, array->data[i]);
  }
  copyArray(array->data, temp_arr->data, temp_arr->size * sizeof(int));
  array->size = temp_arr->size;
  freeArray(&temp_arr);
}

void sortArray(DynamicArray *array) {
  // Bubble Sort
  if (!array) {
    printf("Array not found!\n");
    return;
  }

  int temp_val;
  int change;

  do {
    change = 0;
    for (size_t i = 0; i < array->size - 1; i++) {
      if (array->data[i] > array->data[i + 1]) {
        temp_val = array->data[i];
        array->data[i] = array->data[i + 1];
        array->data[i + 1] = temp_val;
        change = 1;
      }
    }
  } while (change);
}
