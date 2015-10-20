#ifndef __BinaryTreeB____
#define __BinaryTreeB____

#include "Node.h"
#include <iostream>

using namespace std;

template <class T, int V>
class BinaryTreeB {
    
    
public:
    
    Node<T, V>* root;
    
	BinaryTreeB();

    void check();
    void traverse(Node<T, V>* current);
	void insert(const T &newInfo);
	void insertR(Node<T, V>* current, const T &newInfo, T &central, Node<T, V>* &linkToRight, bool &result);
	void insertInfo(Node<T, V>* current, const T &entry, Node<T, V> *linkToRight, int position);
    
    /* recursiveFiller(Node<T, V>* current, int position);*/
    
	void remove(const T &goTo);
	void removeR(Node<T, V> *current, const T &goTo);
	void removeInfo(Node<T, V> *current, int position);
    
	void copyInfo(Node<T, V> *current, int position );
    
    void shiftLeft(Node<T, V> *current , int position );
    void shiftRight(Node<T, V> *current , int position );
    
	void fixInsert(Node<T, V> *current ,int position  );
    
    void splitNode( Node<T, V>* current,  const T &entryAux,   Node<T, V> *offspringAux,  int position, Node<T, V>* &secondHalf,   T &central);
	void mergeNode(Node<T, V> *current, int position );
	
    bool searchInfo(Node<T, V> *current, const T &goTo, int &position );
    bool found(T &infoNode);
    bool search(Node<T, V>* current, T &goTo);
    
    void inOrder();

    void printTree();
	void print( Node<T, V> *current );
    
};

template <class T, int V>
BinaryTreeB<T, V>::BinaryTreeB(){
	root = nullptr;
}


template <class T, int V>
void BinaryTreeB<T, V>::traverse(Node<T, V> * current){
    
	if (current != nullptr ){
		traverse(current->link[0]);
        
		for (int i = 0; i < current->count; i++){
            
            std::cout << current->infoArray[i] << " ";
			traverse(current->link[i + 1]);
            
		}
	}
}


template <class T, int V>
void BinaryTreeB<T, V>::insert(const T &newInfo){
    
	T central;
    
	Node<T, V> *linkToRight, *rootAux;
	bool  result ;
    
	insertR(root, newInfo, central, linkToRight , result);
    
	if(result) {
        
		rootAux = new Node<T, V>;
		rootAux->count = 1;
		rootAux->infoArray[0] = central;
		rootAux->link[0] = root;
		rootAux->link[1] = linkToRight;
		root = rootAux;
        
	}
}

template <class T, int V>
void BinaryTreeB<T, V>::insertR(Node<T, V> *current, const T &newInfo,T &central, Node<T, V> * &linkToRight , bool &result){
    
    int position;
    if (current == nullptr) {
        
        central = newInfo;
        linkToRight = nullptr;
        result = true;
        
    }
    else {
        bool validate =  searchInfo(current, newInfo, position);
        if (!validate){
            
            T entryAux;
            Node<T, V> *offspringAux;
            
            insertR(current->link[position], newInfo, entryAux, offspringAux , result);
            if ( result ) {
                if ( !current->isFull() ) {
                    
                    result = false;
                    insertInfo(current, entryAux, offspringAux, position);
                }
                else{
                    splitNode( current, entryAux, offspringAux, position, linkToRight, central);
                }
            }

        }
        else {
            
            result = false;
            return;
            
        }
    }
}

template <class T, int V>
void BinaryTreeB<T, V>::insertInfo(Node<T, V> *current, const T &entry, Node<T, V> *linkToRight, int position){
    
    int i = 0;
    
    for(i=current->count-1;i>= position;i--){
        
        current->infoArray[i+1]=current->infoArray[i];
        current->link[i+2]=current->link[i+1];
    }
    
    current->infoArray[position]= entry;
    current->link[i+2]=linkToRight ;
    current->count++;
    
}

