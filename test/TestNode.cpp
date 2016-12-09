/***********************************************************************************//**
 * Author:       Steven Ward <stevenward94@gmail.com>
 * File:         L2Copy+Move/src/TestNode.cpp
 * Last Change:  2016 Nov 10
 ***********************************************************************************/

#include "Node.h"

int main(void) {

    single_link::Node<int> defaultNode;
    single_link::Node<int> dataNode(17);

    single_link::Node<int>* defaultNodePtr = &defaultNode;
    dataNode.setNext(defaultNodePtr);

    std::cout << dataNode.data() << std::endl;

    single_link::Node<int> anotherNode = dataNode;

    std::cout << anotherNode.data() << std::endl;

    defaultNode.setData(53);
    std::cout << dataNode.next()->data() << std::endl;

    return 0;
}
