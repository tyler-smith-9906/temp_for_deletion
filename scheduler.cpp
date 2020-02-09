#include <string>
#include <iostream>
#include <cctype>

#include "scheduler.h"

using namespace std;

bool Scheduler::isAvailable(unsigned start, unsigned duration) const//Untested, might be good
{
    int check = 0; 
    ScheduleNode* temp = new ScheduleNode("filler");
    temp = head;
    for(int i = 0; i < 99; i++)//iterates 99 times to check if time is valid
    {
        /*
        if(temp->length < i)
        {
            return false;
        }
        */
        if(temp->name == "FREE")//tests if the node's name value = free
        {
            cout << "Found a free node" << endl;
            if((start + duration) == temp->length)
            {
                return true;
            }
            else
            {
                return false;
            }
            
        }
        /*
        if(temp->next == NULL)//Checks if the remainder of the list is free
        {
            return true;
        }
        */
        temp = temp->next;
    }
    return false;
}

void Scheduler::schedule(const string& name, unsigned start, unsigned duration)
{
    int pos = 0;//keeps track of the position the node is in
    if((start + duration > 99)||(duration == 0)) // Ensures proper length of time
    {
        while((start+duration > 99)||(duration == 0))
        {
            cout << "Invalid input, try again" << endl;
            cout << "Enter a new start value" << endl;
            cin >> start;
            cout << endl;
            cout << "Enter a new duration" << endl;
            cin >> duration;
        }
    }
    ScheduleNode* temp = new ScheduleNode(name);
    temp = head;    
    for(int i = 0; i < start; i++)
    {
        temp = temp->next;
    }
    temp->length = duration;
    temp->name = name;
    temp->prev->next = temp;
}

void Scheduler::free(unsigned start)
{
    //
    return;
}

void Scheduler::printSchedule() const
{
    //
    return;
}

Scheduler::~Scheduler()
{
    //
    return;
}

void ScheduleNode::merge(ScheduleNode* other)
{
    //
    return;
}