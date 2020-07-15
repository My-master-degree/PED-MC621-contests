#include<bits/stdc++.h>

using namespace std;

typedef struct _node {
	int value;
	int indexes[2];
	_node *left, *right;	
} Node;

Node* createSegmentTree(int *a, int i, int j){
	Node *node;
	node = (Node*) malloc(sizeof(Node));	
	node->indexes[0] = i;
	node->indexes[1] = j;
	if (i == j){
		node->value = a[i];
		node->left = node->right = NULL;
	}else{
		int m = (i + j)/2;
		Node *left, *right;
		left = createSegmentTree(a, i, m);
		right = createSegmentTree(a, m + 1, j);
		node->value = left->value + right->value;
		node->left = left;
		node->right = right;
	}
	return node;
}

void printSegmentTree(Node *root){
	printf("From %d to %d: %d\n", root->indexes[0], root->indexes[1], root->value);
	if (root->left != NULL)
		printSegmentTree(root->left);
	if (root->right != NULL)
		printSegmentTree(root->right);
}

Node* findLeftLB(int value, Node *node){
	if (node == NULL)
		return NULL;
	if (node->value <= value)
		return node;
	return findLeftLB(value, node->left);
	
}

int updateSegmentTree(Node *root, int i, int val){
	if (root != NULL){
		int li = root->indexes[0],
			ri = root->indexes[1],
			m = (li + ri)/2,
			aux;
		if (li == i && ri == i)
			root->value = val;
		else if (i > m)
			root->value = root->value - root->right->value + updateSegmentTree(root->right, i, val);	
		else if (i <= m)
			root->value = root->value - root->left->value + updateSegmentTree(root->left, i, val);	

		return root->value;
	}
}

int main(){
	int n;
	scanf("%d", &n);
	if (n >= 1 && n <= 100000){
		long long b[n];
		int a[n];
		int i, _a;
		long long _b;
		for (i = 0; i < n; i ++){
			cin>>_a>>_b;
			a[i] = _a;
			b[i] = _b;
		}
		Node *root;
		root = createSegmentTree(a, 0, n-1);
//		printSegmentTree(root);

		int q;
		scanf("%d", &q);
		if (q >= 1 && q <= 100000){
			int op, c, j;
			int x;
			int patientsWithoutFood, patientsDead;
			list<pair<int, int> > l;
			while (q--){
				cin>>op;
				if (op == 1){
					cin>>x;
					patientsDead = 0;	
					Node *lb;
					lb = findLeftLB(x, root);
					patientsWithoutFood = n - lb->indexes[1] - 1;
					for (int i = lb->indexes[0]; i <= lb->indexes[1]; i++){
						if (a[i] > 0){
							x -= a[i];
							if (x > b[i]){
								patientsDead++;
								updateSegmentTree(root, i, 0);
							}
						}
					}
					l.push_back(pair<int, int> (patientsDead, patientsWithoutFood));
				}else if (op == 2){
					cin>>_a>>_b>>c;
					a[c] = _a;
					b[c] = _b;
					updateSegmentTree(root, c, _a);
				}
			}
			list<pair<int, int> >::iterator it;
			for (it = l.begin(); it != l.end(); ++it)
				cout<<it->first<<" "<<it->second<<endl;
		}
	}
	return 0;
}
