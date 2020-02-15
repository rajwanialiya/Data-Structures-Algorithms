// Aliya Rajwani 20780325
// Elodie Xie 20796575

#include<iostream>
#include "lab2_drones_manager.hpp"

using namespace std;

// TODO: Implement all of the listed functions below
DronesManager::DronesManager() {
    size = 0;
}

DronesManager::~DronesManager() {
    DroneRecord *store, *position;
    store = first;
    position = first;

    while (position->next != nullptr) {
        position = position->next;
//    delete store -> prev;
        delete store->next;

        store->prev = nullptr;
        store->next = nullptr;
        store = position;
    }
    delete first;
    delete last;
    delete store;
    delete position;
    first = nullptr;
    last = nullptr;
    store = nullptr;
    position = nullptr;

}

// PURPOSE: Comparison operator to compare two DroneRecord instances
bool operator==(const DronesManager::DroneRecord &lhs, const DronesManager::DroneRecord &rhs) {
    bool equal = true;
    equal &= lhs.manufacturer == rhs.manufacturer;
    equal &= lhs.range == rhs.range;
    equal &= lhs.batteryType == rhs.batteryType;
    equal &= lhs.description == rhs.description;
    equal &= lhs.yearBought == rhs.yearBought;
    equal &= lhs.droneID == rhs.droneID;
    equal &= lhs.droneType == rhs.droneType;
    
    return equal;
}

unsigned int DronesManager::get_size() const {
    return size;
}

bool DronesManager::empty() const {
    return (size == 0); // if size = 0, returns true
}

// PURPOSE: Returns the value at the given index in the list
// if index invalid return last element
DronesManager::DroneRecord DronesManager::select(unsigned int index) const {
    DroneRecord *position;

    if (size == 0) {
        return DroneRecord(0); // if list is empty returns DroneRecord(0)
    } else {
        position = first;
        int spot = 0;
        while (position->next != nullptr) {
            if (spot == index) {
                return *position;
            }
            position = position->next;
            ++spot;
        }
        return *position;
    }
}

// PURPOSE: Searches for the given value, and returns the index of this value if found	
// if not found, returns the size of the list; if the list is empty, returns 0
unsigned int DronesManager::search(DroneRecord value) const {
    DroneRecord *position;
    position = first;
    int spot = 0;

    while (position->next != nullptr) {
        if (*position == value) {
            return spot;
        }
        position = position->next;
        ++spot;
    }
    return size;
}

bool DronesManager::insert(DroneRecord value, unsigned int index) {
    DroneRecord *position;
    auto* item = new DroneRecord(value);
    int spot = 0;
    position = first;

    while (position->next != nullptr) {
        if (spot == index) {
            value.prev = position->prev;
            value.next = position;
            position->prev = &value;
            position = nullptr;
            return true;
        }
        ++spot;
    }
    position = nullptr;
    return false;
}

bool DronesManager::insert_front(DroneRecord value) {
    DroneRecord *position;
    
    if (!first) return false;

    position = first;
    position->prev = &value;
    value.next = first;

    return true;
}

bool DronesManager::insert_back(DroneRecord value) {
    if (!first) return false;
    DroneRecord *position;
    position = first;

    while (position->next != nullptr) { //takes to last node
        position = position->next;
    }
    position->next = &value;
    value.prev = position;
    value.next = nullptr;
    return true;
}

bool DronesManager::remove(unsigned int index) {
    DroneRecord *position;
    position = first;
    int spot = 0;
    while (position->next != nullptr) {
        if (spot == index) {
            DroneRecord *prev = position->prev;
            DroneRecord *next = position->next;
  
            prev->prev = next;
            next->prev = prev;

            delete position;
            position = nullptr; // set empty pointer to null pointer
            return true;
        } else {
            position = position->next;
        }
    }
    return false;
}

bool DronesManager::remove_front() {
    DroneRecord *position, *temporary;

    if (!first) return false;

    // Set second position to be first and clear first pointer
    temporary = first;
    position = first->next;
    position->prev = nullptr;
    first = position;

    // Delete first position
    delete temporary;
    temporary = nullptr;

    return true;
}

bool DronesManager::remove_back() {
    if (!first) return false;
    DroneRecord *position;
    while (position->next != nullptr) { //takes to last node
        position = position->next;
    }
    position->prev->next = nullptr; // last node
    delete position;
    position = nullptr;
    return true;
}

