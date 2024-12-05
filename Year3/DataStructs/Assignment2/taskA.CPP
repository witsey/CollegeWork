#include <iostream>
#include <map>
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

    public:
        PatientNode *head, *tail;
        SortedLinkedList() { this->head = this->tail = nullptr; }
        

        // node insertion
        void add_to_head(Patient new_patient) 
        {
            if (head == nullptr) { this->head = this->tail = new PatientNode(new_patient); }

            else 
            {
                PatientNode* newPatient = new PatientNode(new_patient, head);
                this->head = newPatient;
            }
        }

        void add_to_tail(Patient new_patient) 
        {
            if (tail == nullptr) { this->head = this->tail = new PatientNode(new_patient); }

            else
            {
                this->tail->next = new PatientNode(new_patient);
                this->tail = this->tail->next;
            }
        }


        void add_to_middle(Patient new_patient) 
        {

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
            return;
            
        }


        // node deletion
        void delete_from_head() 
        {
            if (head == tail) 
            {
                delete head;
                head = tail = nullptr;
                return;
            }

            PatientNode* tmp = head;
            head = head->next;
            delete tmp;
        }


        void delete_from_tail() 
        {
            if (tail == head) 
            {
                delete_from_head(); // empty list or one element so it doesn't matter
                return;
            }

            PatientNode* cur = head;
            while(cur->next != tail) cur = cur->next;

            tail = cur;
            delete tail->next;
            tail->next = nullptr;
        }


        // printing the list
        void print() 
        {
            
        }


        ~SortedLinkedList() {delete this->head; delete this->tail;}
};


class PriorityQueue {
    public:
        SortedLinkedList queue;

        
};



int main() {return 0;}