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
        for (int n = 0; n <= _depth; ++n) {
            for (int i = 0; i <= n; ++i) {
                std::cout << "Node(" << n << ", " << i << "): " << _tree[n][i] << std::endl;
            }
        }
    }
};
#endif