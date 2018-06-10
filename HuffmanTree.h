//
// Created by Clytie on 2018/6/10.
//

#ifndef DAY12_HUFFMANTREE_H
#define DAY12_HUFFMANTREE_H

#include <cstdint>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int32_t partent;
    int32_t left;
    int32_t right;
    int64_t count;
};

class HuffmanTree {
public:
    HuffmanTree(vector<int64_t> & counts);
    ~HuffmanTree();

    void BuildTree();

    int32_t LeafNum;
    vector<vector<int32_t> > paths;
private:
    vector<Node> Tree;
    bool succeed;
};


#endif //DAY12_HUFFMANTREE_H
