#include <stdlib.h>
#ifndef BIN_NODE_H
#define BIN_NODE_H

typedef struct binNode binNode;
typedef struct binTree binTree; 
#define NODE_SETUP(node) binNode node; nodeSetup(&node)


struct binNode {
    void *value; 
    binNode *leftNode;
    binNode *rightNode; 
    void (*delete) (binNode*);
    void (*setRightNode) (binNode*, binNode*); 
    void (* setLeftNode) (binNode*, binNode*); 
    void* (* getValue) (binNode*);
    void (* setValue) (binNode*, void*, size_t); 
    binNode* (*getLeftNode) (binNode*);
    binNode* (*getRightNode) (binNode*); 
}; 

void delete(binNode*);
void nodeSetup(binNode*); 
void setValue(binNode*, void*, size_t);
void setRightNode(binNode*,binNode*); 
void setLeftNode(binNode*,binNode*); 
void* getValue(binNode*);
binNode* getLeftNode(binNode*);
binNode* getRightNode(binNode*); 

#endif