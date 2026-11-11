# Design and Analysis of Algorithms

C++ implementations of the classic algorithms covered in a Design and Analysis of Algorithms course, grouped by topic.

## 01 · Sorting
| Algorithm | File | Time complexity |
|---|---|---|
| Insertion Sort | [InsertionSort.cpp](01-Sorting/InsertionSort.cpp) | O(n²) |
| Merge Sort | [MergeSort.cpp](01-Sorting/MergeSort.cpp) | O(n log n) |
| Quick Sort | [QuickSort.cpp](01-Sorting/QuickSort.cpp) | O(n log n) avg, O(n²) worst |
| Heap Sort | [HeapSort.cpp](01-Sorting/HeapSort.cpp) | O(n log n) |

## 02 · Divide and Conquer
| Algorithm | File | Time complexity |
|---|---|---|
| Integer Multiplication (Karatsuba) | [IntegerMultiplication.cpp](02-Divide-and-Conquer/IntegerMultiplication.cpp) | O(n^1.585) |

## 03 · Trees
| Algorithm | File |
|---|---|
| Binary Tree | [BinaryTree.cpp](03-Trees/BinaryTree.cpp) |
| Binary Search Tree | [BST.cpp](03-Trees/BST.cpp) |
| Inorder Traversal | [InOrder.cpp](03-Trees/InOrder.cpp) |
| Preorder Traversal | [PreOrder.cpp](03-Trees/PreOrder.cpp) |
| Postorder Traversal | [PostOrder.cpp](03-Trees/PostOrder.cpp) |

## 04 · Graphs
**Traversal**
| Algorithm | File | Time complexity |
|---|---|---|
| Breadth-First Search | [BFS.cpp](04-Graphs/Traversal/BFS.cpp) | O(V + E) |
| Depth-First Search | [DFS.cpp](04-Graphs/Traversal/DFS.cpp) | O(V + E) |

**Shortest Path**
| Algorithm | File | Time complexity |
|---|---|---|
| Dijkstra | [Dijkstra.cpp](04-Graphs/Shortest-Path/Dijkstra.cpp) | O((V + E) log V) |
| Bellman-Ford | [BellmanFord.cpp](04-Graphs/Shortest-Path/BellmanFord.cpp) | O(V · E) |
| Floyd-Warshall | [FloydWarshall.cpp](04-Graphs/Shortest-Path/FloydWarshall.cpp) | O(V³) |

**Minimum Spanning Tree**
| Algorithm | File | Time complexity |
|---|---|---|
| Prim's | [Prims.cpp](04-Graphs/Minimum-Spanning-Tree/Prims.cpp) | O(E log V) |
| Kruskal's | [Kruskal.cpp](04-Graphs/Minimum-Spanning-Tree/Kruskal.cpp) | O(E log E) |

## 05 · Greedy
| Algorithm | File | Time complexity |
|---|---|---|
| Fractional Knapsack | [FractionalKnapsack.cpp](05-Greedy/FractionalKnapsack.cpp) | O(n log n) |
| Huffman Coding | [Huffman.cpp](05-Greedy/Huffman.cpp) | O(n log n) |

## 06 · Dynamic Programming
| Algorithm | File | Time complexity |
|---|---|---|
| 0/1 Knapsack | [Knapsack.cpp](06-Dynamic-Programming/Knapsack.cpp) | O(n · W) |
| Longest Common Subsequence | [LCS.cpp](06-Dynamic-Programming/LCS.cpp) | O(n · m) |
| Sequence Alignment | [SequenceAlignment.cpp](06-Dynamic-Programming/SequenceAlignment.cpp) | O(n · m) |

## 07 · Backtracking
| Algorithm | File | Time complexity |
|---|---|---|
| N-Queens | [NQueens.cpp](07-Backtracking/NQueens.cpp) | O(n!) |

## Running a program
```bash
g++ -std=c++17 01-Sorting/MergeSort.cpp -o mergesort
./mergesort
```
