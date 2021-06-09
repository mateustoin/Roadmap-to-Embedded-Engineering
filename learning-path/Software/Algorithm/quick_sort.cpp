#include <iostream>
#include <string>
#include <utility>
#include <algorithm>

int main(){
    std::string test = "alo alo marciano";
    std::cout << test << std::endl;
    std::sort(test.begin(), test.end());
    std::cout << test << std::endl;

    return 0;
}