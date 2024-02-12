#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


using namespace std;

const int maxrow = 10;  // gave the system to accept 10 rows by default

string ItemName[maxrow] = {}; // stores the value in the maxrow
string ItemId[maxrow] = {};



void Additem()  // the add function
{
    char itemname[50];
    char itemid[6];
    cin.ignore();

    cout<<"Enter item id: \n";
    cin.getline(itemid, 6);
    cout<<"Enter item name: \n";
    cin.getline(itemname, 50);

    for (int x = 0; x < maxrow; x++)
    {
        if (ItemId[x] == "\0")  // if the item id is correct will output the item name and id
        {
            ItemName[x] = itemname;
            ItemId[x] = itemid;
            break;
        }
    }





}



void Listitem()  // the listing function
{
    system("CLS");
    cout<<"Items in the storage" <<endl;
    cout<<"=======================================" <<endl;

    int counter = 0;         // adds number to the table different from the id to make it easy to classify the rows
    cout<<"No. |    ID    |          Name    "  <<endl                     
        <<"---------------------------------------\n";
    for (int x = 0; x < maxrow; x++)
    {
        if(ItemId[x] != "\0")
            {
                counter++;
                cout<< " "<<counter <<"   " <<ItemId[x]<<"           "<<ItemName[x]<<endl;

            }
    }

    if (counter == 0)
    {
        cout<<"No Record found!" << endl;
    }

    cout<<"======================================="<<endl;
}


void  readfile()
{
string line;
  ifstream myfile ("fms");
  if (myfile.is_open())
  {
    while (! myfile.eof() )
    {
      getline (myfile,line);
      cout << line  << endl;
    }
    myfile.close();
  }

  else cout << "Unable to open file";
}




void Searchitem(string search)  // the function for the search
{
    system("CLS");
    cout<<"Current Record" <<endl;
    cout<<"======================================" <<endl;
    int counter = 0;
    for(int x = 0; x < maxrow; x++)     //maxrow is the default 10 rows given
    {
        if(ItemId[x] == search)
        {
            counter++;
            cout<<"  " << counter << "      " <<ItemId[x] <<"            "<<ItemName[x] << endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout<<"No Record found" <<endl;
    }
    cout<<"======================================"<<endl;
}

void Updateitem(string search)   // the item updater function
{
    char itemname[50];
    char itemid[6];

    int counter = 0;
    for(int x = 0; x < maxrow; x++)
    {
        if(ItemId[x] == search)
        {
            counter ++;
            cout<<"New Item Name" <<endl;
            cin.getline(itemname, 50);

            ItemName[x] = itemname;
            cout<<"Updated record successfully"<<endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout<<"No Record found" <<endl;
    }

}

void Deleteitem(string search)  // function for deleting items
{
    int counter = 0;
    for(int x = 0; x < maxrow; x++)
    {
        if(ItemId[x] == search)
        {
            counter++;

            ItemId[x] = "";  // emptys the values inside
            ItemName[x] = "";

            cout<<"Successfully Deleted Record" <<endl;
            break;
        }
    }

    if (counter == 0)
    {
        cout<<"ID Number does not exist";
    }


}

void SavetoFile()     // saves the data on the memory to file
{
    ofstream myfile;
    myfile.open("fms");

    for(int x = 0; x < maxrow; x++)
    {
        if(ItemId[x] == "\0")
        {
            break;
        }
        else
        {
            myfile << ItemId[x] + "," + ItemName[x] <<endl;
        }
    }

}





int main()
{
    system("CLS");
    int option;
    string ID;
    system("CLS");
do{
    cout<<"Welcome to Farm Information Management System" <<endl;
    cout<<"1. Add item to storage" <<endl;
    cout<<"2. List items in storage" <<endl;
    cout<<"3. Read from Storage" <<endl;
    cout<<"4. Search item in storage" <<endl;
    cout<<"5. Update item in storage" <<endl;
    cout<<"6. Delete item in storage" <<endl;
    cout<<"7. Save file to storage" <<endl;
    cout<<"Enter your option: ";
    cin>> option;


    switch (option)    // used the switch method to make it easier for the user to select its option
    {
        case 1: Additem();  // when number 1 is pressed calls the additem function above
            break;
        case 2: Listitem(); // when number 2 is pressed calls the listitme function above
            break;
        case 3: readfile();
            break;
        case 4:
            cin.ignore();           // ignores the codes below from interfering
            cout<<"Search by ItemId" <<endl;
            getline(cin, ID);
            Searchitem(ID);
            break;
        case 5:
            cin.ignore();
            cout<<"Search by ItemId" <<endl;
            getline(cin, ID);
            Updateitem(ID);
            break;
        case 6:
            cin.ignore();
            cout<<"Delete by ItemId" <<endl;
            getline(cin, ID);
            Deleteitem(ID);
            cin.ignore();
            system("CLS");
            break;
        case 7:
            SavetoFile();
            cout<<"Exit... Saving to file"<<endl;

       }

}while (option);

    return 0;
    }



