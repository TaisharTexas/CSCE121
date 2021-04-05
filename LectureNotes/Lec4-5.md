## References to Pointer Variables

instead of returning a pointer array
    int* resize(int* array, int& capacity);

return nothing and reference the pointer
    void resize(int*& array, int& capacity);
instead of returning the memory address of the new array, just reassign the pointer of the old array to the new array
