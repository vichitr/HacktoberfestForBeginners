#include <stdlib.h>
#include <stdio.h>

//data type to be stored in the heap
typedef int elem;
//max number of elements in the heap
#define MAX_SIZE 100

//easily passing from index zero to index one
#define PARENT (((pos+1)/2)-1)  //truncate division
#define LEFT ((pos+1)*2-1)
#define RIGHT (((pos+1)*2+1)-1)
//failed to allocate memory
#define MEM_ERR 1

//heap data type definition
struct heap{
    elem *list;
    int size;
};

//FUNCTIONS
//constructors
int init_heap(int size, struct heap *heap);
struct heap *heapify(elem *list, int size);
//destructor
void destroy_heap(struct heap *heap);
//actions
void insert(elem a, struct heap *heap);
elem extract_min(struct heap *heap);
elem remove_min(struct heap *heap);
//internal functions
int sift_up(int pos, struct heap *heap);
int sift_down(int pos, struct heap *heap);

//Simple use of heap for sorting
int main(){
    elem list[8] = {45, 42, 26, 48, 86, 39, 46, 30};
    struct heap *heap;
    heap = heapify(list, 8);
    int i;
    for(i=0; i<8; i++){
        printf("%d ", remove_min(heap));
    }
    putchar('\n');

    destroy_heap(heap);
    return 0;
}

//Returns 0 if sucessfull or MEM_ERR if it fails to allocate memory
int init_heap(int size, struct heap *heap){
    heap->size = 0;
    heap->list = malloc(sizeof(elem)*size);
    if(heap->list == NULL) return MEM_ERR;
    return 0;
}

//Returns heap if sucessfull or NULL if it fails to allocate memory
struct heap *heapify(elem *list, int size){

    struct heap *heap = malloc(1*sizeof(struct heap));
    //Check for failures when allocating the heap
    if(heap==NULL) return NULL;
    if (init_heap(MAX_SIZE, heap) == MEM_ERR){
        free(heap);
        return NULL;
    }

    //Copy list to heap
    int i;
    for(i=0; i<size; i++) heap->list[i] = list[i];
    heap->size = size;

    if (size <= 1) {return heap;} //list is already heap

    //Every leaf is a heap, pos is the first non-leaf node
    int pos = size-1;
    pos = PARENT;
    //Put the smallest on top
    while(pos >= 0){
        sift_down(pos, heap);
        pos--;
    }

    return heap;
}

void destroy_heap(struct heap *heap){
    heap->size=0;
    free(heap->list);
}

void insert(elem a, struct heap *heap){
    int pos = heap->size;   //Inserting in the end of the list
    heap->list[pos] = a;
    heap->size++;
    //Pulls the last element up the heap
	sift_up(pos, heap);
}

elem extract_min(struct heap *heap){
    return heap->list[0];
}

elem remove_min(struct heap *heap){
    elem min = heap->list[0];
    //Puts last element on top
    heap->list[0] = heap->list[--heap->size];
    //Pushes the first element down the heap
    sift_down(0, heap);
    return min;
}

int sift_up(int pos, struct heap *heap){
    elem aux;
    while(heap->list[pos] < heap->list[PARENT]){
        aux = heap->list[pos];
        heap->list[pos] = heap->list[PARENT];
        heap->list[PARENT] = aux;
        pos = PARENT;
    }
	return pos;
}

int sift_down(int pos, struct heap *heap){
	elem aux;
    while(RIGHT < heap->size){
        if(heap->list[LEFT] <= heap->list[RIGHT] && heap->list[LEFT] < heap->list[pos]){
            aux = heap->list[pos];
            heap->list[pos] = heap->list[LEFT];
            heap->list[LEFT] = aux;
            pos = LEFT;
        }
        else if(heap->list[RIGHT] < heap->list[pos]){
            aux = heap->list[pos];
            heap->list[pos] = heap->list[RIGHT];
            heap->list[RIGHT] = aux;
            pos = RIGHT;
        }
        else{   //current is the smallest
            return pos;
        }
    }

    //Last parent has one child
    if(LEFT < heap->size && heap->list[LEFT] < heap->list[pos]){
        aux = heap->list[LEFT];
        heap->list[LEFT] = heap->list[pos];
        heap->list[pos] = aux;
    }

	return pos;
}
