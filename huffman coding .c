#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

class Node {
public:
    char data;
    float freq;
    Node *left, *right;

    Node(char d, float f) {
        data = d;
        freq = f;
        left = right = NULL;
    }
};

class Compare {
public:
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Modified to return the total bits used by Huffman encoding
float calculateCompressedSize(Node* root, string code, float totalBits) {
    if (root == NULL) return 0;

    if (root->left == NULL && root->right == NULL) {
        cout << root->data << " : " << code << endl;
        return root->freq * code.length(); // freq * bit length
    }

    return calculateCompressedSize(root->left, code + "0", totalBits) +
           calculateCompressedSize(root->right, code + "1", totalBits);
}

void HuffmanCoding(char data[], float freq[], int size) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    float totalFrequency = 0;
    for (int i = 0; i < size; i++) {
        pq.push(new Node(data[i], freq[i]));
        totalFrequency += freq[i];
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* newNode = new Node('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        pq.push(newNode);
    }

    Node* root = pq.top();
    cout << "\nHuffman Codes:\n";

    float compressedBits = calculateCompressedSize(root, "", 0);

    // Assuming 8 bits per character for standard ASCII original size
    float originalBits = totalFrequency * 8;

    cout << "\nOriginal Size (8-bit fixed): " << originalBits << " bits";
    cout << "\nCompressed Size: " << compressedBits << " bits";
    cout << "\nCompression Ratio: " << (originalBits / compressedBits) << ":1" << endl;
}

int main() {
    int n;
    cout << "Enter number of characters: ";
    cin >> n;

    char data[50];
    float freq[50];

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) cin >> data[i];

    cout << "Enter frequencies: ";
    for (int i = 0; i < n; i++) cin >> freq[i];

    HuffmanCoding(data, freq, n);
    return 0;
}
