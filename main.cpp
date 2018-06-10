#include <iostream>
#include <vector>
#include "HuffmanTree.h"

using namespace std;
int main() {
    vector<int64_t> counts = {7, 5, 2, 4, 6, 3, 3};
    HuffmanTree tree(counts);
    tree.BuildTree();
    for (int32_t i = 0; i < tree.LeafNum; ++i) {
        cout << "node weight: " << counts[i] << " | ";
        cout << "node path: leaf<-";
        for (int32_t j = 0; j < tree.paths[i].size(); ++j) {
            cout << tree.paths[i][j];
            if (j < tree.paths[i].size() - 1) {
                cout << "<-";
            }
        }
        cout << "(root)" << endl;
    }
    return 0;
}