/*
template <class T, int V>
void BinaryTreeB<T, V>::recursiveFiller(Node<T, V>* current, int position){
    
   for(int i = 0; i < this->count; i++){
        if(search(current){
            recursiveFiller(current);
        }
   }
}
 
*/

template <class T, int V>
void BinaryTreeB<T, V>::remove( const T &goTo ){
    
	removeR(root , goTo);
    
	if( root != nullptr && root->count == 0 ){
        
		Node<T, V> *rootRemoval = root;
		root = root->link[0];
		delete rootRemoval;
        
	}
}

template <class T, int V>
void BinaryTreeB<T,V>::removeR( Node<T, V> *current, const T &goTo ){
    
	int position;
	if ( !(current == nullptr) ){
        
        bool validate =  searchInfo(current, goTo, position);
        if (validate){
            
            if (current->link[position] != nullptr){
                
                copyInfo(current , position);
                removeR(current->link[position], current->infoArray[position]);
            }else{
                removeInfo( current , position);
            }
            
        }else{
            removeR(current->link[position], goTo);
        }
        
        if(current->link[position] != nullptr){
            if( current->link[position]->isEmpty()){
                fixInsert(current, position);
            }
        }

	}
	else{
        std::cout << "Elemento no encontrado" << std::endl;
        return;
    }
}

template <class T, int V>
void BinaryTreeB<T,V>::removeInfo(Node<T, V> *current, int position){
    
    for(int i = position; i < current->count-1; i++){
		current->infoArray[i] = current->infoArray[i+1];
    }
	current->count--;
}

template <class T, int V>
void BinaryTreeB<T,V>::copyInfo(Node<T, V> *current, int position){
    
	Node<T, V> * leaf = current->link[position];
    
    while( leaf->link[leaf->count] != nullptr ){
		leaf = leaf->link[leaf->count];
    }
	current->infoArray[position] = leaf->infoArray[leaf->count-1];
}

template <class T, int V>
void BinaryTreeB<T,V>::shiftLeft(Node<T, V> *current, int position){
    
    Node<T, V> *linkToLeft = current->link[position-1],
    
    *linkToRight = current->link[position];
    
    linkToLeft->infoArray[linkToLeft->count] = current->infoArray[position-1];
    
    linkToLeft->link[++linkToLeft->count] = linkToRight->link[0];
    current->infoArray[position-1] = linkToRight->infoArray[0];
    
    linkToRight->count--;
    for(int i = 0;i < linkToRight->count; i++ ){
        
        linkToRight->infoArray[i] = linkToRight->infoArray[i+1];
        linkToRight->link[i] = linkToRight->link[i+1];
    }
    linkToRight->link[linkToRight->count] = linkToRight->link[linkToRight->count +1];
    
}

template <class T, int V>
void BinaryTreeB<T,V>::shiftRight(Node<T, V> *current, int position){
    
    Node<T, V>*linkToRight = current->link[position+1],
    *linkToLeft = current->link[position];
    
    linkToRight->link[linkToRight->count+1] = linkToRight->link[linkToRight->count];
    
    for( int i = linkToRight->count; i > 0; --i ){
        
        linkToRight->infoArray[i] = linkToRight->infoArray[i-1];
        linkToRight->link[i] = linkToRight->link[i-1];
    }
    
    linkToRight->count++;
    linkToRight->infoArray[0] = current->infoArray[position];
    
    linkToRight->link[0] = linkToLeft->link[linkToLeft->count--];
    current->infoArray[position] = linkToLeft->infoArray[linkToLeft->count];
}


template <class T, int V>
void BinaryTreeB<T,V>::fixInsert(Node<T, V> *current, int position){
    
    if( position == current->count ){
        
        if( current->link[position-1]->count > (V-1)/2 ){
            
			shiftRight(current, position-1);
            
        }else{
            
			mergeNode(current, position );
        }
    }else if( position == 0 ){
            if(current->link[1]->count > (V-1)/2){
                
                shiftLeft(current, 1 );
                
            }else{
                mergeNode(current, 1 );
            }
    }else{
            if(current->link[position-1]->count > (V-1)/2 ){
                shiftRight(current, position-1 );
                
            }
            else if(current->link[position+1]->count > (V-1)/2 ){
                shiftLeft(current, position+1 );
                
            }
            else{
                mergeNode(current, position);
            }
    }
}

