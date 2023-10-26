#include <iostream>
#include <cstdlib>

class SkipNode {
public:
    int key;
    SkipNode** forward;

    SkipNode(int k, int level) : key(k) {
        forward = new SkipNode*[level + 1];
        for (int i = 0; i <= level; ++i) {
            forward[i] = nullptr;
        }
    }

    ~SkipNode() {
        delete[] forward;
    }
};

class SkipList {
public:
    SkipList(int maxLevels, float probability) : MAX_LEVELS(maxLevels), probability(probability) {
        level = 0;
        header = new SkipNode(-1, MAX_LEVELS);
    }

    ~SkipList() {
        delete header;
    }

    // Generate a random level for a new node
    int randomLevel() {
        int lvl = 0;
        while (static_cast<float>(rand()) / RAND_MAX < probability && lvl < MAX_LEVELS) {
            lvl++;
        }
        return lvl;
    }

    // Insert a key into the Skip List
    void insert(int key) {
        SkipNode* update[MAX_LEVELS + 1];
        SkipNode* current = header;

        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
            update[i] = current;
        }

        current = current->forward[0];

        if (current == nullptr || current->key != key) {
            int newLevel = randomLevel();
            if (newLevel > level) {
                for (int i = level + 1; i <= newLevel; i++) {
                    update[i] = header;
                }
                level = newLevel;
            }

            SkipNode* newNode = new SkipNode(key, newLevel);

            for (int i = 0; i <= newLevel; i++) {
                newNode->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = newNode;
            }
        }
    }

    // Search for a key in the Skip List
    bool search(int key) {
        SkipNode* current = header;
        for (int i = level; i >= 0; i--) {
            while (current->forward[i] != nullptr && current->forward[i]->key < key) {
                current = current->forward[i];
            }
        }
        current = current->forward[0];
        return (current != nullptr && current->key == key);
    }

    void display() {
        for (int i = 0; i <= level; i++) {
            SkipNode* node = header->forward[i];
            std::cout << "Level " << i << ": ";
            while (node != nullptr) {
                std::cout << node->key << " ";
                node = node->forward[i];
            }
            std::cout << std::endl;
        }
    }

private:
    const int MAX_LEVELS;
    const float probability;
    int level;
    SkipNode* header;
};

int main() {
    SkipList skipList(4, 0.5); // Max levels and probability

    skipList.insert(10);
    skipList.insert(20);
    skipList.insert(30);
    skipList.insert(40);

    skipList.display();

    std::cout << "Searching for 20: " << skipList.search(20) << std::endl; // Should be true
    std::cout << "Searching for 25: " << skipList.search(25) << std::endl; // Should be false

    return 0;
}
