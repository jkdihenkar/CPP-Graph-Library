/* MAIN FUNCTION...... */

#include<iostream>
#include<cstdlib>
#include"graph.h"

void makegraph(graph& g);

using namespace std;

int main()
{

graph g;
int choice;

makegraph(g);

mainmenu:cout << "\n\n\tHello World... Welcome to the Graph Program... :)";
cout << "\n\n\t\t\tMenu : ";
cout << "\n\t\t1. Add a node to graph...";
cout << "\n\t\t2. Display nodes of graph...";
cout << "\n\t\t3. Make Link in Graph...";
cout << "\n\t\t4. Search node in Graph...";

cout << "\n\t\t5. Graph Taversals...";
cout << "\n\t\t6. Single Source Shortest Path...";
cout << "\n\t\t7. Minimum Spanning Trees...";

cout << "\n\t\t10. Exit...";
cout << "\n\n\tEnter your choice : ";

cin >> choice;

cout << "\n\t";

switch(choice)
{
case 1 : { cout << "Add node Option Selected!";
cout << "\n\n";
g.addnode();
goto mainmenu;
}

case 2 : { displaymenu:cout << "Display Graph Option selected!";
cout << "\n";
cout << "\tDisplay Menu : ";
cout << "\n\n\t1. Display nodes only!";
cout << "\n\t2. Display nodes with adjecent list!";
cout << "\n\n\tEnter your choice : ";
cin >> choice;

switch(choice) { 
  case 1 :
  case 2 :
    g.displaynodes(choice);
    goto mainmenu;
  default : { cout << "\n\tThe Entered choice is not recognized...";
  goto displaymenu;
  }
}

g.displaynodes(2);
goto mainmenu;
}

case 3 : { cout << "Make Link in Graph Option Selected!";
cout << "\n\n";
g.createlink();
goto mainmenu;
}

case 4 : { cout << "Search option selected!";
cout << "\n\n";

cout << "Enter the node value to search for : ";

string svalue;

cin >> svalue;

bool found=false;
found=g.searchnode(svalue);

if(found) { 
  cout << "The node Searched for is present in the graph!";
}
else { 
  cout << "The node is not present in Graph!";
}

goto mainmenu;
}

case 5 : { //graph taversal

cout << "\n\n\tEnter the taversal method : ";
cout << "\n\n\t1. BFS Taversal Method...";
cout << "\n\t2. DFS Taversal Method...";

cout << "\n\n\tEnter your choice : ";
cin >> choice;

g.graphtaversal(choice);

g.reset();

goto mainmenu;
}

case 6 : { string svalue;
  cout << "Enter the source node : ";
  cin >> svalue;
  
  node* source;
  source = g.getnode(svalue);
  
  if(source == NULL) { 
    cout << "The Source node is not found! Error!";
    goto mainmenu;
  }
  g.dijkstra(source);
  goto mainmenu;
}

case 10 : { 
  cout << "\n\n";
  cout << "Are you sure you want to EXIT?(y/n) : ";
char m;
cin >> m;

if(m=='y' || m=='Y') { exit(0);
}
else {
goto mainmenu;
}

}

default : { 
  cout << "\n\n";
  cout << "The choice you have entered is not Valid!";
cout << "\nDo enter valid choice... Redisplaying Menu...";
}

}

return 0;

}

void makegraph(graph& g)
{
  g.addnode("A");
  g.addnode("B");
  g.addnode("C");
  g.addnode("D");
  g.addnode("E");
  g.addnode("F");
  g.addnode("G");
  g.addnode("H");
  g.addnode("I");
  
  g.makelink(g.getnode("A"),g.getnode("B"),1,8);
  g.makelink(g.getnode("A"),g.getnode("C"),1,4);
  g.makelink(g.getnode("B"),g.getnode("F"),1,1);
  g.makelink(g.getnode("D"),g.getnode("E"),1,2);
  g.makelink(g.getnode("F"),g.getnode("H"),1,2);
  g.makelink(g.getnode("E"),g.getnode("H"),1,4);
  g.makelink(g.getnode("E"),g.getnode("G"),1,7);
  g.makelink(g.getnode("G"),g.getnode("I"),1,9);
  
  g.makelink(g.getnode("C"),g.getnode("B"),1,11);
  g.makelink(g.getnode("C"),g.getnode("E"),1,8);
  g.makelink(g.getnode("B"),g.getnode("D"),1,7);
  g.makelink(g.getnode("F"),g.getnode("D"),1,6);
  g.makelink(g.getnode("G"),g.getnode("H"),1,4);
  g.makelink(g.getnode("I"),g.getnode("H"),1,10);
  
}
  





