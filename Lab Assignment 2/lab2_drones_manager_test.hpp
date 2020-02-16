// Aliya Rajwani 20780325
// Elodie Xie 20796575

#ifndef DRONES_MANAGER_TEST
#define DRONES_MANAGER_TEST

#include "lab2_drones_manager.hpp"

// User defined asserts
#define ASSERT_TRUE(T) if (!(T)) return false;
#define ASSERT_FALSE(T) if ((T)) return false;

class DronesManagerTest {
public:
	// PURPOSE: New empty list is valid
	bool test1() {
		DronesManager test;
		ASSERT_TRUE(test.get_size() == 0);
		ASSERT_TRUE(test.empty() == true);
		ASSERT_TRUE(test.first == nullptr);
		ASSERT_TRUE(test.last == nullptr);
	    return true;
	}
	
	// PURPOSE: insert_front() and insert_back() on zero-element list
	bool test2() {
		DronesManager test_1, test_2;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(100);

		manager1.insert_front(record_1);
		manager2.insert_back(record_2);
	    
		ASSERT_TRUE(test_1.get_size() == test_2.get_size() && test_1.get_size() == 1);
		ASSERT_TRUE(test_1.first != nullptr && test_1.first == test_1.last);
		ASSERT_TRUE(test_2.first != nullptr && test_2.first == test_2.last);
		ASSERT_TRUE(test_1.first->prev == nullptr && test_1.last->next == nullptr);
		ASSERT_TRUE(test_2.first->prev == nullptr && test_2.last->next == nullptr);
		ASSERT_TRUE(test_1.select(0) == test_2.select(0) && test_1.select(0) == record_1);
	    return true;
	}
	
	// PURPOSE: select() and search() work properly
	bool test3() {
		DronesManager test;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(101);
		DronesManager::DroneRecord record_null(0);

		ASSERT_TRUE(test.select(0) == record_null);

		test.insert_back(record_1);
		test.insert_back(record_2);
		test.insert_back(record_1);
		test.insert_back(record_2);

		ASSERT_TRUE(test.get_size() == 4);
	    ASSERT_TRUE(test.select(0) == record_1);
	    ASSERT_TRUE(test.select(test.get_size() + 10) == record_2);
        ASSERT_TRUE(test.search(record_1) == 0);
	    ASSERT_TRUE(test.search(record_2) == 1);
	    
		return true;
	}
	
