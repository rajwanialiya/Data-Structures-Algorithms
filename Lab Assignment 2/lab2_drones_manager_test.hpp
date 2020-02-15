// Aliya Rajwani 20780325
// Elodie Xie 20796575

#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager manager;
		ASSERT_TRUE(manager.get_size() == 0);
		ASSERT_TRUE(manager.empty() == true);
		ASSERT_TRUE(manager.first == nullptr);
		ASSERT_TRUE(manager.last == nullptr);
	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager manager1, manager2;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager2.insert_back(DronesManager::DroneRecord(100));
	    
		ASSERT_TRUE(manager1.get_size() == manager2.get_size() && manager1.get_size() == 1);
		ASSERT_TRUE(manager1.first != nullptr && manager1.first == manager1.last);
		ASSERT_TRUE(manager2.first != nullptr && manager2.first == manager2.last);
		ASSERT_TRUE(manager1.first->prev == nullptr && manager1.last->next == nullptr);
		ASSERT_TRUE(manager2.first->prev == nullptr && manager2.last->next == nullptr);
		ASSERT_TRUE(manager1.select(0) == manager2.select(0) && manager1.select(0) == DronesManager::DroneRecord(100));
	    return true;
	}
	
	// TODO: Implement all of the test cases below
	
	// PURPOSE: select() and search() work properly
	bool test3() {
	    return false;
	}
	
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
	    return false;
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
	    return false;
	}
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
	    return false;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
	    return false;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
		DronesManager manager1;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager1.insert_front(DronesManager::DroneRecord(150));
	    
		ASSERT_TRUE(manager1.remove(0));
		ASSERT_TRUE(manager1.remove(0));
		ASSERT_FALSE(manager1.remove(0));

		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(150), 0));
		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(50), 0));
		ASSERT_TRUE(manager1.get_size() == 2)
	    return true;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		DronesManager manager1;
		ASSERT_FALSE(manager1.remove(0))
		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(150), 0));
		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(50), 0));
		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(130), 0));
		ASSERT_TRUE(manager1.insert(DronesManager::DroneRecord(54), 0));
		ASSERT_TRUE(manager1.remove(0))
		ASSERT_TRUE(manager1.remove(3))
		ASSERT_FALSE(manager1.remove(100))
		ASSERT_TRUE(manager1.get_size() == 2)
	    return true;
	}    
	    	
	// PURPOSE: inserts into an unsorted list, then sort the list
	bool test10() {
		DronesManagerSorted manager1;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager1.insert_front(DronesManager::DroneRecord(33));
		manager1.insert_front(DronesManager::DroneRecord(150));
		manager1.sort_asc();

        ASSERT_TRUE(manager1.select(0).droneID == 33);
        ASSERT_TRUE(manager1.select(1).droneID == 100);
        ASSERT_TRUE(manager1.select(2).droneID == 150);
	   	return true;
	}  
	
	// PURPOSE: insert and remove into sorted manager in ascending order
	bool test11() {
		DronesManagerSorted manager1;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager1.insert_front(DronesManager::DroneRecord(33));
		manager1.insert_front(DronesManager::DroneRecord(150));
		manager1.sort_asc();
		manager1.insert_sorted_asc(DronesManager::DroneRecord(120));

        ASSERT_TRUE(manager1.select(2).droneID == 120);
	   	return true;	
	}
	
	// PURPOSE: insert and remove into sorted manager in descending order
	bool test12() {
		DronesManagerSorted manager1;
		manager1.insert_front(DronesManager::DroneRecord(100));
		manager1.insert_front(DronesManager::DroneRecord(33));
		manager1.insert_front(DronesManager::DroneRecord(150));
		manager1.sort_desc();
		manager1.insert_sorted_desc(DronesManager::DroneRecord(120));

        ASSERT_TRUE(manager1.select(1).droneID == 120);
	   	return true;	
	}  
};

#endif
