#include<iostream>
#include<cstdlib>

using namespace std;

enum color { white , gray, black } ;

class list;
class alistnode;
class queue;
class graph;
class node;

//node class declaration : ----------------------------------------------------------

//class graph declaration : ------------------------starts-----------------------------------------

class graph { 

node* head;
node* tail;

public : 

graph();  //create empty graph
graph(node* h,node* t);  //create alias to already existing graph

void addnode();  //insert node to the graph : higher level user interaction function
void addnode(string data);  //advanced direct testing function 
void addnode(node* n);  //insert node to graph : lower level function to insert node in vertex list
void displaynodes(int choice=1);  //display function : value | values with adjecent lists
bool searchnode(string data);  //returns true is search value node is present else false
node* getnode(string data);  //search node by data, if present return node address
void createlink();  //User Interaction handling function : higher level function for linking nodes
void makelink(node* n1,node* n2,int type=1,float dist=1);  //lower level linking function to support the create link function!

void graphtaversal(int choice);
//taversal function : user interaction | choice = 1 : BFS | = 2 DFS
void bfstaversal(node* source);
//BFS taversal
void dfstaversal();
//DFS taversal
    void dfs_visit(node* n);
    //lower level function supporting recursion for dfstaversal()
    
void reset();
//reset all node flags to intital values...

void dijkstra(node* n); //single source shortest path
    void initSingleSource(node* n);
    //initalizing all the nodes flag for setting the single source algorithms
    void relax(node* u,node* v,float w);
    //relax function : dijkstra check and set shortest distance
    float weight(node* u,node* v);
    //gives weight of the link b/w these two nodes..
	//if no link returns 999 else the link distance;
    void printDijkstra();
    //prints the nodes their shortest distance and path to the shortest node

private : 
  bool searchnode(node* n);

};

//class graph declaration : -------------------------ends-----------------------------------------



class node { 

string node_data;
color node_color;
float node_distance;
node* node_path;
list* node_adj;



public : 

node* next; //next pointer is public
node* qnext;

node();  //create a node with all default values
node(string data);  //create a node with data set to parameter value and other defaults
node(node* n);

void update(string ndata,color ncolor=white,float ndistance=999,node* npath=NULL,list* nadj=NULL);
//function to update the node values of respective fields
void display(int choice=1); 
//lower level node display function to support display nodes of entire graph
list* adjecent();  //returns the pointer to the adjecent list of the node
string data(); //returns node data
void displaylist();  //lower level function to display the adjecency list of node
void append_node(string ndata="",color ncolor=white,float ndistance=999,node* npath=NULL,list* nadj=NULL,float d=1);
//append a newly created node to the adjecency list
void append_node(node* auxnode,float d=1);
//append an existing node to the adjecency list of the current node

void setcolor(color x);
void setdistance(float a);
void setpath(node* a);
color ncolor();
float distance();
void reset();

friend void graph::printDijkstra();

protected:
  void append(alistnode* auxnode);
  //lower level function supporting the append node function

};

//node class declaration : ------------ends-------------------------------------------------

//queue ---start----

class queue { 
node* front;
node* end;

public:

  //creating the empth queue...
queue();

//basic queue functions...
void enqueue(node* n);
node* dequeue();
bool empty();

//dijkstra supporting functions for shortest path...
node* extract_min();

//remove any arbitaru node of address given
void remove(node* n);

//display queue
void print();

};

//queue ----end-----

//alistnode class declaration : ------------------------------------------------------------


class alistnode { 

node* nodeaddress;
float distance;

public : 
  
alistnode* next;  //next pointer is public
alistnode(node* n,float d=1); //creates an alistnode from the node
alistnode* converttoalist(node* aux,float dist);
//converts and return the alistnode out of a node
node* givenodeaddress();
//returns the node address of the node embedded in the alistnode element
float givedistance();
//gives the distance of the link of the current node
friend void graph::bfstaversal(node* source);
friend void graph::dfs_visit(node* n);
friend node* queue::extract_min();
};

//alistnode class declaration : -----------------------ends------------------------------------



//list class declaration : -----------------------------------------------------------------



class list { 

alistnode* head;
alistnode* tail;

public : 

list();
//empty adjecency list
list(alistnode* head,alistnode* tail);
//creating an alias of an existing adjecency list
alistnode* givehead();
//returns the head of the adjecency list of the node
alistnode* givetail();
//returns the tail of the adjecency list of the node
void setheadtail(alistnode* h,alistnode* t);
//sets the value of head and tail respectively to the values in parameters
void addtolist(alistnode* auxnode);
//adds a adjecencylist element to the end of the list
friend void graph::bfstaversal(node* source);
friend void graph::dfs_visit(node* n);
};

//list class declaration : ------------------------ends--------------------------------------------














