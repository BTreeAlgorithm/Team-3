// function return value
#define FALSE        1
#define TRUE         0

// Error Code
#define E_NOERR      0
#define E_ARGV       1
#define E_GET_B_TREE 2

int ErrNum;  // A globle variable represent all kinds of errors.

struct B_Tree
{
    // point to an array, whose length is depended on the order that
    // is decided by input.
    int * p_key;

    // point to a pointer array. there should be (key_counter + 1)
    // elements in the array.
    struct B_Tree * p_children_tree;

    // to use this variable to judge if it is necessary to seperate.
    int key_counter;   
};

int insert(B_Tree * p_tree, int value);
int search(B_Tree * p_tree, int value);
int delete(B_Tree * p_tree, int value);