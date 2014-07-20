//functions only

#include<iostream>
#include<cstdlib>
#include"graph.h"

using namespace std;

//node class function definations

//default constructor
node::node() { node_data="";
node_color = white;
node_distance = 999;
node_path = NULL;
node_adj = NULL;
next=NULL;
}

//parameterized constructor
node::node(string data) {
this->node_data = data;
node_color = white;
node_distance = 999;
node_path = NULL;
node_adj = NULL;
next=NULL;
}

node::node(node* n)
{
node_data=n->node_data;
node_color=n->node_color;
node_distance=n->node_distance;
node_path=n->node_path;
node_adj=n->node_adj;
}

//update function to update the values of node
void node::update(string ndata,color ncolor,float ndistance,node* npath,list* nadj)
{ node_data = ndata;
node_color = ncolor;
node_distance = ndistance;
node_path = npath;
node_adj = nadj;
}

void node::display(int choice)
{
  if(choice==0) //only name
  {
    cout << node_data;
    return;
  }
  if(choice==1 || choice==2) //formal illustrated printing 
  {
  cout << "Node : Data : " << node_data << "\n";
  if(choice==2) { displaylist();
    }
  }
}

void node::displaylist()
{
  alistnode* temp;
  cout << "\tAdjecents : ";
  if(node_adj==NULL)
  {
    cout << "NULL\n";
    return;
  }
  temp = node_adj->givehead();
  while(temp!=NULL)
  {
    cout << "\t";
    (temp->givenodeaddress())->display(0);
    cout << "(" << temp->givedistance() << ")" ;
    temp=temp->next;
  }cout << "\n";
  return;
}

//appending the node to the list

//create and append : advanced functionality
void node::append_node(string ndata,color ncolor,float ndistance,node* npath,list* nadj,float d)
{
node* aux = new node(ndata);
aux->update(ndata,ncolor,ndistance,npath,nadj);
append_node(aux,d);
return;
}

//directly append
void node::append_node(node* auxnode,float dist)
{
alistnode* temp;
temp = new alistnode(auxnode,dist);
append(temp);
}

//the sub-level function to append a node to the list!
	//simple list function to insert node to the end of the list
void node::append(alistnode* auxnode)
{
alistnode* temp;

if(node_adj == NULL)
{
  node_adj = new list;
  goto ins;
}

temp=node_adj->givehead();

while(temp!=NULL)
{
if(temp->givenodeaddress() == auxnode->givenodeaddress())
{
return;
}
temp=temp->next;
}
ins:node_adj->addtolist(auxnode);
return;
}

list* node::adjecent() { 
  return node_adj;
}

string node::data() { 
  return node_data;
}


void node::setcolor(color x)
{
node_color = x;
}

void node::setdistance(float a)
{
node_distance = a;
}

void node::setpath(node* a)
{
node_path = a;
}

color node::ncolor() {
return node_color;
}

float node::distance() { 
return node_distance;
}

void node::reset() { 
node_color = white;
node_distance = 0;
node_path = NULL;
}



/* -----------------------------------------------------------------------------------------  */

//default constructor
alistnode::alistnode(node* n,float d) { 
nodeaddress = n;
distance = d;
next=NULL;
}

//convert a node to adjecencylist node
alistnode* converttoalist(node* aux,float dist) { 
alistnode *temp;
temp = new alistnode(aux,dist);
return temp;
}

node* alistnode::givenodeaddress() { 
return nodeaddress;
}

float alistnode::givedistance() {
  return distance;
}

/* -----------------------------------------------------------------------------------------*/


//list class function defination

//default constructor
list::list() { 
head = NULL;
tail = NULL;
}

//parameterized constructor
list::list(alistnode* head,alistnode* tail) { 
this->head = head;
this->tail = tail;
}

alistnode* list::givehead() { 
  return head;
}

alistnode* list::givetail() { 
  return tail;
}

void list::setheadtail(alistnode* h,alistnode* t)
{
  head=h;
  tail=t;
}

void list::addtolist(alistnode* aux)
{
if(head == NULL)
{
head=aux;
tail=aux;
return;
}
tail->next =aux;
tail=aux;
return;
}


/*-------------------------------------------------------------------------------------------------*/

//class graph defination : main functionalities here...

//default constructor!
graph::graph() { 
head = NULL;
tail = NULL;
}

//parameterized constructor to copy alias of the graph into another
graph::graph(node* h,node* t) { 
head = h;
tail = t;
}

//add node to the graph with prompt about node values...
void graph::addnode()
{
node *temp;
string data;
cout << "Enter the node data : ";
cin >> data;
temp = new node(data);
addnode(temp);
}

void graph::addnode(string data)
{
  node *temp;
  temp = new node(data);
  addnode(temp);
}



//direclty add the node to the graph that is specified by the address
void graph::addnode(node* n)
{
if(head == NULL)
{
head = n;
tail = n;
return;
}
tail->next = n;
tail=n;
}

