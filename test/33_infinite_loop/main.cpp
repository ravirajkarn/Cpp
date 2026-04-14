#include <iostream>
#include <string>
#include <vector>
#include <numeric> // For std::accumulate
#include <algorithm> // for std::next_permutation and std::sort
#include <chrono>

void arr_func(std::vector<std::string> set){ // TODO: there a one very little mistake behind the my logic. 
    std::vector<int> array(set.size(), 0); 
    int n = array.size() - 1;
    int temp = 0, count = 1;
    for(int i=0; true; i++, count++){
        if(i >= n || i < 0) 
        i = 0;
    
        for(int j=0; j<=n ; j++){
            if(array.at(j) > n)
            {
                array.at(j-1)++;
                array.at(j) = 0;
            }
            std::cout << array.at(j) << "\t";
            temp = temp + array.at(j);
        }
        std::cout << "\t" << count << "\n";
    
        if(temp == n*(n+1))
            break;
        temp = 0;
        array.at(n)++;
    }
}


// AI generated function to process the input set

// Function to process the input set
void arr_func2(const std::vector<std::string>& set) { // TODO: this same as arr_func but improved by AI
    std::vector<int> array(set.size(), 0); 
    int maxIndex = array.size() - 1;

    
    while (true) {
        // Reset index if it goes out of bounds
        for (int i = 0; i <= maxIndex; ++i) {
            if (array[i] > maxIndex) {
                if (i > 0) {
                    array[i - 1]++;
                }
                array[i] = 0;
            }
            std::cout << set.at(array[i]) << "\t";
        }
        std::cout << "\n";
    
        // Calculate the sum of the array
        int sum = std::accumulate(array.begin(), array.end(), 0);
    
        // Break the loop if the sum matches the termination condition
        if (sum == maxIndex * (maxIndex + 1)) {
            break;
        }
    
        // Increment the last element and reset the sum
        array[maxIndex]++;
    }
}

// permutation without repetition.
void printpermutation(std::vector<std::string> &set) // * Best method to find permutation.
{
    std::sort(set.begin(), set.end());

    do
    {
        for (const auto &temp : set)
        {
            std::cout << temp << "\t";
        }
        std::cout << std::endl;
    } while (std::next_permutation(set.begin(), set.end()));
    
}


//* method to find permutation with repetition  
//start 
void generatePermutationsWithRepetition(std::vector<std::string> set, int k, std::vector<std::string>& currentPermutation) {
    if (k == 0) {
        // Base case: We have filled all k positions, print the permutation
        for (const auto& str : currentPermutation) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
        return;
    }

    for (const auto& element : set) {
        currentPermutation[currentPermutation.size() - k] = element; // Place each element at the current position
        generatePermutationsWithRepetition(set, k - 1, currentPermutation); // Recurse for the next position
    }
}

void printPermutationsWithRepetition(std::vector<std::string> set, int length) {
    if (set.empty() || length <= 0) {
        return;
    }

    std::vector<std::string> currentPermutation(length);
    generatePermutationsWithRepetition(set, length, currentPermutation);
}
// end

int main()
{
    std::vector<std::string> set = {"A", "B", "C"};
    
    std::cout << "first function.\n";
    auto start = std::chrono::high_resolution_clock::now();
    arr_func(set);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "\nTime taken by the first function: " << duration.count() << " miliseconds\n";
    
    std::cout << "Second function.\n";
    start = std::chrono::high_resolution_clock::now();
    arr_func2(set);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout <<"\nTime taken by the second function: " << duration.count() << " miliseconds\n";

    std::cout << "Third function.\n";
    start = std::chrono::high_resolution_clock::now();
    printpermutation(set);
    end = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::microseconds>(end-start);
    std::cout << "\nTime taken byt the third function: " << duration.count() << " miliseconds\n";

    printPermutationsWithRepetition(set, 3);

    std::cout <<"\nend";
    return 0;   
}