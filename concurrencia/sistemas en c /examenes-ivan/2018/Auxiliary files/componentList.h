#ifndef COMPONENTLIST_H_
#define COMPONENTLIST_H_

struct Component {
  int id; //code to identify a component
  int manufacturer; //code to identify the manufacturer
  int type; //code to identify the type of component: 1 for resistor, 2 for inductor, etc. New codes may be added as needed.
  float price; //price of the component
};

//DEFINE HERE TList AND ANY OTHER TYPE YOU MIGHT NEED

//Initialize the list of components as an empty list (0.5 points, including declaration of TList)
void createList(TList *list);

//Given the list in the first argument, this function returns in the second argument
//a new list with the same elements, but ordered by ascending id code. (3 points)
void new_ordered_list(TList unordered, TList *ordered);

//Inserts the component at the end of the list given as the first parameter, if
//there is no component with the same id code in that list. In the parameter ok, the
//function will return 1 if the insertion was successful, and 0 otherwise. (2 points)
void insert_component(TList *list, struct Component comp, int *ok);

//Adds to the list the contents of the file COMPONENTS.BIN, making sure that no new
//component is inserted if it has the same id as any element already present in the
//list. The return value will be the number of components actually inserted in the
//list. (1 point)
int read_file_to_list (TList *list);

//prints the list on screen (1 point)
void show_list(TList list);

//Adds the component to the file COMPONENTS.BIN. The component will be added to end
//of the file, after any contents the file may previously have. The argument ok will
//be set to 1 if the addition was succesful, or 0 if it could not be added because
//of some I/O error. (1 Point)
void add_to_file (struct Component comp, int *ok);

//Removes from the list all components of the specified manufacturer. If the manufacturer
//is negative, removes all elements. (1.5 points)
void remove_elements(TList *list, int manufacturer);

#endif
