#include <conio.h>
#include "Tree.h"

using namespace std;

int get_k()
{
    while (true)
    {
        int k = 0;
        cin >> k;
        if ((k == 0) || (k == 224)) cin >> k;
        if ((k == 1) || (k == 2) || (k == 3) || (k == 4)) return k;
        else cout << "Repeat input";
    }
}

int main()
{
    Map map;
    int m = 0;
    int key;
    string data;
    while (true)
    {
        system("cls");
        cout << "1 - Insert element\n2 - Get data\n3 - Erase element\n4 - Exit\n\nTree:\n";
        map.print();
        cout << "\n\n";
        int m = get_k();
        if (m == 1)
        {
            cout << "Key: ";
            cin >> key;
            cout << "Data: ";
            cin >> data;
            try
            {
                map.insert(key, data);
            }
            catch (const char* err)
            {
                cout << err;
                system("pause");
            }
        }
        if (m == 2)
        {
            cout << "Key: ";
            cin >> key;
            try
            {
                cout << "Data: " << map.find(key) << "\n";
                system("pause");
            }
            catch (const char* err)
            {
                cout << err;
                system("pause");
            }
        }
        if (m == 3)
        {
            cout << "Key: ";
            cin >> key;
            try
            {
                map.erase(key);
            }
            catch (const char* err)
            {
                cout << err;
                system("pause");           
            }
        }
        if (m == 4) break;
    }
    return 0;
}
