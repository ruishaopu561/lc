#include "Node.h"

/*
 * Super class: Node
 */
Node::Node()
{
    isRoot = false;
    isLeaf = false;
    parent = NULL;

    keyNum = 0;
    for (int i=0; i<MAXCHILDRENNUM; i++){
        keys[i] == KeyType(0);
    }
}

Node::~Node()
{
    delete parent;
    parent = NULL;
}

/*
 * Internal Node
 */
InternalNode::InternalNode()
{
    nodeNum = 0;
    for(int i=0; i<MAXCHILDRENNUM; i++)
    {
        children[i] = NULL;
    }
}

InternalNode::~InternalNode()
{
    int index = (nodeNum < MAXCHILDRENNUM)?nodeNum:MAXCHILDRENNUM;
    for(int i=0; i<index; i++)
    {
        delete children[i];
        children[i] = NULL;
    }
}

/*
 * Leaf Node
 */
LeafNode::LeafNode()
{
    valueNum = 0;
    for(int i=0; i<MAXCHILDRENNUM; i++)
    {
        values[i] = "";
    }
}

LeafNode::~LeafNode()
{
}
