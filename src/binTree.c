#include "binTree.h"
#include <stdlib.h>
#include <stdio.h>

void nodeSetup(binNode* node){
    // init function pointers
    node->delete= delete;
    node->setValue = setValue;
    node->setRightNode = setRightNode;
    node->setLeftNode = setLeftNode;
    node->getValue = getValue;
    node->getLeftNode = getLeftNode;
    node->getRightNode = getRightNode; 

    // Set all pointers to NULL
    node->value = NULL;
    node->leftNode = NULL;
    node->rightNode = NULL; 
}


void delete(binNode *node){
    free(node);
}

void setValue(binNode *node, void *newValue, size_t valueSize){
    if (node->value == NULL){
        node->value = malloc(valueSize); 
        if (node->value != NULL)
            memcpy(node->value, newValue, valueSize);
        else{ 
            printf("malloc has failed\n");
        }
    }
    else{ 
        void *newMemory = realloc(node->value, valueSize);
        if (newMemory != NULL){
            // Store the pointer to the previous memory block for later freeing
            void *previousMemory = node->value;

            node->value = newMemory;
            memcpy(node->value, newValue, valueSize);

            // Free the previously allocated memory
            free(previousMemory);
        }
        else{
            printf("realloc has failed\n");
        }
    }
}


void* getValue(binNode *node) {
    if (node->value != NULL){
        return node->value;
    }
    return NULL;
}

void setRightNode(binNode *node, binNode *rightNode){
    if (node->rightNode == NULL){
        node->rightNode = rightNode;
    }
    else {
        void *previousNode = node->rightNode;
        node->rightNode = rightNode;
        free(previousNode);
    }
} 

void setLeftNode(binNode *node,binNode *leftNode){
    if (node->leftNode == NULL){
        node->leftNode = leftNode;
    }
    else {
        void *previousNode = node->leftNode;
        node->leftNode = leftNode;
        free(previousNode);
    }}

binNode * getLeftNode(binNode *node){
    if (node->leftNode != NULL){
        return node->leftNode;      
    }
    return NULL;
}

binNode * getRightNode(binNode *node){
    if (node->rightNode != NULL){
        return node->rightNode;      
    }
    return NULL;
}
