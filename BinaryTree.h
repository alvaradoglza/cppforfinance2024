#ifndef BINARYTREE_H
#define BINARYTREE_H
#include <vector>
#include <iostream>

template <typename T>
class BinaryTree {
private:
    int _depth;  
    std::vector<std::vector<T>> _tree;  

public:
    
    void setDepth(int depth) {
        _depth = depth;
        _tree.resize(_depth + 1);
        for (int i = 0; i <= _depth; ++i) {
            _tree[i].resize(i + 1);
        }
    }

    
    void setNode(int n, int i, T value) {
        _tree[n][i] = value;
    }

    
    T getNode(int n, int i) const {
        return _tree[n][i];
    }

    
    void display() const {
        int max_width = _depth + 1;  // Maximum width of the tree
        int spacing = 4;            // Spacing between levels for formatting
    
        for (int n = 0; n <= _depth; ++n) {
            // Print leading spaces for alignment
            int offset = (max_width - n) * spacing / 2;
            for (int i = 0; i < offset; ++i) {
                std::cout << " ";
            }
    
            // Print values at level `n`
            for (int i = 0; i <= n; ++i) {
                std::cout << _tree[n][i];
                // Add spaces between nodes at the same level
                if (i < n) {
                    for (int j = 0; j < spacing; ++j) {
                        std::cout << " ";
                    }
                }
            }
            std::cout << std::endl;
    
            // Print slashes (`/` and `\`) to connect levels
            if (n < _depth) {
                // Print leading spaces for the slashes
                int slash_offset = (max_width - n - 1) * spacing / 2;
                for (int i = 0; i < slash_offset; ++i) {
                    std::cout << " ";
                }
    
                // Print slashes between nodes
                for (int i = 0; i <= n; ++i) {
                    std::cout << "/";
                    for (int j = 0; j < spacing - 1; ++j) {
                        std::cout << " ";
                    }
                    std::cout << "\\";
                    if (i < n) {
                        for (int j = 0; j < spacing - 1; ++j) {
                            std::cout << " ";
                        }
                    }
                }
                std::cout << std::endl;
            }
        }
    }
};
#endif