template<typename T>
class BinaryNode {
    public:
    T data;
    BinaryNode *left;
    BinaryNode *right;

    BinaryNode(T data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    ~BinaryNode() {
        delete this->left;
        delete this->right;
    }
};


template<typename T>
class LinkedListNode {
    public:
    T data;
    LinkedListNode *next;

    LinkedListNode(T data) {
        this->data = data;
        this->next = NULL;
    }
};