void graph::displaynodes(int choice)
{
  node* temp;
  if(head == NULL)
  {
    cout << "\nEmpty Graph! No nodes to display!";
    return;
  }
  temp = head;
  while(temp!=NULL)
  {
    temp->display(choice);
    temp=temp->next;
  }
  return;
}

bool graph::searchnode(string data)
{
  if(head==NULL) {
    return false;
  }
  node* temp;
  temp=head;
  
  while(temp!=NULL)
  {
    if(temp->data() == data)
    {
      return true;
    }temp=temp->next;
  }
  return false;
}

bool graph::searchnode(node* n)
{
  if(head==NULL) {
    return false;
  }
  node* temp;
  temp=head;
  
  while(temp!=NULL)
  {
    if(temp == n)
    {
      return true;
    }temp=temp->next;
  }
  return false;
}

node* graph::getnode(string data)
{
  if(head==NULL) {
    return NULL;
  }
  node* temp;
  temp=head;
  
  while(temp!=NULL)
  {
    if(temp->data() == data)
    {
      return temp;
    }temp=temp->next;
  }
  return NULL;  
}


void graph::createlink()
{
  cout << "Welcome to the Node Linking Module!";
  cout << "\n\n" << "Enter the node values to link : ";
  cout << "\n\t" << "Enter first (from) node value : ";
  string sval1,sval2;
  
  cin >> sval1;
  
  cout << "\n\tEnter the second (to) node value : ";
  
  cin >> sval2;
  
  node *n1,*n2;
  
  n1=getnode(sval1);
  n2=getnode(sval2);
  
  if(n1==NULL || n2==NULL)
  {
    cout << "Sorry the nodes for linking are not present in graph!";
    return;
  }
  
  cout << "Both the nodes for linking are found! ";
  
  typemenu:cout << "\n\nWhat Type of Link to Create? ";
  cout << "\n\n\t1. Un-Directed Link\n\t2. Directed Link";
  cout << "Enter your choice : ";
  int choice;
  
  cin >> choice;
  
  switch(choice)
  {
    case 1 : 
    case 2 :
      cout << "Enter the Distance between the nodes : ";
      float dis;
      cin >> dis;
      
      makelink(n1,n2,choice,dis);
      
      break;
    default : 
      cout << "Error the choice entered is invalid! Try Again...";
      goto typemenu;
  }
  return;
}


void graph::makelink(node* n1,node* n2,int type,float dist)
{
  //type=1 : undirected
  //type=2 : directed
  
  n1->append_node(n2,dist); //directed done
  if(type==1) { 
    n2->append_node(n1,dist);
  }
  
  return;
}


void graph::graphtaversal(int choice)
{
//taversal function : user interaction | choice = 1 : BFS | = 2 DFS
string sval;

cout << "Enter data of the source node : ";
cin >> sval;

node* source = getnode(sval);

if(source==NULL) { 
cout << "The source is not found! Error!";
return;
}

if(choice == 1)
{
bfstaversal(source);
return;
}

if(choice == 2)
{
dfstaversal();
return;
}

cout << "Error! Wrong Choice! Returning to Main Menu...";
return;
}



void graph::bfstaversal(node* source)
{
//BFS taversal

cout << "The BFS Taversal of the graph is as follows : \n\n";

//step 1 : initialize 
  //for each node in V[G] do color = white , distance = 0, path = null
  
  //----it's already set in the graph initalization
  
  node *u;
  queue Q;
  
  //step 2 : u=s
  u=source;
  
  u->setcolor(gray);
  u->setdistance(0);
  u->setpath(NULL);
  
  Q.enqueue(source);
  source->display();
  
  while(!Q.empty())
  {
    u=Q.dequeue();
    node* v;
    
    //for each v in adjecent of u...
      
      //get the list pointer
    list* temp;
    if(u->adjecent()==NULL) { 
    continue;
    }
    temp=u->adjecent();
    
    alistnode* t=temp->head;
    
    while(t!=NULL)
    {
      v=(t->nodeaddress);
      if(v->ncolor() == white)
      {
        v->setcolor(gray);
        v->setdistance(u->distance() + 1);
        v->setpath(u);
        Q.enqueue(v);
        v->display();
      }
    t=t->next;    
    }
    u->setcolor(black);
    }
}


void graph::dfstaversal()
{
//DFS taversal

node* u;

u=head;

while(u!=NULL)
{
dfs_visit(u);
u=u->next;
}
return;

}

void graph::dfs_visit(node* u)
{
  if(u->ncolor() == white) { 
    u->display(); 
  }
  u->setcolor(gray);
  node* v;
  
  if((u->adjecent())==NULL)
  {
    return;
  }
  
  alistnode* t = (u->adjecent())->head;
  
  while(t!=NULL)
  {
    
    v=(t->nodeaddress);
    
    if(v->ncolor() == white)
    {
      v->setpath(u);
      dfs_visit(v);  
    }
   t=t->next;
  }
    u->setcolor(black);
}

