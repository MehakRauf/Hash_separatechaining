#include <iostream>
using namespace std;

struct HNode
{
    int value;
    struct HNode *next = NULL;
};
//hashfunction to calculate the index
int hash_function(int key_value, int size)
{
    return (key_value % size);
}
//function to insert a value
void insert(HNode HTable[], int size)
{
    cout << "Enter the keyvalue: " << endl;
    int key;
    cin >> key;
    int ind = hash_function(key, size);
    //checking if the there is no value already present at the indes
    if (HTable[ind].value == -1)
    {
        HTable[ind].value = key;
    }
    else
    {
        //otherwise allocating memory
        struct HNode *temp = (struct HNode *)malloc(sizeof(struct HNode));
        //assigning the values
        temp->value = key;
        temp->next = NULL;
        //chacking if the next of the index is null then assigning it a value
        if (HTable[ind].next == NULL)
        {
            HTable[ind].next = temp;
        }
        //otherwise
        else
        {
            //creating a curr node to traverse the list present at the specific node
            //until we find it empty so we can place the value 
            struct HNode *curr = HTable[ind].next;
            //traversing till the end
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            //finally assigning the value
            curr->next = temp;
        }
    }
}
//function to search a value
bool search(HNode HTable[], int size)
{
    //taking the value as input
    int toSearch;
    cout << "Enter the value you want to search: " << endl;
    cin >> toSearch;
    int ind = hash_function(toSearch, size);
    //checking it initially at the calculated index 
    if (HTable[ind].value == toSearch)
    {
        return true;
    }
    else
    {
        //if the next of the index is null means vlaue is not present
        if (HTable[ind].next == NULL)
        {
            return false;
        }
        else
        {
            //otherwise traversing it till we find the value
            struct HNode *curr = HTable[ind].next;
            while (curr->next != NULL)
            {
                if (curr->value == toSearch)
                {
                    return true;
                }
                //moving the cursor forward
                curr = curr->next;
            }
        }
    }
}
int main()
{
    //taking the size of Htable as input
    int size;
    cout << "Enter the size of the hash table: " << endl;
    cin >> size;
    //declaring the array as a struct type
    HNode Htable[size];
    //making the values initlaly as -1 
    for (int i = 0; i < size; i++)
    {
        Htable[i].value = -1;
    }
    insert(Htable, size);
    insert(Htable, size);
    insert(Htable, size);
    insert(Htable, size);
    insert(Htable, size);
    insert(Htable, size);
    cout << search(Htable, size);
}