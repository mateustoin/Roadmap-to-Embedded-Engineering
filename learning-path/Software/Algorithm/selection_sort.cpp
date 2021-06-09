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

void selection_sort(std::vector<int> &A) {
    // [35, 4, 53, 10, 20]
    int smallest_index = 0;

    for(int i=0; i<A.size(); ++i){
        smallest_index = i;

        for(int j=i+1; j<A.size(); ++j){
            if (A[j] < A[smallest_index]){
                smallest_index = j;
            }
        }

        std::swap(A[smallest_index], A[i]);
    }
}

int main() {
    std::vector<int> A = {35, 4, 53, 10, 20};

    print_array(A);
    selection_sort(A);
    print_array(A);

    return 0;
}