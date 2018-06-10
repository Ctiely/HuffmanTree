//
// Created by Clytie on 2018/6/10.
//

#include "HuffmanTree.h"
#include <functional>

HuffmanTree::HuffmanTree(vector<int64_t> & counts) {
    succeed = 0; //判断是否构建过Huffman Tree
    sort(counts.begin(), counts.end(), greater<int>());
    LeafNum = counts.size();
    Tree.resize(2 * LeafNum - 1);
    for (int32_t i = 0; i < Tree.size(); ++i) {
        Tree[i].partent = -1;
        Tree[i].left = -1;
        Tree[i].right = -1;
        Tree[i].count = 1e15;
    }
    for (int32_t i = 0; i < LeafNum; ++i) {
        Tree[i].count = counts[i];
    }
    for (int32_t i = 0; i < LeafNum; ++i) {
        paths.push_back(vector<int32_t>());
    }
}

HuffmanTree::~HuffmanTree() {}

void HuffmanTree::BuildTree() {
    if (succeed) {
        return;
    }
    int32_t leaf = LeafNum - 1; //leaf用来保存叶子结点权重最小值
    int32_t node = LeafNum;     //node用来保存非叶子结点权重最小值
    for (int32_t i = LeafNum; i < Tree.size(); ++i) { //构造非叶子结点
        vector<int32_t> mini(2); //保存最小的两个权重
        for (int32_t j = 0; j < 2; ++j) { //从leaf,leaf-1,node,node+1中寻找最小的两个权重
            if (leaf >= 0 && Tree[leaf].count < Tree[node].count) {
                mini[j] = leaf--; //最终leaf会指向未使用的最小权重叶子结点
            } else {
                mini[j] = node++; //最终node会指向未使用的最小权重非叶子结点
            }
        }

        Tree[i].left = mini[0];
        Tree[i].right = mini[1];
        Tree[i].count = Tree[mini[0]].count + Tree[mini[1]].count;
        Tree[mini[0]].partent = i;
        Tree[mini[1]].partent = i;
    }

    for (int32_t i = 0; i < LeafNum; ++i) {
        int32_t j = i; //j是需要变化的节点位置
        while (Tree[j].partent != -1) {
            paths[i].push_back(Tree[j].partent - LeafNum);
            j = Tree[j].partent;
        }
    }
    succeed = 1;
}