#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size = 0;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;
            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i = 0 ; i<=size;i++){
            cout << arr[i] <<  " " ;
        }cout << endl;
    }

    void deletefromHeap(){
        if(size == 0 ){
            cout << "Heap is Empty" << endl;
            return ;
        }
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftInd = 2*i;
            int rightInd = 2*i-1;

            if(leftInd <= size && arr[i]<arr[leftInd] && arr[leftInd]>arr[rightInd]){
                swap(arr[i] , arr[leftInd]);
                i=leftInd;
            }
            else if(rightInd<=size && arr[i]<arr[rightInd] && arr[rightInd]>arr[leftInd]){
                swap(arr[i],arr[rightInd]);
                i=rightInd;

            }else{
                return;
            }
        }

    }
};

int main(){
    heap h ;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();


    return 0;
}