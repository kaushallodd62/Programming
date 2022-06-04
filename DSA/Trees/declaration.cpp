// Dynamic Linked Node Representation
class Node {
    public:
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            this->data = val;
        }
};

// Sequential Array Representation
// if father = p, then left-child = 2*p+1, and right-child = 2*p+2 using 0-(n-1) 
// if father = p, then left-child = 2*p, and right-child = 2*p+1 using 1-n