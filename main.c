#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_s *NODE;
typedef struct NODE_s{
    NODE right;
    NODE left;
    int key;
    void *data;
    int height;
} NODE_t[1];

typedef struct{
    NODE root;
} AVL_t[1], *AVL;

AVL avl_init(){
    AVL t = (AVL)malloc(sizeof(AVL_t));
    t->root = NULL;
    return t;
}
NODE init_node(int key, void *data){
    NODE node = (NODE)malloc(sizeof(NODE_t));
    node->left = NULL;
    node->right = NULL;
    node->key = key;
    node->data = data;
    node->height = NULL;
    return node;
}

/*void dsw_right_rot(AVL t){
    NODE grandParent = (NODE)t;
    NODE parent = t->root;

    while(parent != NULL){
        NODE child = parent->left;
        if(child != NULL){
            parent->left = child->right;
            child->right = parent;
            grandParent->right = child;
            parent = child;
        }
        else{
            grandParent = parent;
            parent = parent->right;

        };

    }

}

int amount_of_backbone(AVL backbone_t){
    int count = 0;
    if(backbone_t != NULL && backbone_t->root != NULL){
        NODE child = backbone_t->root;
        while(child != NULL){
            child = child->right;
            count++;
        }
    }
    return count;
}

void left_rotation(AVL backbone_t,int n){
    NODE grandParent = (NODE)backbone_t;
    NODE parent = backbone_t->root;
    int copy_of_n = n;
    while(n != 0){
        NODE child = parent->right;
        if(child != NULL && n == copy_of_n){
            parent->right = child->left;
            child->left = parent;
            grandParent->right = child;
            parent = child;
            parent = parent;
            n--;
        }
        else{
            grandParent = parent;
            parent = parent->right;
            copy_of_n--;
        };
    }
}*/

void left_rotation(NODE parent){}
void right_rotation(NODE parent){}
int max(int num1, int num2)
{
    return (num1 > num2 ) ? num1 : num2;
}
int get_height(NODE node){
    if(node == NULL || node->height == NULL){
        return 0;
    }else{
        return node->height;
    }
}
NODE avl_insert_rec(NODE node, int key, void *data){
    if(node == NULL){
        node = init_node(key, data);

    }
    else{
        if(key < node->key){
            node->left = avl_insert_rec(node->left, key, data);
        }
        else if(key > node->key){
            node->right = avl_insert_rec(node->right, key, data);
        }
        else{
            printf("Duplicate key: %d. Ignoring...\n\n\n", key);
        }
    }

    //TODO: Update the height of current node;
    //TODO: node->height = max(node->left->height,node->right->height) + 1;
    node->height = max(get_height(node->left), get_height(node->right)+1);

    //TODO: Compute Balance Factor
    //TODO: bf = node->left->height - node->right->height

    int bf = get_height(node->left) - get_height(node->right); //Balance Factor


    if(bf < -1){
        if(get_height(node->right->left) < get_height(node->right->right)) {
            //TODO:Right Right Problem
        }else{
            //TODO:Right Left Problem
        }
    } else if(bf > 1){
        if(get_height(node->left->right) < get_height(node->left->left)) {
            //TODO:Left Left Problem
        }else{
            //TODO:Left Right Problem
        }
    }

    //TODO: CAUTION!!! node->left or node->right might be NULL;
    return node;
}

void avl_insert(AVL t, int key, void *data){
    if(t == NULL){
        printf("ERROR. Uninitialized tree\n");
    }
    else{
        if(t->root == NULL){
            t->root = init_node(key, data);
        }
        else{
            t->root = avl_insert_rec(t->root, key, data);
        }
    }
}


void tree_print(NODE node, int l){
    int i;
    if(node != NULL){
        tree_print(node->right, l+1);
        for (i = 0; i < l; ++i) {
            printf("        ");
        }
        printf("%d\n", node->key);
        tree_print(node->left, l+1);
    }
}


int main() {
    printf("Hello, World!\n");

    AVL t1 = avl_init();
    avl_insert(t1, 40, NULL);
    avl_insert(t1, 60, NULL);
    avl_insert(t1, 32, NULL);
    avl_insert(t1, 65, NULL);
    avl_insert(t1, 43, NULL);
    avl_insert(t1, 78, NULL);


    tree_print(t1->root,0);
    return 0;
}
