#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> removeDuplicates(vector<int> &A){
    vector<int> output;
    unordered_map<int, bool> myMap;

    for (auto item : A){
        if (myMap.count(item) > 0)
            continue;
        
        myMap[item] = true;
        output.push_back(item);
    }

    return output;
}


int main(){
    vector<int> input = {3, 5, 7, 5, 3, 1, 9, 2, 1, 3, 1};

    for(auto item : removeDuplicates(input)){
        cout << item << " ";
    }
    
    return 0;
}