	// PURPOSE: remove_front() and remove_back() on one-element list
	bool test4() {
		DronesManager test;
		DronesManager::DroneRecord record_test(100);

		ASSERT_TRUE(test.insert_front(record_test);
		ASSERT_TRUE(test.get_size() == 1);

		ASSERT_TRUE(test.remove_front());
		ASSERT_TRUE(test.empty());

		ASSERT_TRUE(test.first == nullptr && test.last == nullptr);

		ASSERT_TRUE(test.insert_front(record_test));
		ASSERT_TRUE(test.get_size() == 1);

		ASSERT_TRUE(test.remove_back());
		ASSERT_TRUE(test).empty());

		ASSERT_TRUE(test).first == nullptr && test.last == nullptr);
		return true;
	    return false;
	}
	
	// PURPOSE: replace() and reverse_list() work properly
	bool test5() {
		DronesManager test;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(101);
		DronesManager::DroneRecord record_3(102);

		test.insert_back(record_1);
		test.insert_back(record_2);
		test.insert_back(record_3);

		ASSERT_TRUE(test.select(0) == record_1);

		ASSERT_TRUE(test.replace(0, record_2));
		ASSERT_TRUE(test.select(0) == record_2);

		ASSERT_TRUE(test.replace(1, record_1));
		ASSERT_TRUE(test.select(1) == record_1);

		ASSERT_TRUE(test.reverse_list());
		ASSERT_TRUE(test.select(0) == record_3);
		ASSERT_TRUE(test.select(1) == record_1);
		ASSERT_TRUE(test.select(2) == record_2);

		return true;
	}
	
	// PURPOSE: insert_front() keeps moving elements forward
	bool test6() {
		DronesManager test;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(101);

		ASSERT_TRUE(test.insert_front(record_2));
		ASSERT_TRUE(test.get_size() == 1);
		ASSERT_TRUE(test.insert_front(record_1));
		ASSERT_TRUE(test.get_size() == 2);
		ASSERT_TRUE(test.select(0) == record_1);
		ASSERT_TRUE(test.select(1) == record_2);

		return true;
	}
	
	// PURPOSE: inserting at different positions in the list
	bool test7() {
		DronesManager test;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(101);

		ASSERT_TRUE(test.insert(record_1, 0));
		ASSERT_TRUE(test.insert(record_1, 1));
		ASSERT_TRUE(test.get_size() == 2);
		ASSERT_TRUE(test.insert(record_2, 2));
		ASSERT_TRUE(test.get_size() == 3);

		return true;
	}
	
	// PURPOSE: try to remove too many elements, then add a few elements
	bool test8() {
		DronesManager test;
		DronesManager::DroneRecord record_1(100);

		test.insert_front(record_1);
		test.insert_front(record_1);
	    
		ASSERT_TRUE(test.remove(0));
		ASSERT_TRUE(test.remove(0));
		ASSERT_FALSE(test.remove(0));

		ASSERT_TRUE(test.insert(record_1, 0));
		ASSERT_TRUE(test.insert(record_1, 0));
		ASSERT_TRUE(test.get_size() == 2)
	    return true;
	}
	
	// PURPOSE: lots of inserts and deletes, some of them invalid
	bool test9() {
		DronesManager test;
		DronesManager::DroneRecord record_test(100);

		ASSERT_FALSE(test.remove(0))
		ASSERT_TRUE(test.insert(record_test, 0));
		ASSERT_TRUE(test.insert(record_test, 0));
		ASSERT_TRUE(test.insert(record_test, 0));
		ASSERT_TRUE(test.insert(record_test, 0));
		ASSERT_TRUE(test.remove(0))
		ASSERT_TRUE(test.remove(3))
		ASSERT_FALSE(test.remove(100))
		ASSERT_TRUE(test.get_size() == 2)
	    return true;
	}    
	    	
	// PURPOSE: inserts into an unsorted list, then sort the list
	bool test10() {
		DronesManagerSorted test;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(99);
		DronesManager::DroneRecord record_3(101);

		test.insert_front(record_1);
		test.insert_front(record_2);
		test.insert_front(record_3);
		test.sort_asc();

        ASSERT_TRUE(test.select(0).droneID == 99);
        ASSERT_TRUE(test.select(1).droneID == 100);
        ASSERT_TRUE(test.select(2).droneID == 101);
	   	return true;
	}  
	
	// PURPOSE: insert and remove into sorted manager in ascending order
	bool test11() {
		DronesManagerSorted test;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(99);
		DronesManager::DroneRecord record_3(102);

		test.insert_front(record_1);
		test.insert_front(record_2);
		test.insert_front(record_3);
		test.sort_asc();
		test.insert_sorted_asc(DronesManager::DroneRecord(101));

        ASSERT_TRUE(test.select(2).droneID == 101);
	   	return true;	
	}
	
	// PURPOSE: insert and remove into sorted manager in descending order
	bool test12() {
		DronesManagerSorted test;
		DronesManager::DroneRecord record_1(100);
		DronesManager::DroneRecord record_2(99);
		DronesManager::DroneRecord record_3(102);

		test.insert_front(record_1);
		test.insert_front(record_2);
		test.insert_front(record_3);
		test.sort_desc();
		test.insert_sorted_desc(DronesManager::DroneRecord(101));

        ASSERT_TRUE(test.select(1).droneID == 101);
	   	return true;	
	}  
};

#endif
