typedef int ElemType;

class AvlNode{
public:
	ElemType data;
	int depth;
	int balance;
	AvlNode left;
	AvlNode right;
	AvlNode parent;
	AvlNode(ElemType d):data(d),left(NULL),right(NULL){
		depth = 1;
		balance = 0;
	}
}