#include "arraylist.h"

int main() {
    list *plist;
    list_node node;

    plist = create_list(5);

    if (plist){
        node.data = 100;
        add_element(plist, 0, node);
        node.data = 200;
        add_element(plist, 1, node);
        node.data = 300;
        add_element(plist, 2, node);
        node.data = 50;
        add_element(plist, 0, node);
        node.data = 25;
        add_element(plist, 0, node);
        node.data = 5;
        add_element(plist, 0, node); //Error

        display_list(plist);

        remove_element(plist, 2);
        display_list(plist);

        remove_element(plist, 0);
        display_list(plist);

        remove_element(plist, 2);
        display_list(plist);

        clear_list(plist);

        display_list(plist);

        delete_list(plist);
    }
    return 0;
}