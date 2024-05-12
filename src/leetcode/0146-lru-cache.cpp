#include <gtest/gtest.h>

#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
	explicit LRUCache(int capacity)
		: N(capacity)
	{
	}

	int get(int key)
	{
		if (key2kv.contains(key)) {
			auto iter = key2kv[key];
			auto [k, v] = *iter;
			storage.erase(iter);
			storage.emplace_front(k, v);
			key2kv[k] = storage.begin();
			return v;
		}
		return -1;
	}

	void put(int key, int value)
	{
		if (key2kv.contains(key)) {
			auto iter = key2kv[key];
			storage.erase(iter);
			storage.emplace_front(key, value);
			key2kv[key] = storage.begin();
		} else if (storage.size() < N) {
			storage.emplace_front(key, value);
			key2kv[key] = storage.begin();
		} else {
			evict();
			storage.emplace_front(key, value);
			key2kv[key] = storage.begin();
		}
	}

	void evict()
	{
		// remove the LRU item from the cache
		auto [key, value] = storage.back();
		assert(key2kv.erase(key));
		storage.pop_back();
	}

private:
	int const N;
	list<pair<int, int>> storage;
	unordered_map<int, list<pair<int, int>>::iterator> key2kv;
};

TEST(LC0146, Example1)
{
	LRUCache c(2);
	c.put(1, 1);
	c.put(2, 2);
	EXPECT_EQ(c.get(1), 1);
	c.put(3, 3);
	EXPECT_EQ(c.get(2), -1);
	c.put(4, 4);
	EXPECT_EQ(c.get(1), -1);
	EXPECT_EQ(c.get(3), 3);
	EXPECT_EQ(c.get(4), 4);
}

TEST(LC0146, FailingCase1)
{
	LRUCache c(2);
	c.put(1, 0);
	c.put(2, 2);
	EXPECT_EQ(c.get(1), 0);
	c.put(3, 3);
	EXPECT_EQ(c.get(2), -1);
	c.put(3, 3);
	EXPECT_EQ(c.get(2), -1);
	c.put(4, 4);
	EXPECT_EQ(c.get(1), -1);
	EXPECT_EQ(c.get(3), 3);
	EXPECT_EQ(c.get(4), 4);
}