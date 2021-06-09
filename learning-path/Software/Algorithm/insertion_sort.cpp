#include <iostream>
#include <utility>
#include <vector>

void print_array(std::vector<int> &A){
    printf("A = [ ");
    for (int i=0; i<A.size(); i++) {
        printf("%d ", A[i]);
    }
    printf("]\n");
}

void insertion_sort(std::vector<int> &A) {
    int pivo = 0;
    // [35, 4, 53, 10, 20]
    for(int i=1; i < A.size(); ++i) {
        int j = i - 1;

        while(j>=0 && A[j]>A[j+1]){
            std::swap(A[j+1], A[j]);
            --j;
        }
    }
}

int main(){
    std::vector<int> A = {35, 4, 53, 10, 20};

    print_array(A);
    insertion_sort(A);
    print_array(A);

    return 0;
}