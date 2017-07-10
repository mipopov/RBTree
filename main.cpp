#include "RBTree.h"
#include <cstring>

int main(){
	RBNode<int,int> node(4,4);
	RBTree<int, int>tr;
	Insert(tr, node);
	return 0;
}
