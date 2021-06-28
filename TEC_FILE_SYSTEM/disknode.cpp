#include "disknode.h"
#include "QDebug"
DiskNode::DiskNode()
{
    is_last = true;
}
void DiskNode::add_bit(int bit)
{
    bits.append(bit);

}

int DiskNode::get_bit(int pos)
{
    return bits[pos];
}
DiskNode *DiskNode::get_next()
{
    return next;
}
void DiskNode::set_next(DiskNode *n)
{
    next = n;
}