// PURPOSE: Prints all the elements in the list to the console
void DronesManager::print() const {
    DroneRecord *position;
    position = first;

    while (position->next != nullptr) {
        cout << "range: " << position->range << endl;
        cout << "battery: " << position->batteryType << endl;
        cout << "year: " << position->yearBought << endl;
        cout << "id: " << position->droneID << endl;
        cout << "type: " << position->droneType << endl;
        cout << "manufacturer: " << position->manufacturer << endl;
        cout << "description: " << position->description << endl;

        position = position->next;
    }
}

// PURPOSE: Replaces value at the given index with the given value; the list is not sorted	
bool DronesManager::replace(unsigned int index, DroneRecord value) {
    if (size < index) {
        return false; // takes care of invalid index
    } else {
        DroneRecord *position;
        position = first;
        int spot = 0;

        while (position->next != nullptr) {
            if (spot == index) {
                position->droneType = value.droneType;
                position->manufacturer = value.manufacturer;
                position->range = value.range;
                position->yearBought = value.yearBought;
                position->batteryType = value.batteryType;
                position->description = value.description;
                position->droneID = value.droneID;
                return true;
            }
            position = position->next;
            ++spot;
        }
        return false;
    }
}

// PURPOSE: Reverses the linked list
bool DronesManager::reverse_list() {
    DroneRecord *position;
    position = first;

    while (position->next != nullptr) {
        DroneRecord *temporary = position->prev; // get prev
        position->prev = position->next; // prev node = next node 
        position->next = temporary; // next node = prev node
        position = position->prev; // switch
    }

    return true;
}

bool DronesManagerSorted::is_sorted_asc() const {
    DroneRecord *position;
    int last = position->droneID;
    // cycle through nodes no longer in ascending order
    while (position->next != nullptr && position->next->droneID > last) {
        position = position->next;
        last = position->droneID;
    }
    return (position->next == nullptr);
}

bool DronesManagerSorted::is_sorted_desc() const {
    DroneRecord *position;
    int last = position->droneID;

    // cycle through nodes no longer in descending order
    while (position->next != nullptr && position->next->droneID < last) {
        position = position->next;
        last = position->droneID;
    }
    return (position->next == nullptr);
}

bool DronesManagerSorted::insert_sorted_asc(DroneRecord val) {
    DroneRecord *position;
    position = first;

    // cycle through nodes until next drone ID is greater than prev
    while (position->next != nullptr && position->next->droneID < val.droneID) {
        position = position->next;
    }

    if (position->next != nullptr) return false;
    
    position->next->prev = &val;
    val.next = position->next;
    val.prev = position;
    position->next = &val;
    return true;
}

bool DronesManagerSorted::insert_sorted_desc(DroneRecord val) {
    DroneRecord *position;
    position = first;
    while (position->next != nullptr && position->next->droneID > val.droneID) { //cycle through nodes until next drone ID is greater
        position = position->next;
    }

    if (position->next != nullptr) return false;

    position->next->prev = &val;
    val.next = position->next;
    val.prev = position;
    position->next = &val;

    return true;
}

void DronesManagerSorted::sort_asc() { //selection sort
    DroneRecord *position, *temporary, *minimum;
    
    if (!first) { 
      return; 
    }

    position = first;
    temporary = first;
    minimum = first;
    int index = 0;
    int index_2 = 0;
    int minIndex = 0;

    while (position->next != nullptr) { //cycle through linked list
        while (temporary->next != nullptr) {
            if (temporary->droneID < minimum->droneID) { //update min
                minimum = temporary;
                minIndex = index_2;
            }
            temporary = temporary->next;
            index_2++;
        }
        index++;

        replace(index, *minimum);
        replace(index_2, *position); //switch pointers
        index_2 = index;

        position = position->next;
        temporary = position;
        minimum = position;
    }
}

void DronesManagerSorted::sort_desc() {
    DroneRecord *position, *temporary, *maximum;
   
    if (!first){
      return; 
    }

    position = first;
    temporary = first;
    maximum = first;
    int index = 0;
    int index_2 = 0;

    while (position->next != nullptr) { //cycle through linked list
        while (temporary->next != nullptr) {
            if (temporary->droneID > maximum->droneID) { // update max
                maximum = temporary;
            }
            temporary = temporary->next;
            index_2++;
        }
        index++;

        replace(index, *maximum); //switch pointers
        replace(index_2, *position);
        index_2 = index;

        position = position->next;
        temporary = position;
        maximum = position;
    }
}

