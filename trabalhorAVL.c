
// Definição da estrutura do nó da árvore AVL
struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};
// Função auxiliar para obter o máximo entre dois números
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Função para obter a altura de um nó
int getHeight(struct Node* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

// Função para criar um novo nó na árvore AVL
struct Node* createNode(int key) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

// Função para realizar uma rotação simples à direita
struct Node* rotateRight(struct Node* node) {
    struct Node* leftChild = node->left;
    struct Node* rightGrandchild = leftChild->right;
    
    // Realiza a rotação
    leftChild->right = node;
    node->left = rightGrandchild;
    
    // Atualiza as alturas dos nós afetados
    updateHeight(node);
    updateHeight(leftChild);
    
    // Retorna o novo nó raiz
    return leftChild;
}

// Função para realizar uma rotação simples à esquerda
struct Node* rotateLeft(struct Node* node) {
    struct Node* rightChild = node->right;
    struct Node* leftGrandchild = rightChild->left;
    
    // Realiza a rotação
    rightChild->left = node;
    node->right = leftGrandchild;
    
    // Atualiza as alturas dos nós afetados
    updateHeight(node);
    updateHeight(rightChild);
    
    // Retorna o novo nó raiz
    return rightChild;
}

// Função para inserir um nó em uma árvore AVL
struct Node* insertNode(struct Node* node, int key) {
    // Realiza a inserção normal de uma árvore binária de busca
    if (node == NULL)
        return createNode(key);
    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node; // Duplicatas não são permitidas em uma árvore de busca
    
    // Atualiza a altura do nó atual
    updateHeight(node);
    
    // Verifica o fator de balanceamento e realiza as rotações necessárias
    int balanceFactor = getBalanceFactor(node);
    if (balanceFactor > 1) {
        if (key < node->left->key)
            return rotateRight(node);
        else {
            node->left = rotateLeft(node->left);
        return rotateRight(node);

// Função para remover um nó em uma árvore AVL
struct Node* removeNode(struct Node* root, int key) {
    if (root == NULL)
        return root;
    
    // Realiza a remoção normal de uma árvore binária de busca
    if (key < root->key)
        root->left = removeNode(root->left, key);
    else if (key > root->key)
        root->right = removeNode(root->right, key);
    else {
        // Nó a ser removido encontrado
        
        // Caso 1: Nó folha ou com apenas um filho
        if (root->left == NULL || root->right == NULL) {
            struct Node* temp = root->
            
// Função para balancear a árvore AVL após a remoção de um nó
struct Node *balanceTree(struct Node *node) {
    updateHeight(node);
    int balanceFactor = getBalanceFactor(node);

    // Caso de desbalanceamento à esquerda-esquerda
    if (balanceFactor > 1 && getBalanceFactor(node->left) >= 0)
        return rightRotate(node);

    // Caso de desbalanceamento à esquerda-direita
    if (balanceFactor > 1 && getBalanceFactor(node->left) < 0) {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Caso de desbalanceamento à direita-direita
    if (balanceFactor < -1 && getBalanceFactor(node->right) <= 0)
        return leftRotate(node);

    // Caso de desbalanceamento à direita-esquerda
    if (balanceFactor < -1 && getBalanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}            
     