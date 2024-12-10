#include <iostream>
#include <map>
#include <list>
#include <string>
using namespace std;



int condition_to_priority(string condition)
{
    map<string, int> condition_to_priority; 
    condition_to_priority["normal"] = 3;
    condition_to_priority["urgent"] = 2;
    condition_to_priority["critical"] = 1;

    return condition_to_priority[condition];
}


class Patient {
    public:
        string name;
        int age;
        string condition;
        int priority;

        Patient() : name(""), age(0), condition("normal"), priority(3) {}
        Patient(string name, int age, string condition) 
        {
            this->name = name;
            this->age = age;
            this->condition = condition;
            this->priority = condition_to_priority(condition);

        }

        void print() {
            cout << endl;
            cout << "Patient name: " << this->name << endl;
            cout << "Patient age: " << this->age << endl;
            cout << "Patient condition: " << this->condition << endl;
            cout << "Patient priority: " << this->priority << endl;
        }
};


class PatientNode 
{
    public:
        Patient patient;
        PatientNode* next;

        PatientNode() {next = nullptr;}
        PatientNode(Patient patient, PatientNode* next = nullptr)  
        { 
            this->patient = patient;
            this->next = next;
        }
};



class SortedLinkedList
{

    private: int size;
    public:
        PatientNode *head, *tail;
        SortedLinkedList() { this->head = this->tail = nullptr; size = 0;}
        

        // node insertion
        void add_to_head(Patient new_patient) 
        {
            size++;
            if (head == nullptr) { this->head = this->tail = new PatientNode(new_patient); }

            else 
            {
                PatientNode* newPatient = new PatientNode(new_patient, head);
                this->head = newPatient;
            }
        }

        void add_to_tail(Patient new_patient) 
        {
            size++;
            if (tail == nullptr) { this->head = this->tail = new PatientNode(new_patient); }

            else
            {
                this->tail->next = new PatientNode(new_patient);
                this->tail = this->tail->next;
            }
        }


        void add_to_middle(Patient new_patient) 
        {
            size++;
            if (head == 0)  {add_to_head(new_patient); return;}

            PatientNode* current = head->next;
            PatientNode* prev = head;

            while (current->patient.priority <= new_patient.priority)
            {
                prev = current;
                current = current->next;
                if (current == nullptr) 
                {
                    prev->next = new PatientNode(new_patient);
                    tail = prev->next;
                    return;
                }
            }

            prev->next = new PatientNode(new_patient);
            prev->next->next = current;


            if (current == nullptr)
                tail = prev->next;

            return;
            
        }


        PatientNode* delete_from_head() 
        {
           if (head == nullptr) return nullptr;


            --size;
            PatientNode* tmp = head;
            head = head->next;
            
            if (head == nullptr) 
                tail = nullptr;

            tmp->next = nullptr; 
            return tmp;
        }


        // printing the list
        void print() 
        {
            PatientNode* current = head;
            while (current) 
            {
                current->patient.print();
                current = current->next;
            }
        }

        int getSize() {return this->size;}


        ~SortedLinkedList() 
        {
            while (head) 
            {
                PatientNode* tmp = head;
                head = head->next;
                delete tmp;
            }
        }
};


class PriorityQueue {
    public:
        SortedLinkedList queue;
        list<PatientNode*> processed_patients;


        bool isEmpty() {return queue.getSize() == 0;}

        void add_patient(Patient new_patient) {

            switch (new_patient.priority)
            {
                case 3:
                    queue.add_to_tail(new_patient);
                    break;
                
                default:
                    queue.add_to_middle(new_patient);
                    break;
            } 
        }


        void proccess_patient() {

            PatientNode* highest_patient = queue.delete_from_head();

            if (highest_patient != nullptr)
            {
                processed_patients.push_front(highest_patient);
                highest_patient->patient.print();
                cout << endl;
            }
        }

        void display() 
        {
            cout << "-----------CURRENT PATIENTS: " << endl;
            queue.print();

            cout << endl;
        }
        int size() {return queue.getSize();}


        void display_processed_patients() 
        {
            cout << "---------------PREVIOUS PATIENTS:" << endl;
            for (PatientNode* node : processed_patients) 
            {
                node->patient.print();
            }

            cout << endl;
        }


        string& FrontName() 
        {
            string name = queue.head->patient.name;

            if (this->isEmpty())  throw "Queue is empty.";

            display_processed_patients();
            display();
            cout << this->size() << " PATIENTS IN THE QUEUE." << endl;

            return name;
        } 
};



int main() 
{
    PriorityQueue p;
    
    Patient p1("A", 19, "normal");
    Patient p2("B", 21, "normal");
    Patient p3("C", 22, "normal");
    Patient p4("D", 29, "normal");

    p.add_patient(p1);
    p.add_patient(p2);
    p.add_patient(p3);
    p.add_patient(p4);

    p.proccess_patient();
    p.proccess_patient();

    string name = p.FrontName();
    cout << name;
    return 0;
}