#include<iostream>
#include<utility>
using namespace std;

void heapifyUp(int heap[], int size, int index){
    int parent = (index - 1)/2;
    while(index > 0 && heap[index] > heap[parent]){
        swap(heap[index],heap[parent]);
        index = parent;
        parent = (index - 1)/2;
    }
}
void insertToMaxHeap(int heap[], int &size, int value){
    size++;
    int index = size -1;
    heap[index]=value;

    heapifyUp(heap,size,index);
}
void delete_root(int heap[], int &size){
    if(size == 0){
        cout<<"heap is empty"<<endl;
        return;
    }
    heap[0] = heap[size];
    size--;
    int i = 0;
    while(i<size){
        int left = 2*i + 1;
        int right = 2*i + 2;
        if(left<size && heap[i]<heap[left]){
            swap(heap[i],heap[left]);
            i = left;
        }
        else if(right<size&& heap[i]<heap[right]){
            swap(heap[i],heap[right]);
            i = right;
        }
        else{
            return;
        }
    }
}
int main(){
    int heap[101];
    int size = 0;
    // Insert elements into the max heap.
    insertToMaxHeap(heap, size, 125);
    insertToMaxHeap(heap, size, 120);
    insertToMaxHeap(heap, size, 40);
    insertToMaxHeap(heap, size, 60);
    insertToMaxHeap(heap, size, 100);
    insertToMaxHeap(heap, size, 75);
    insertToMaxHeap(heap, size, 58);
    insertToMaxHeap(heap, size, 31);
    for(int i = 0; i<size; i++){
        cout<<heap[i]<<" "<<endl;
    }
}