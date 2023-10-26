#include <iostream>
#include <vector>
#include <bitset>
#include <functional>

class BloomFilter {
public:
    BloomFilter(size_t size, size_t numHashFunctions)
        : size_(size), numHashFunctions_(numHashFunctions), bits_(size, false) {}

    void add(const std::string& value) {
        for (size_t i = 0; i < numHashFunctions_; ++i) {
            size_t hash = hashFunction(value, i) % size_;
            bits_[hash] = true;
        }
    }

    bool contains(const std::string& value) {
        for (size_t i = 0; i < numHashFunctions_; ++i) {
            size_t hash = hashFunction(value, i) % size_;
            if (!bits_[hash]) {
                return false;
            }
        }
        return true;
    }

private:
    size_t size_;
    size_t numHashFunctions_;
    std::vector<bool> bits_;

    size_t hashFunction(const std::string& value, size_t index) {
        std::hash<std::string> hasher;
        return hasher(value + std::to_string(index));
    }
};

int main() {
    BloomFilter bloomFilter(1000, 3); // Bloom filter with 1000 bits and 3 hash functions

    bloomFilter.add("apple");
    bloomFilter.add("banana");
    bloomFilter.add("cherry");

    std::cout << "Contains apple: " << bloomFilter.contains("apple") << std::endl; // Should return 1
    std::cout << "Contains pear: " << bloomFilter.contains("pear") << std::endl;   // Should return 0

    return 0;
}
