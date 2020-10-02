/*
 * @lc app=leetcode.cn id=558 lang=cpp
 *
 * [558] 四叉树交集
 */

// @lc code=start
/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    bool checkTrue(Node *node) {
        return node && node->isLeaf && node->val;
    }
    Node* intersect(Node* quadTree1, Node* quadTree2) {
        if (quadTree1 == nullptr || quadTree2 == nullptr) return nullptr;
        else if (quadTree1->isLeaf && quadTree2->isLeaf) {
            return new Node(quadTree1->val | quadTree2->val, true);
        }
        Node *node;
        if (!quadTree1->isLeaf && !quadTree2->isLeaf) {
            node = new Node();
            node->topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
            node->topRight = intersect(quadTree1->topRight, quadTree2->topRight);
            node->bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
            node->bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
        } else {
            // quadTree1->isLeaf || quadTree2->isLeaf
            Node *tree1 = quadTree1->isLeaf ? quadTree1 : quadTree2; // leaf
            Node *tree2 = quadTree1->isLeaf ? quadTree2 : quadTree1;

            if (tree1->val) node =  new Node(true, true);
            else node = tree2;
        }
        if (checkTrue(node->topLeft) && checkTrue(node->topRight) 
            && checkTrue(node->bottomLeft) && checkTrue(node->bottomRight)) {
            node = new Node(true, true);
        }
        return node;
    }
};
// @lc code=end

