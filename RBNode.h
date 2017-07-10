#ifndef _RBNODE_H_
#define _RBNODE_H_

#define Color_Red 1
#define Color_Black 0

#include <iostream>

template<class V, class T>
class RBNode {
public:
	RBNode();
	RBNode(const V &k, const T &val);
	void LRotation(const RBNode<V,T> &xtop);
	void RRotation(const RBNode<V,T> &xtop);
//	RBNode<V,T> *FindMin();
	V key_;
	T color_; 
	T val_;
	RBNode *left_; 
	RBNode *right_; 
	RBNode *parent_;
};

template<class V, class T>
RBNode<V,T> :: RBNode() {
	color_ = Color_Black;
	left_ = NULL;
	right_ = NULL;
	parent_ = NULL;
}

template<class V, class T>
RBNode<V,T> :: RBNode(const V &k, const T &val) {
	key_ = k;
	val_ = val;
	left_ = NULL;
	right_ = NULL;
	parent_ = NULL;
	color_ = Color_Black;
}

template<class V, class T>
void RBNode<V,T> :: LRotation(const RBNode<V,T> &xtop) {
	RBNode<V,T> *ytop  = xtop->right_;
	xtop->right_ = ytop->left_;
	if (ytop->left_ != NULL) 
		ytop->left_->parent_ = xtop;
	ytop->parent_ = xtop->parent_;
	if (xtop == xtop->parent_->left_)
		xtop->parent_->left_ = ytop;
	else
		xtop->parent_->right_ = ytop;
	ytop->left_ = xtop;
	xtop->parent_ = ytop;
}

template<class V, class T>
void RBNode<V,T> :: RRotation(const RBNode<V,T> &xtop) {
	RBNode<V,T> *ytop = xtop->left_;
	xtop->left_ = ytop->right_;
	if (ytop->right_ != NULL) 
		ytop->right_->parent_ = xtop;
	ytop->parent_ = xtop->parent_;
	if (xtop == xtop->parent_->left_)
                xtop->parent_->left_ = ytop;
        else
                xtop->parent_->right_ = ytop;
        ytop->right_ = xtop;
        xtop->parent_ = ytop;
}

#endif
