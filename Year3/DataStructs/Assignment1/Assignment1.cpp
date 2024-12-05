#include <iostream>
#include <string>
using namespace std;

// task 1:
class Student 
{
public:
    string name;
    long int ID;
    double GPA;
    Student* next;

    Student() {name = ""; ID = 0; GPA = 0.0; next = nullptr;}
    Student(string name, long int ID, double GPA, Student* next = nullptr) 
    {
        this->name = name;
        this->ID = ID;
        this->GPA = GPA;
        this->next = next;
    }

};


class StudentList 
{
public:
    Student *head, *tail;
    int size = 0;

    StudentList() { head = tail = nullptr; }
    ~StudentList() 
    { 
        Student* current = head;
        while (current != nullptr) 
        {
            Student* tmp = current->next;
            delete current;
            current = tmp;
        }
    }


    void insert(Student* student) 
    {

        size++;
        if (head == nullptr) { head = student; return; }

        if (student->ID < head->ID) 
        {
            student->next = head;
            head = student;
            return;
        }

        Student* current = head;
        while (current->next != nullptr && current->next->ID < student->ID ) current = current->next;  

        student->next = current->next;
        current->next = student;

        if (student->next == nullptr) 
        {
            tail = student;
        }
    }


    bool deleteStudent(long int ID) 
    {

        if (head == nullptr) return false;

    
        if (head->ID == ID) 
        {
            Student* tmp = head;
            head = head->next;
            delete tmp;
            --size;

            if (head == nullptr) tail = nullptr;
                
            cout << "Student: " << ID << " has been deleted" << endl;
            return true;
        }


        Student* current = head;
        
        while (current->next != nullptr) 
        {
            if (current->next->ID == ID) 
            {
                Student* tmp = current->next;
                current->next = tmp->next;
                delete tmp;
                --size;

                if (current->next == nullptr) tail = current;

                cout << "Student: " << ID << " has been deleted" << endl;
                return true;
            }

            current = current->next;
        }

        cout << "No student with the ID: " << ID << " is founded" << endl;
        return false;
    }


    void search(long int ID) 
    {
        Student* current = head;

        while(current != nullptr) 
        {
            if (current->ID == ID) break;
            current = current->next;
        } 

        if (current == nullptr) 
        {
            cout << "Student with ID: " << ID << " has not been found." << endl;
            return;
        }

        cout << "Name: " << current->name << endl;
        cout << "ID: " << current->ID << endl;
        cout << "GPA: " << current->GPA << endl;
        return;

    }


    void display() 
    {
        Student* current = head;
        while (current != nullptr) 
        {
            cout << current->ID << " ";
            current = current->next;
        }

        cout << endl; 
    }


    int getSize() {return size;} 
};



// task 2:
class Node 
{
public:
    char data;
    Node* next;
    Node* prev;

    Node() { char data = '\0'; next = nullptr; prev = nullptr; }
    Node(char data, Node* next = nullptr, Node* prev = nullptr) 
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    } 
};


class DoublyLinkedList 
{
    public:
    
        Node *head, *tail;
        int size = 0;
        DoublyLinkedList() {head = tail = nullptr;}
        

        void insert_to_tail(char value) 
        {
            size++;
            Node* newNode = new Node(value);

            if (head == nullptr) 
            {
                head = tail = newNode;
                return;
            }

            Node* current = head;
            while (current->next != nullptr)
            {
                current = current->next;
            }

            current->next = newNode;
            newNode->prev = current;
            tail = newNode;

            return;
        }


        void insert_at_position(char value, int index) 
        {

            size++;
            if (head == nullptr) { insert_to_tail(value); }

            int counter = 0;
            Node* current = head;

            while (current != nullptr && counter != index) 
            {
                counter++;
                current = current->next;
            }

            Node* tmp = current->next;
            Node* newNode = new Node(value);
            current->next = newNode;
            newNode->prev = current;
            newNode->next = tmp;
            tmp->prev = newNode;

            return;
        }


        void delete_char(int index) 
        {
            int counter = 0;
            Node* current = head;

            while (current != nullptr && counter + 1 != index) 
            {
                counter++;
                current = current->next;
            }

            if (current == nullptr) return; 

            Node* tmp = current->next;
            current->next = tmp->next;
            tmp->next->prev = current;
            delete tmp;
            size--;
            return;
        }


        void concat(DoublyLinkedList list) 
        {
            Node* current = list.head;
            while (current != nullptr) 
            {
                insert_to_tail(current->data);
                current = current->next;
            }

            size += list.size;
            return;
        }


        string extract(int low, int high) 
        {

            string exctraction = "";

            if (low >= size) return exctraction;

            Node *current = head;
            int counter = 0;

            while (current != nullptr && counter <= high )
            {
                if (counter >= low) 
                {
                    exctraction += current->data;
                }
                counter++;
                current = current->next;
            }
            
            return exctraction;
        }


