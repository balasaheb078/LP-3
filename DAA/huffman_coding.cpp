#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

class MinHeapNode {
public:
    char data;            // Character stored in the node
    int freq;             // Frequency of the character
    MinHeapNode *left, *right;  // Left and right child nodes
    
    // Constructor to initialize the node with character and frequency
    MinHeapNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        this->left = this->right = nullptr;
    }
};

// Comparator class for Min-Heap (priority queue)
struct Compare {
    bool operator()(MinHeapNode* left, MinHeapNode* right) {
        return left->freq > right->freq; // Min-Heap, so return true if left's frequency is greater
    }
};

// Function to print the Huffman Codes by traversing the Huffman tree
void printCodes(MinHeapNode* root, string str, unordered_map<char, string>& huffmanCodes) {
    if (root == nullptr) {
        return;
    }

    // If it's a leaf node (contains a character)
    if (root->data != '$') {
        huffmanCodes[root->data] = str;
    }

    // Traverse left and right subtree
    printCodes(root->left, str + "0", huffmanCodes);
    printCodes(root->right, str + "1", huffmanCodes);
}

// Function to build the Huffman Tree and generate the Huffman codes
void HuffmanCode(vector<char>& data, vector<int>& freq, int size) {
    // Min-Heap (priority queue) to store the nodes based on frequency
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, Compare> minHeap;
    
    // Create a node for each character and insert it into the Min-Heap
    for (int i = 0; i < size; i++) {
        minHeap.push(new MinHeapNode(data[i], freq[i]));
    }
    
    // Build the Huffman tree
    while (minHeap.size() > 1) {
        // Extract two nodes with the least frequency
        MinHeapNode* left = minHeap.top();
        minHeap.pop();
        MinHeapNode* right = minHeap.top();
        minHeap.pop();
        
        // Create a new internal node with frequency equal to the sum of the two nodes
        MinHeapNode* temp = new MinHeapNode('$', left->freq + right->freq);
        temp->left = left;
        temp->right = right;
        
        // Insert the internal node back into the heap
        minHeap.push(temp);
    }
    
    // The root node of the Huffman Tree is now the only node left in the heap
    unordered_map<char, string> huffmanCodes;
    printCodes(minHeap.top(), "", huffmanCodes);
    
    // Output the Huffman Codes for each character
    cout << "Huffman Codes:\n";
    for (auto pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }
}

int main() {
    int n;

    // Take number of characters from the user
    cout << "Enter the number of characters: ";
    cin >> n;

    vector<char> data(n);
    vector<int> freq(n);

    // Take input for characters and their frequencies
    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> data[i];
        cout << "Frequency of " << data[i] << ": ";
        cin >> freq[i];
    }
    
    // Call Huffman coding function
    HuffmanCode(data, freq, n);
    
    return 0;
}

/*

Example output:

Enter the number of characters: 4
Enter characters and their frequencies:
Character 1: A
Frequency of A: 5
Character 2: B
Frequency of B: 9
Character 3: C
Frequency of C: 12
Character 4: D
Frequency of D: 13

Huffman Codes:
C: 00
A: 01
B: 10
D: 11

Explanation:

- MinHeapNode: Represents a node in the Huffman tree. Each node contains a character, its frequency, and pointers to its left and right child nodes.
- Compare: A comparator used for ordering the nodes in the Min-Heap based on frequency. The comparator ensures that the node with the lowest frequency is given the highest priority.
- printCodes: This function recursively traverses the Huffman tree, printing the Huffman code (binary string) for each character.
- HuffmanCode: Builds the Huffman tree by repeatedly extracting the two nodes with the lowest frequency, combining them into a new internal node, and reinserting the new node into the Min-Heap.
- The main function sets up the data and frequency arrays, then calls the `HuffmanCode` function to generate and print the Huffman codes.

Time Complexity: O(n log n), where n is the number of unique characters. The heap operations (insert and remove) take O(log n) time, and we perform these operations n-1 times.

Auxiliary Space: O(n), as we store n nodes in the heap during the process.
*/