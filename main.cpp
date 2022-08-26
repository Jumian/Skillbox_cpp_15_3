#include <iostream>
#include "vector"

std::vector<int> arr;
int val =0;

void print(){
    for(int i=0;i<arr.size();++i){
        std::cout<<arr[i]<< " ";
    }
    std::cout<<std::endl;
}

// Shaker sort
void sort(){
    bool notSorted= true;
    int count=0;
    while (notSorted) {
        ++count;
        int moves = 0, start = 0, end = arr.size() - 1;
        for (int i = start; i <= end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                ++moves;
            }
        }
        --end;
        for (int i = end; i > 0; --i) {
            if (arr[i - 1] > arr[i]) {
                std::swap(arr[i], arr[i - 1]);
                ++moves;
            }
        }
        ++start;
        if (moves==0) notSorted=false;
    }
}

void handle(){
    do{
        std::cout << "Input value:";
        std::cin>>val;
        if(val==-2) break;
        else if (val==-1) {
            sort();
            if(arr.size()>=5) std::cout<<"Fifth value is: "<<arr[4]<< std::endl;
            else std::cerr<<std::endl<< "Size of array less then 5" <<std::endl;
        } else arr.push_back(val);
    }while(val!=-2);
}

int main() {
    print();
    handle();
    print();
}
