#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "RBNode.h"

template<class V, class T>
class RBTree {
public:
	RBTree();
	RBTree(const RBTree<V,T> &tr);
	void LRotation(RBTree<V,T> *tr, RBNode<V,T> *node);
	void RRotation(RBTree<V,T> *tr, RBNode<V,T> *node);
	RBTree<V,T> *Insert(RBTree<V,T> *Tr, RBNode<V,T> *node);
//	RBTree<V,T> *Fixup_Insert(const RBNode<V,T> &root, const RBNode<V,T> &node);
	void Clear(const RBNode<V,T> &tr);
//	void Delete(const V key, const T value);
//	void Print(RBNode<V, T> *node, int lvl, T value) const;

private:
	RBNode<V,T> *root_;
	size_t  size_;
};

template<class V, class T>
RBTree<V,T> :: RBTree() {
	root_ = NULL;
	size_ = 0;
}

template<class V, class T>
RBTree<V,T> :: RBTree(const RBTree<V,T> &tr) {
	root_ = NULL;
	size_ = 0;
	*this = tr;
}

template<class V, class T>
void RBTree<V,T> :: LRotation(RBTree<V,T> *tr, RBNode<V,T> *xtop) {
        RBNode<V,T> *ytop  = xtop->right_;
        xtop->right_ = ytop->left_;
        if (ytop->left_ != NULL) 
                ytop->left_->parent_ = xtop;
        ytop->parent_ = xtop->parent_;
	if (xtop->parent_ == NULL)
		tr->root_ = ytop;
	else {
        	if (xtop == xtop->parent_->left_)
                	xtop->parent_->left_ = ytop;
        	else
        	        xtop->parent_->right_ = ytop;
	}
       	ytop->left_ = xtop;
        xtop->parent_ = ytop;
}

template<class V, class T>
void RBTree<V,T> :: RRotation(RBTree<V,T> *tr, RBNode<V,T> *xtop) {
        RBNode<V,T> *ytop = xtop->left_;
        xtop->left_ = ytop->right_;
        if (ytop->right_ != NULL)
                ytop->right_->parent_ = xtop;
        ytop->parent_ = xtop->parent_;
	if (xtop->parent_ == NULL)
		tr->root_ = ytop;
	else {
        	if (xtop == xtop->parent_->left_)
                	xtop->parent_->left_ = ytop;
        	else
                	xtop->parent_->right_ = ytop;
	}
        ytop->right_ = xtop;
        xtop->parent_ = ytop;
}

/*
template<class V, class T>
void RBTree<V,T> :: Clear(const RBNode<V,T> &tr) {
	if (tr != NULL) {
		Clear(tr->left_);
		Destruct(tr->right_);
		delete[] tr;
		--size_;
	}
}
*/

template<class V, class T>
RBTree<V,T> *RBTree<V,T> :: Insert(RBTree<V,T> *Tr, RBNode<V,T> *node) {
	RBNode<V,T> *y = NULL;
	node->color_ = Color_Red;
	while (node != Tr->root_ && node->parent_->color_ == Color_Red) {
			if (node->parent_  == node->parent_->parent_->color_) {
				y = node->parent_->parent_->right_;
				if (y->color_ == Color_Red) {
					node->parent_->color_ = Color_Black;
					y->color_ = Color_Black;
					node->parent_->parent_->color_ = Color_Red;
					node = node->parent_->parent_;
				} else {
					if (node == node->parent_->right_) {
						node = node->parent_;
						LRotation(Tr, node);
						node->parent_->color_ = Color_Black;
						node->parent_->parent_->color_ = Color_Red;
						RRotation(Tr, node);
					}
				}
			} else {
				if (node->parent_  == node->parent_->parent_->color_) {
                                	y = node->parent_->parent_->left_;
                                if (y->color_ == Color_Red) {
                                        node->parent_->color_ = Color_Black;
                                        y->color_ = Color_Black;
                                        node->parent_->parent_->color_ = Color_Red;
                                        node = node->parent_->parent_;
                                } else {
                                        if (node == node->parent_->left_) {
                                                node = node->parent_;
                                                RRotation(Tr, node);
                                                node->parent_->color_ = Color_Black;
                                                node->parent_->parent_->color_ = Color_Red;
                                                LRotation(Tr, node);
                                        }
                                }
                        }	
		}
	}
	Tr->root_->color_ = Color_Black;
	return Tr;
}

/*
template<class V, class T>
RBTree<V,T> *RBTree<V,T> :: Fixup_Insert(const RBNode<V,T> &root, const RBNode<V,T> &node) {
	RBNode<V,T> *uncle;
	while (node != root && node->parent_->color_ == Color_Red) {
		if (node->parent_ == node->parent_->parent_->left_) {
			uncle = node->parent_->parent_->right_;
		if (uncle->color_ == Color_Red) {
			node->parent_->color_ = Color_Black;
			uncle->color_ = Color_Black;
			node->parent_->parent_->color_ = Color_Red;
			node = node->parent_->parent_;
		} else {
			if (node == node->parent_->right_) {
				node = node->parent_;
				root = rbtree_left_rotate(root, node);
			}
			node->parent_->color_ = Color_Black;
			node->parent_->parent_->color_ = Color_Red;
			root = RRotate(node->parent_->parent_);
			}
		} else {
			uncle = node->parent_->parent_->left_;
			if (uncle->color_ == Color_Red) {
				node->parent_->color_ = Color_Black;
				uncle->color_ = Color_Black;
				node->parent_->parent_->color_ = Color_Red;
				node = node->parent_->parent_;
			} else {
				if (node == node->parent_->left_) {
					node = node->parent_;
					root = Rrotate(node);
				}
				node->parent_->color_ = Color_Black;
				node->parent_->parent_->color_ = Color_Red;
				root = RRotate(node->parent_->parent_);
			}
		}
	}
	root_->color_ = Color_Black;
	return root_;
}*/


#endif