void graph::reset()
{
node* temp;
if(head==NULL)
{
return;
}
temp=head;
while(temp!=NULL)
{
temp->reset();

temp=temp->next;
}

}

void graph::dijkstra(node* n)
{
  initSingleSource(n);
  
  node* u;

  //trying by array
  
  node* a[99];
  node* b[99];
  int index=0;
  float dists[99];
  
  for(u=head;u!=NULL;u=u->next)
      {
	if(u->adjecent() == NULL)
	{
	  continue;
	}
	alistnode* temp = (u->adjecent())->givehead();
	  for(;temp!=NULL;temp=temp->next)
	  {
	    node* v;
	    v=temp->givenodeaddress();
	    a[index] = u;
	    b[index] = v;
	    dists[index] = temp->givedistance();
	    index++;
	  }
	  u->setcolor(gray);
      }
      
      int x;
      for(x=0;x<index;x++)
      {
	relax(a[x],b[x],weight(a[x],b[x]));
      }
      for(x=index-1;x>=0;x--)
      {
	relax(a[x],b[x],weight(a[x],b[x]));
      }
  end:printDijkstra();
  reset();
}

void graph::initSingleSource(node* n)
{
  node* u;
  
  u=head;
  
  while(u!=NULL)
  {
    u->setdistance(999);
    u->setpath(NULL);
    u->qnext=NULL;
    u=u->next;
  }
  
  n->setdistance(0);
}

void graph::relax(node* u,node* v,float weight)
{
  if(v->distance() > u->distance() + weight )
  {
    v->setdistance(u->distance() + weight);
    v->setpath(u);
  }
}

float graph::weight(node* u,node* v)
{    
    if(u->adjecent() == NULL)
    {
      return 999;
    }
    
    alistnode* t = (u->adjecent())->givehead();
    
    while(t!=NULL)
    {
      if(t->givenodeaddress() == v)
      {
	return t->givedistance();
      }
      t=t->next;
    }
    return 999;
}

void graph::printDijkstra()
{
  node* u;
  
  u=head;
  
  while(u!=NULL)
  {
    u->setcolor(white);
    u=u->next;
  }
  
  u=head;
  
  while(u!=NULL)
  {
    cout << "\nNode : " << u->node_data << " Shortest distance : " << u->node_distance;
    cout << "\tPath : ";
    node* t;
    t=u->node_path;
    while(t!=NULL)
    {
	cout << t->node_data << " <- " ;
      t=t->node_path;
    }
    cout << "source";
    u=u->next;
  }
  
}


//class queue function definations-------------------------------------------------------------

queue::queue() { 
front=NULL;
end=NULL;
}


void queue::enqueue(node* n) { 
//insert at end of queue

if(front==NULL)
{
front=n;
end=n;
return;
}
end->qnext=n;
end=n;
}

node* queue::dequeue() { 

if(front==NULL)
{
return NULL;
}
node* temp;
temp=front;
front=front->qnext;

return temp;
}

bool queue::empty()
{
if(front==NULL)
{
return true;
}
return false;
}

node* queue::extract_min()
{
  node* u;
  float shortestdistance=999;
  node* selnode = NULL;
  
  for(u=front;u!=NULL;u=u->qnext)
  {
    if(u->adjecent() == NULL)
    {
      continue;
    }
    alistnode* t = (u->adjecent())->givehead();
    
    for(;t!=NULL;t=t->next)
    {
      if(shortestdistance > t->givedistance() )
      {
	shortestdistance = t->givedistance();
	selnode = t->givenodeaddress();
      }
    }
  }
  return selnode;
}

void queue::remove(node* n)
{
  node* temp=NULL;
  node* prev=NULL;
  node* current=front;
  node* nextnode;
  
  if(n == front)
  {
    //remove first node from queue
    front=front->qnext;
    return;
  }
  
  prev=front;
  current=front->qnext;
  nextnode=current->qnext;
  
  while(current != NULL)
  {
     if(current == n)
    {
      prev->qnext = nextnode;
      return;
    }
    prev=current;
    current=nextnode;
    nextnode=nextnode->qnext;
  }
}

void queue::print()
{
  cout << "\n\nQueue : ";
  node* u;
  
  for(u=front;u!=NULL;u=u->qnext)
  {
    u->display();
    cout << "\t";
  }
}
      
    
/* garbage code for dijkstra!
  {
  //trying to create array!
  
  while(!Q.empty())
  {
    u=Q.extract_min();
    
    cout << "U is : ";
    
    u->display();
    
    if(u == NULL) { 
      goto end;
    }
    Q.remove(getnode(u->data()));
    Q.print();
    
    if(u->adjecent() == NULL)
    {
    continue;
    }
    node* v;
    alistnode* t = (u->adjecent())->givehead();
    while(t!=NULL)
    {
      v=t->givenodeaddress();
        relax(u,v,weight(u,v));      
      t=t->next;
    }
  }*/    
























