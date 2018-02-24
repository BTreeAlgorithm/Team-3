#define FALSE        1
#define TRUE         0

#define E_NOERR      0
#define E_ARGV       1
#define E_GET_B_TREE 2

struct B_Tree
{
	// point to an array, whose length is depended on the order that
	// is decided by input.
    float * p_key;

    // point to a pointer array. there should be (key_counter + 1)
    // elements in the array.
    struct B_Tree * p_children_tree;

    // to use this variable to judge
    int key_counter;   
};

int ErrNum;  // A globle variable represent all kinds of errors.

int insert(B_Tree * p_tree, float value);
int search(B_Tree * p_tree, float value);