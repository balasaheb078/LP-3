import heapq
from collections import defaultdict

# Node structure for the Huffman tree
class HuffmanNode:
    def __init__(self, char, freq):
        self.char = char
        self.freq = freq
        self.left = None
        self.right = None

    # Comparator for the priority queue (min-heap)
    def __lt__(self, other):
        return self.freq < other.freq

# Recursive function to generate and store the Huffman codes
def generate_codes(root, code, huffman_code):
    if root is None:
        return

    # If it's a leaf node, it contains one of the input characters
    if not root.left and not root.right:
        huffman_code[root.char] = code

    # Traverse the left and right children, adding "0" and "1" to the code respectively
    generate_codes(root.left, code + "0", huffman_code)
    generate_codes(root.right, code + "1", huffman_code)

# Function to build the Huffman Tree
def build_huffman_tree(chars, freqs):
    # Create a priority queue (min-heap) to hold nodes sorted by frequency
    min_heap = []

    # Create a leaf node for each character and add it to the min-heap
    for i in range(len(chars)):
        heapq.heappush(min_heap, HuffmanNode(chars[i], freqs[i]))

    # Build the Huffman tree by repeatedly combining two lowest frequency nodes
    while len(min_heap) > 1:
        # Extract the two nodes with the lowest frequency
        left = heapq.heappop(min_heap)
        right = heapq.heappop(min_heap)

        # Create a new internal node with these two nodes as children
        node = HuffmanNode('$', left.freq + right.freq)
        node.left = left
        node.right = right

        # Add the new node back to the min-heap
        heapq.heappush(min_heap, node)

    # The root of the Huffman tree is the only node left in the heap
    return min_heap[0]

def main():
    # Input number of characters and their frequencies
    n = int(input("Enter the number of characters: "))
    
    chars = []
    freqs = []
    
    print("Enter characters and their frequencies:")
    for i in range(n):
        char = input(f"Character {i+1}: ")
        freq = int(input(f"Frequency of {char}: "))
        chars.append(char)
        freqs.append(freq)
    
    # Build the Huffman Tree
    root = build_huffman_tree(chars, freqs)
    
    # Generate Huffman codes for each character
    huffman_code = {}
    generate_codes(root, "", huffman_code)
    
    # Output the generated Huffman codes
    print("\nHuffman Codes:")
    for char, code in huffman_code.items():
        print(f"{char}: {code}")

if __name__ == "__main__":
    main()
