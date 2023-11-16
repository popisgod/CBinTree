#include <stdio.h> 
#include <stdlib.h>
#include "binTree.h"

int main(){
    NODE_SETUP(node);
    node.setValue(&node, "special", sizeof("special"));

    
    NODE_SETUP(child);
    child.setValue(&child, "poop", sizeof("poop"));
    node.setLeftNode(&node, &child);
    free(&child);

    binNode *childNode = (binNode*) node.getLeftNode(&node);
    char *value = (char*)((childNode->getValue)(childNode));
    printf("&s", value);

    return 0; 
}