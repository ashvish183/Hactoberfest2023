#include <iostream>
#include <vector>

void generatePowerSet(std::vector<int>& set, std::vector<int>& subset, int index) {
    if (index == set.size()) {
        // Print the subset
        std::cout << "{ ";
        for (int i : subset) {
            std::cout << i << " ";
        }
        std::cout << "}\n";
        return;
    }

    // Include the current element and generate subset
    subset.push_back(set[index]);
    generatePowerSet(set, subset, index + 1);

    // Exclude the current element and generate subset
    subset.pop_back();
    generatePowerSet(set, subset, index + 1);
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the set: ";
    std::cin >> n;

    std::vector<int> set(n);
    std::cout << "Enter the elements of the set:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> set[i];
    }

    std::vector<int> subset;

    std::cout << "Power set:\n";
    generatePowerSet(set, subset, 0);

    return 0;
}