template <class T, int V>
void BinaryTreeB<T,V>::splitNode(Node<T, V>* current,  const T &entryAux,   Node<T, V>* offspringAux, int position, Node<T, V>* &secondHalf,   T &central){
    
    secondHalf = new Node<T,V>;
    
    int center = V/2;
    
    if( position <= center ){
        for(int i = center;i < V-1;i++ ){
            
            secondHalf->infoArray[i-center] = current->infoArray[i];
            secondHalf->link[i+1-center] = current->link[i+1];
            
        }
        
        current->count = center;
        secondHalf->count = V-1-center;
        insertInfo( current , entryAux , offspringAux , position );
        
    } else {
        
        center = center+1;
        
        for(int i = center;i < V-1;i++ ){
            
            secondHalf->infoArray[i-center] = current->infoArray[i];
            secondHalf->link[i+1-center] = current->link[i+1];
            
        }
        
        current->count = center;
        secondHalf->count = V-1-center;
        insertInfo(secondHalf , entryAux , offspringAux , position-center);
        
    }
    
    central = current->infoArray[current->count-1];
    secondHalf->link[0] = current->link[current->count];
    
    current->count--;
}

template <class T, int V>
void BinaryTreeB<T,V>::mergeNode(Node<T, V> *current, int position){
    
	int i;
	Node<T, V> *linkToLeft = current->link[position-1],
    
    *linkToRight = current->link[position];
    
	linkToLeft->infoArray[linkToLeft->count] = current->infoArray[position-1];
	linkToLeft->link[++linkToLeft->count] = linkToRight->link[0];
    
	for( i =0;i < linkToRight->count;i++){
        
		linkToLeft->infoArray[linkToLeft->count] = linkToRight->infoArray[i];
		linkToLeft->link[++linkToLeft->count] = linkToRight->link[i+1];
	}
	current->count--;
    
	for( i=position-1; i < current->count; i++ ){
        
		current->infoArray[i] = current->infoArray[i+1];
		current->link[i+1] = current->link[i+2];
	}
    
	delete linkToRight;
}

template <class T, int V>
bool BinaryTreeB<T,V>:: searchInfo( Node<T, V> *current, const T &goTo, int &position ){
    
    position=0;
    
    while (position < current->count && goTo > current->infoArray[position])
        position++;
    
    if (position < current->count && goTo == current->infoArray[position]){
        
        return 1;
        
    }else{
        
        return 0;
    }
}

template <class T, int V>
bool BinaryTreeB<T,V>::found( T &infoNode ){
    
    return search(root , infoNode);
    
}

template <class T, int V> bool BinaryTreeB<T,V>::search( Node<T, V> *current, T &goTo ){
    
    bool result = false;
    int position;
    if (current != nullptr){
        
        result =  searchInfo(current, goTo, position);
        if (result == true){
            
            goTo = current->infoArray[position]->getData();
        }else{
            
            result = search(current->link[position], goTo);
        }
    }
    return result;
}

template <class T, int V> void BinaryTreeB<T,V>::inOrder(){
    
    return traverse( root );
    
}

template <class T, int V>
void BinaryTreeB<T,V>::printTree(){
	
    if ( !(root == nullptr) ){
        print(root);
    }
	else{
        std::cout << "No information" << std::endl;
	}
}

template <class T, int V>
void BinaryTreeB<T,V>::print( Node<T, V> *current ){
    
    if(!current)
    {
        return;
    }else{
    
        for(int i=0; i<= current->count ;i++){
        print( current->link[i] );
    }
    }
}



#endif