        int search(string substring) 
        {
            Node* current = head;
            int ctr = 0;
            
            while (current != nullptr) 
            {

                if (current->data == substring[0]) 
                {
                    Node* subCurrent = current->next;
                    bool found = true;

                    for (int i = 1; i < substring.length(); ++i) 
                    {
                        if (subCurrent == nullptr) return -1;
                        
                        if (subCurrent->data != substring[i]) { found = false; break; }
                        subCurrent = subCurrent->next; 
                    }

                    if (found == true) return ctr;
                }

                current = current->next;
                ctr++;
            }

            return -1;
        }


        bool replace(string substring, string replacement) 
        {
            int occ = search(substring);

            if (occ == -1) return false;

            Node* current = head;
            int ctr = 0;

            while (ctr < occ && current != nullptr) {
                current = current->next;
                ctr++;
            }

            Node* subCurrent = current;
            int i = 0;
            
            while (subCurrent != nullptr && i < replacement.length()) {

                if (i < substring.length()) {
                   
                    subCurrent->data = replacement[i];
                    subCurrent = subCurrent->next;

                } else {
                    
                    Node* newNode = new Node(replacement[i]);
                    
                    newNode->next = subCurrent;
                    newNode->prev = subCurrent->prev;
                        
                    newNode->prev->next = newNode;
                    subCurrent->prev = newNode;
                    size++;
                    
                }
                ++i;
            }

            while (i < replacement.length()) {

                Node* newNode = new Node(replacement[i]);
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
                size++;
                ++i;
            }

            
            if ( i < substring.length() ) 
            {
                while (i < substring.length()) 
                {
                    
                    if (subCurrent->next == nullptr) 
                    {
                        tail = tail->prev;
                        delete tail->next;
                        tail->next = nullptr;

                        if (tail->prev == nullptr) head = tail;
                        break;
                    }

                    Node* tmp = subCurrent;
                    subCurrent->prev->next = tmp->next;
                    tmp->next->prev = subCurrent->prev;

                    subCurrent = tmp->next;
                    delete tmp;

                    ++i;
                    
                }
            } 

            return true;

        }


        void reverse() 
        {
            Node *low = head;
            Node *high = tail;

            while (low != high && low->next != high) 
            {
                swap(low->data, high->data);
                low = low->next;
                high = high->prev;
            }
        }


        void print() 
        {
            Node* current = head;
            while (current != nullptr) 
            {
                cout << current->data << " ";
                current = current->next;
            }
        }

};



// main:
int main() 
{

    // task 1:
    cout << "// TASK 1 //" << endl;

    StudentList list;

    Student* s1 = new Student("Ahmed", 20190001, 3.4);
    Student* s2 = new Student("Menna", 20190010, 3.5);
    Student* s3 = new Student("Yousef", 20190003, 1.4);


    list.insert(s1);
    list.insert(s2);
    list.insert(s3);
    list.display();
    cout << endl;


    Student* s4 = new Student("Ali", 20190005, 2.5);
    list.insert(s4);
    list.display();
    cout << endl;

    list.deleteStudent(20190001);
    list.display();
    cout << endl;

    list.search(20190005);
    cout << endl;


    cout << endl << "Students number: " << list.getSize();




    // task 2:
    cout << endl << endl <<  "// TASK 2 //" << endl << endl;

    DoublyLinkedList l1;
    l1.insert_to_tail('h');
    l1.insert_to_tail('e');
    l1.insert_to_tail('l');
    l1.insert_to_tail('l');
    l1.insert_to_tail('o');

    DoublyLinkedList l3;
    l3.insert_to_tail('w');
    l3.insert_to_tail('o');
    l3.insert_to_tail('r');
    l3.insert_to_tail('l');
    l3.insert_to_tail('d');


    l1.concat(l3);
    cout << "concatenated list: "; l1.print(); cout << endl;

    int charToRemove;
    cout << "choose a character by index to remove: ";
    cin >> charToRemove;

    l1.delete_char(1);
    cout << "list after removal: "; l1.print(); cout << endl;

    int low, high;
    cout << "enter a lower bound of a range: ";
    cin >> low;

    cout << "enter a higher bound of a range: ";
    cin >> high;

    cout << "extraction: " << l1.extract(low, high) << endl;

    string  substring;
    cout << "search for a string in the list: ";
    cin >> substring;

    cout << "found at index: " << l1.search(substring) << endl;


    string substringToReplace, replacement;
    cout << "enter 2 substrings to replace one with another" << endl << endl;

    cout << "substring 1: ";
    cin >> substringToReplace;
    cout << endl;

    cout << "its replacement: ";
    cin >> replacement;
    cout << endl;

    l1.replace(substringToReplace, replacement);
    cout << "list after replacement: "; l1.print(); cout << endl;

    l1.reverse();
    cout << "reversed list: "; l1.print(); cout << endl;

    return 0;
}