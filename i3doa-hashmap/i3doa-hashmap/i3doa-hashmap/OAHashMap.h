	#pragma once
	#include "OAHashMapException.h"

	template<typename KeyType, typename ValueType>
	class OAHashMap
	{
	public:

		// ==========================================================================================
		// NAME:	OAHashMap (constructor)
		// POST:	Map is of size 's'. Hash function set to 'h'
		// ==========================================================================================
		OAHashMap(const int s, int(*h)(KeyType, int))
			: hash(h), mapSize(s), nEntriesUsed(0)
		{
			map = new MapEntry[mapSize];
		}

		// ==========================================================================================
		// NAME:	search(key)
		// POST:	If 'key' is found in the map, 'value' is set to the corresponding value and
		//			true is returned. Otherwise, false is returned.
		// ==========================================================================================
		bool search(const KeyType& key, ValueType* value)
		{
			int index = findIndex(key);

			if (index == KEY_NOT_FOUND) return false;

			*value = map[index].value;
			return true;
		}

		// ==========================================================================================
		// NAME:	insert(key, value)
		// PRE:		Map is not full
		// POST:	[key, value] is in map
		// ==========================================================================================
		void insert(const KeyType& key, const ValueType& val)
		{
			int index, hashIndex;

			if (nEntriesUsed == mapSize) throw OAHashMapException("Map is full");

			index = hashIndex = hash(key, mapSize);

			int nProbes = 0;

			while (map[index].state == MapEntry::AddressState::OCCUPIED)
			{
				if (map[index].key == key)
				{
					// Key is in map - update corresponding value and return
					map[index].value = val;
					return;
				}
				index = (hashIndex + probe(++nProbes)) % mapSize;	// probing
			}

			// Open address found - insert key
			map[index].key = key;
			map[index].value = val;
			map[index].state = MapEntry::AddressState::OCCUPIED;

			++nEntriesUsed;
		}

		// ==========================================================================================
		// NAME:	remove()
		// POST:	Entry with key = key is not in map
		// ==========================================================================================
		void remove(const KeyType& key)
		{
			int index;

			if ((index = findIndex(key)) == KEY_NOT_FOUND) return;

			map[index].state = MapEntry::AddressState::PREV_USED;
		
			--nEntriesUsed;
		}

		// ==========================================================================================
		// NAME:	getLoadFactor()
		// POST:	The load factor is returned
		// ==========================================================================================
		double getLoadFactor() const
		{
			return static_cast<double>(nEntriesUsed) / mapSize;
		}

		// Default Hash function, always returns index 0
		static int defaultHash(KeyType k, int map_size) {
			return 0;
		}

	private:
		const int KEY_NOT_FOUND = -1;

		// Function pointer to the hash function
		int (*hash)(KeyType, int);

		// Internal class to hold map entries
		class MapEntry
		{
		public:
			enum class AddressState
			{
				OCCUPIED,
				PREV_USED,
				NEVER_USED
			};

			MapEntry(const KeyType& k = KeyType(), const ValueType& v = ValueType())
				: key(k), value(v), state(AddressState::NEVER_USED) {}

			KeyType key;
			ValueType value;
			AddressState state;
		};

		// ==========================================================================================
		// NAME:	findIndex()
		// POST:	index of the key is returned, or -1 if key is not found
		// ==========================================================================================
		int findIndex(const KeyType& key)
		{
			/*Use Adresse State PREV_USED and NEVER_USED to determine if af Key is even in the map.
			If search for a given Key hits a NEVER_USED the key is not in the given map and should return -1*/
			
			/* First stop is to calculate the hashIndex*/
			int index, hashIndex;

			index = hashIndex = hash(key,mapSize);

			/*Now, check the given map index adressestate 
			- if OCCUPIED check if the key at the index matches our key. If not, start probing until match is found or index
			with adressestate NEVER_USED
			- if NEVER_USED, this key is not in the map
			- if PREV_USED, start probing and for each prob check if the key at the new index matches with our key.
			*/
			if (map[hashIndex].state == MapEntry::AddressState::NEVER_USED)
			{
				return KEY_NOT_FOUND;
			}

			if (map[hashIndex].state == MapEntry::AddressState::OCCUPIED)
			{
				if (map[hashIndex].key == key)
				{
					// Key is in map - return index
					return hashIndex;
				}

				int nProbes = 0;

				index = (hashIndex + probe(++nProbes)) % mapSize;	// start probing

				while (map[index].state == MapEntry::AddressState::OCCUPIED || map[index].state == MapEntry::AddressState::PREV_USED)
				{
					if (map[index].key == key)
					{
						// Key is in map - return index
						return hashIndex;
					}
					index = (hashIndex + probe(++nProbes)) % mapSize;	// probing

					/*Map as been fully traversed, only occupied and prev used index-states*/
					if (nProbes == mapSize)
					{
						return KEY_NOT_FOUND;
					}
				}
			}

			if (map[index].state == MapEntry::AddressState::PREV_USED)
			{
				int nProbes = 0;

				index = (hashIndex + probe(++nProbes)) % mapSize;	// start probing

				while (map[index].state == MapEntry::AddressState::OCCUPIED || map[index].state == MapEntry::AddressState::PREV_USED)
				{
					if (map[index].key == key)
					{
						// Key is in map - return index
						return hashIndex;
					}
					index = (hashIndex + probe(++nProbes)) % mapSize;	// probing

					/*Map as been fully traversed, only occupied and prev used index-states*/
					if (nProbes == mapSize)
					{
						return KEY_NOT_FOUND;
					}
				}
			}
			return KEY_NOT_FOUND;
		}

		// =========================================================================================
		// NAME: probe
		// PRE: i>0
		// POST: The probing offset for probe i is returned
		// =========================================================================================
		int probe(int i) const
		{
			return i;
		}

		MapEntry* map;
		int mapSize; 
		int nEntriesUsed;
	};