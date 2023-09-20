# HASHMAPS

LL - O(n)
BST - O(logn)
Hashmap - O(1) (bucket array + Good hash code + low LF)

## Hash Maps: What They Are and Why We Use Them

ordered map - bst : insertion and searching in logn and deletion in 1.
unordered map - hash table = avg 1 for everything

**What is a Hash Map?**
- A hash map, also known as an unordered map in C++, is a data structure that stores **key-value pairs**.
- It allows for efficient storage and retrieval of values based on their associated keys.
- Hash maps use a technique called hashing to map keys to indices in an array, enabling quick access to values.

**Why Do We Use Hash Maps?**

1. **Fast Access Time:** Hash maps provide fast access to values. Retrieval time is usually constant on average (O(1)), making them ideal for applications where quick data access is crucial.

2. **Efficient Storage:** Hash maps are memory-efficient because they store data in an array-like structure. They don't require additional memory for keys or indices, which can be advantageous in resource-constrained environments.

3. **Flexibility:** Hash maps are versatile and can store various data types as values, including user-defined types.

4. **Associative Data Storage:** They excel at associating data based on keys. For example, you can use hash maps to store information about students (values) associated with their student IDs (keys).

5. **Efficient Key Search:** Hash maps can quickly locate specific keys, making them useful for implementing dictionaries, caches, or lookup tables.

6. **Constant-Time Average Complexity:** While hash map operations may have worst-case time complexities, such as O(N) in the event of hash collisions, they offer average-case constant time complexity (O(1)) for insertion, deletion, and lookup operations.

7. **Application in Algorithms:** Hash maps are vital in algorithmic problem-solving. They help optimize performance by storing intermediate results, reducing the need for redundant calculations.

8. **Frequency Counting:** Hash maps are commonly used for counting the frequency of elements in a collection. For example, you can count the occurrences of words in a text document.

9. **Memoization:** In dynamic programming and recursive algorithms, hash maps can be employed for memoization. Storing previously computed results saves time by preventing redundant computations.

10. **Data Processing:** Hash maps play a crucial role in data processing tasks, such as data aggregation, grouping, and summarization.


**Unordered map - random order print, but for map (ordered map-implemented in BST) the order is reserved(order of insertion)**


**Basics of Unordered Map:**

**1. Include Header:**
   - To use unordered maps, include the `<unordered_map>` header.

**2. Declaration:**
   - Declare an unordered map as follows:
   ```cpp
   std::unordered_map<KeyType, ValueType> myMap;
   ```

**3. Insertion:**
   - Insert key-value pairs into the unordered map:
   ```cpp
   myMap[key] = value;
   OR
   pair<dt1,dt2> p = make_pair(dt1,dt2);
   pair<dt1,dt2> p("str",2);
   m.insert(p);
   ```
   **Only unique entries**

   **First time insertion->insertion.. after that all op r updation ex m["a"]=1; //insertion , m["a"]=2; //updation**

**4. Accessing Values:**
   - Retrieve values based on their keys:
   ```cpp
   value = myMap[key];
   cout<< myMap.at("key");
   cout<< myMap.at("Unknown key");  // Raises an exception key not found 
   cout<< myMap["Unkown key"]; // Outputs 0
   ```

**IMP NOTE:IF we try to access an key value which is not declared using map[key] syntax .. it will automatically create an entry for it with 0 corresponding value.. and now this wont give exception once we run it again**

**5. Checking Existence:**
   - Check if a key exists in the map:
   ```cpp
   if (myMap.count(key) > 0) {
       // Key exists in the map
       // present - 1
       // absent - 0
   }
   ```

**6. Erasing Elements:**
   - Remove elements from the map by key:
   ```cpp
   myMap.erase(key);
   ```

**7. Size and Empty:**
   - Get the number of elements in the map:
   ```cpp
   size_t size = myMap.size();
   ```

   - Check if the map is empty:
   ```cpp
   bool isEmpty = myMap.empty();
   ```

**Hashing and Hash Functions:**
- Unordered maps use a hash function to map keys to indices within the container.
- The default hash function is provided for standard types, but you can specify custom hash functions for user-defined types.

**Collision Handling:**
- Collisions occur when two keys hash to the same index.
- Unordered maps handle collisions using techniques like chaining (each index is a linked list of key-value pairs) or open addressing (probing for the next available slot).

**Iterating Over an Unordered Map:**
- Use iterators to traverse an unordered map:
```cpp
for (auto it = myMap.begin(); it != myMap.end(); ++it) {
    KeyType key = it->first;
    ValueType value = it->second;
    // Process key-value pair
}
for (auto it=m)
    cout<<it.first<<it.second;
// instead of using auto
unordered_map<string, int>::iterator it = m.begin();
it++; // to increment in while loop
```

**Advanced Usage:**

**1. Load Factor:**
   - The load factor is the ratio of the number of stored elements to the size of the hash table.
   - High load factors can lead to more collisions and performance issues.

**2. Custom Hash Functions:**
   - For user-defined types, you can specialize the `std::hash` template to provide custom hash functions.

**3. Bucket Size and Bucket Count:**
   - Each index in an unordered map is a "bucket" that can store multiple key-value pairs.
   - You can access the bucket size (number of pairs in a bucket) and bucket count (total number of buckets) using member functions like `bucket_count` and `bucket_size`.

**4. Performance:**
   - Unordered maps offer average-case O(1) time complexity for insertion, deletion, and lookup operations.
   - However, worst-case behavior can occur with hash collisions, leading to O(N) time complexity.

**5. Thread Safety:**
   - By default, unordered maps are not thread-safe.
   - For thread-safe usage, consider using synchronization mechanisms like `std::shared_mutex`.

**6. Resizing:**
   - Unordered maps automatically resize when the load factor exceeds a certain threshold. Resizing involves creating a larger array and rehashing all elements.

**7. Usage in Algorithms:**
   - Unordered maps are widely used in algorithms and data structures for memoization, frequency counting, and more.

**8. Performance Optimizations:**
   - To optimize unordered map performance, consider tuning the load factor, selecting an efficient hash function, and avoiding unnecessary resizing.

Unordered maps are versatile and efficient data structures for storing and retrieving key-value pairs. Understanding hash functions, collision handling, and load factors is essential for effectively using unordered maps in various applications, from basic key-value storage to advanced algorithmic problems.



## Bucket Array in Hash Maps

**Basically an array, they store value corresponding to index (mapped through hash function)**

**Introduction to Bucket Array:**
- A bucket array, also known as a bucket or a bucket container, is a key component of hash maps (unordered maps) in C++ and many other programming languages.
- It's used to handle collisions and efficiently store multiple key-value pairs that hash to the same index within the hash map.

**Illustration of a Bucket Array:**
- Imagine a hash map with an array of buckets. Each bucket is like a small container that can hold multiple key-value pairs. Here's an illustration:

```
[ Bucket 0 ] -> Key-Value Pair 1 -> Key-Value Pair 2 -> ...
[ Bucket 1 ] -> Key-Value Pair 3 -> ...
[ Bucket 2 ] -> ...
...
[ Bucket n ] -> ...
```

**Working Principle:**
- When two or more keys hash to the same index (collision), the bucket array comes into play.
- Instead of overwriting the previous key-value pair, the new pair is appended to the corresponding bucket.
- Each bucket can be implemented as a linked list, a vector, or another data structure that allows efficient insertion and retrieval of key-value pairs.

**Advantages of Using Bucket Arrays:**

1. **Collision Handling:** Bucket arrays are essential for handling hash collisions. They enable multiple key-value pairs to coexist at the same index.

2. **Memory Efficiency:** Since a bucket array only occupies space when there are collisions, it doesn't waste memory when most indices are unique.

3. **Dynamic Sizing:** Hash maps can dynamically resize their bucket array when necessary, ensuring efficient storage even as the number of key-value pairs increases.

**Bucket Array in Practice:**
- Here's how you can visualize the implementation of a bucket array in a hash map:

```cpp
std::unordered_map<KeyType, ValueType> myMap;

// Hash map using a bucket array:
// Each index in the array can hold multiple key-value pairs.
myMap[0] -> Key-Value Pair 1 -> Key-Value Pair 2 -> ...
myMap[1] -> Key-Value Pair 3 -> ...
myMap[2] -> ...
...
myMap[n] -> ...
```

**Bucket Array and Performance:**
- The efficiency of a bucket array depends on the data structure chosen to implement it (linked list, vector, etc.).
- In practice, when a bucket array becomes too full, it may be resized to maintain good performance. Resizing involves creating a larger array and redistributing key-value pairs to new buckets.

**When to Use Bucket Arrays:**
- Bucket arrays are a fundamental component of hash maps and are used automatically by hash map implementations.
- You don't typically need to interact with bucket arrays directly; instead, you work with the hash map's API to insert, retrieve, and manipulate key-value pairs.

**Conclusion:**
- Bucket arrays are a critical part of hash maps, enabling them to handle hash collisions and efficiently store multiple key-value pairs at the same index. Understanding how bucket arrays work under the hood can help you appreciate the efficiency and versatility of hash maps in various programming scenarios.


**Hash Function in Hash Maps**

**Introduction to Hash Functions:**
- A hash function is a fundamental component of hash maps (unordered maps) in C++ and other programming languages.
- It plays a crucial role in converting keys into indices within the hash map's array, allowing for efficient storage and retrieval of key-value pairs.

**Illustration of a Hash Map with Hash Function:**
- Imagine a hash map with an array of buckets, where each bucket can hold multiple key-value pairs. The hash function determines which bucket to use for each key:

```
Hash Map Array:
[ Bucket 0 ] -> Key-Value Pair 1 -> Key-Value Pair 2 -> ...
[ Bucket 1 ] -> Key-Value Pair 3 -> ...
[ Bucket 2 ] -> ...
...
[ Bucket n ] -> ...

Hash Function:
     |
     v
   [ Hash ]
     |
     v
[ Bucket Index ]
```

**Working Principle of a Hash Function:**
- A hash function takes a key as input and produces a hash code (also called a hash value).
- The hash code is an integer that represents the key.
- The hash code is then used to determine the index (bucket) in the hash map's array where the key-value pair should be stored or retrieved.

**Hash Code:**
- Convert the data type(say string) to an int (same each time)
- The hash code is a numerical representation of the key's content.
- It should be computed in such a way that the same key always produces the same hash code.
- For different keys, the hash codes should be as distinct as possible to minimize collisions (two keys mapping to the same index).

**Compression Function:**
- After generating the hash code, a compression function is often applied to reduce the hash code to a valid index within the array's bounds.
- The compression function maps the hash code to a range of valid indices, typically between 0 and the size of the array minus one.
- The goal is to evenly distribute the key-value pairs across the available buckets.

**Example of a Hash Function:**
- Suppose we have a hash map with an array of 10 buckets, and our hash function is a simple modulo operation:

```
Hash Code: 42
Compression Function: 42 % 10 = 2
Bucket Index: 2
```

- Here, the hash code 42 is compressed using the modulo operation to map it to bucket index 2.

**Properties of a Good Hash Function:**
- **Deterministic:** Given the same input key, a hash function should produce the same hash code every time.
- **Uniform Distribution:** Hash codes should be evenly distributed across the available indices to reduce collisions.
- **Efficiency:** Hash functions should be computationally efficient to avoid performance bottlenecks.
- **Avalanche Effect:** A small change in the input should result in a significantly different hash code.
- **Minimal Collisions:** Hash functions should minimize the likelihood of two different keys producing the same hash code (collision-resistant).

**Common Hash Functions:**
- Many programming languages provide default hash functions for standard data types like integers, strings, and objects.
- For user-defined types, you can customize hash functions by specializing the `std::hash` template.


## Hash Code in Hash Maps: Understanding, Examples, and Collision Prevention

**Introduction to Hash Code:**
- In hash maps (unordered maps), a hash code is a crucial component used to convert keys into indices within the map's array.
- Hash codes are numerical representations of the keys' content, allowing for efficient storage and retrieval of key-value pairs.

**Why Use Hash Codes?**
- Hash codes enable the distribution of key-value pairs across the map's array, reducing collisions (multiple keys mapping to the same index) and optimizing data retrieval.

**Types of Hash Codes:**
1. **Identity Hash Code:** 
   - For integral and floating-point types, the identity hash code is often used. It maps the value directly to an index.
   - Example:
     - For `int key = 42`, the identity hash code is also `42`.
   
2. **String Hash Code:** 
   - For strings, a common approach is to use a **polynomial rolling hash function**.
   - Example:
     - For `"hello"`, the hash code might be `532923492`.
   
3. **Custom Hash Code (User-Defined Types):** 
   - User-defined types can have custom hash functions.
   - Example:
     - For a `Person` object with attributes `name` and `age`, a custom hash function could combine the hash codes of both attributes.

**Preventing Collisions:**

1. **Uniform Distribution:** A good hash code function produces hash codes that are uniformly distributed across the available indices in the map's array. This minimizes the chance of multiple keys colliding.

2. **Avalanche Effect:** Hash codes should exhibit the avalanche effect, meaning that a small change in the key should result in a significantly different hash code. This property helps avoid clustering of keys in the same buckets.

**Examples of Hash Codes for Different Data Types:**

1. **Integers (Identity Hash Code):**
   - Key: `42`
   - Identity hash code: `42`
   
2. **Floating-Point Numbers (Identity Hash Code):**
   - Key: `3.14`
   - Identity hash code: `3.14` (with precision considerations)
   
3. **Strings (Polynomial Rolling Hash Function):**
   - Key: `"hello"`
   - Hash code: `532923492`

4. **Custom Object (User-Defined Hash Function):**
   - Key: Custom object `Person` with attributes `name="Alice"` and `age=30`
   - Custom hash code function combines the hash codes of `name` and `age`.

**Pitfalls to Avoid:**

1. **Inadequate Hash Functions:** Poorly designed hash code functions can lead to hash collisions and reduced map performance.

2. **Non-Deterministic Hash Codes:** Hash codes should be deterministic; the same key should always produce the same hash code.

3. **Over-Hashing:** Overly complex hash functions can be computationally expensive and counterproductive.



# Collision Handling in Hash Maps: Open Hashing and Closed Addressing

**Introduction to Collision Handling:**
- Collision handling is a critical aspect of hash maps (unordered maps) that deals with the situation where multiple keys hash to the same index in the map's array.
- Collisions are common and must be addressed to ensure efficient storage and retrieval of key-value pairs.

**Why Collisions Occur:**
- Collisions occur when different keys produce the same hash code. This can happen due to the finite range of hash codes and variations in key inputs.

**Collision Handling Techniques:**

1. **Open Hashing (Separate Chaining):**
   - In open hashing, each bucket in the hash map's array is implemented as a linked list (or another data structure capable of holding multiple key-value pairs).
   - When a collision occurs, new key-value pairs are added to the linked list at the corresponding bucket.
   - Retrieval involves searching the linked list within the bucket for the specific key.
   - Open hashing is easy to implement and allows for efficient collision resolution but may lead to performance issues when the linked lists become too long.

 **THIS IS PRACTICAL APPROACH**
   **Illustration of Open Hashing:**
   ```
   Hash Map Array:
   [ Bucket 0 ] -> Key-Value Pair 1 -> Key-Value Pair 2 -> ...
   [ Bucket 1 ] -> Key-Value Pair 3 -> ...
   [ Bucket 2 ] -> ...
   ...
   [ Bucket n ] -> ...
   ```

2. **Closed Addressing (Open Addressing):**
   - In closed addressing, all key-value pairs are stored directly in the hash map's array.
   - When a collision occurs, the algorithm probes for the next available slot within the array.
   - This probing can take various forms, such as linear probing (check the next slot), quadratic probing (check slots with increasing gaps), or double hashing (use a second hash function for probing).
   - Closed addressing is memory-efficient but can be complex to implement. It may also lead to clustering and performance issues under high load factors.

   **Illustration of Closed Addressing (Linear Probing):**
   ```
   Hash Map Array:
   [ Key-Value Pair 1 ] -> Key-Value Pair 2 -> ...
   [ Key-Value Pair 3 ] -> ...
   [ Empty Slot ] -> ...
   ...
   [ Bucket n ] -> ...
   ```

   **Linear Probing**

   - H i (a) = h(a) + F i (a)
    i is subscript.. 

    Ex. 7th index collision detected: (here h(a) gave ans 7 and F i (a) is 0 .. (0th attempt))
    - Now F i (a) is 1 for 1 so it check 7+1 = 8th index
    - +2 and so on


    **Quadratic Probing**

   - H i (a) = h(a) + F i (a)
    i is subscript.. 

    Ex. 7th index collision detected: (here h(a) gave ans 7 and F i (a) is 0 .. (0th attempt))
    - Now F i (a) is 1^2 for 1 so it check 7+1 = 8th index
    - Now F i (a) is 2^2 for 2 = 4 ..so 7+4 = 11th index
    - and so on

    **Double Hashing**
    - Take any good function ex 3x^2 +13 or anything



**Collision Handling Strategies:**

- Both open hashing and closed addressing aim to resolve collisions effectively. The choice between them depends on the specific requirements of the application.

**Choosing the Right Collision Handling Method:**

1. **Open Hashing (Separate Chaining):**
   - Suitable when the number of key-value pairs and collisions is not too high.
   - Easy to implement and manage.
   - Efficient when linked lists are short.

2. **Closed Addressing (Open Addressing):**
   - More memory-efficient, as it doesn't involve additional data structures like linked lists.
   - Suitable for applications with a large number of key-value pairs and potential collisions.
   - Requires careful implementation of probing techniques to avoid clustering and performance issues.

**Collision Handling and Performance:**

- The efficiency of collision handling methods depends on factors like the quality of the hash function, the distribution of keys, and the load factor (the ratio of stored items to available buckets).
- To prevent performance issues, hash maps may automatically resize their arrays (rehashing) when the load factor exceeds a certain threshold.

**Conclusion:**
- Collision handling is a crucial aspect of hash maps, ensuring that multiple keys can efficiently coexist at the same index. Open hashing (separate chaining) and closed addressing (open addressing) are two common strategies, each with its strengths and weaknesses. Choosing the appropriate method depends on the specific application's requirements and expected usage patterns. Understanding collision handling techniques is essential for effective use of hash maps in various programming scenarios.


Certainly, let's break down the complexities for each operation and explain them using examples where relevant:

**1. Insertion (Insertion of a Key-Value Pair):**
- **Time Complexity (Average):** O(1)
  - Example: Inserting a key-value pair in a hash map that uses a string key.
  - Explanation: Hash maps typically use the key's hash code to determine the index where the key-value pair should be placed. The hash code calculation complexity is often O(K), where K is the size of the key (number of characters). However, since the number of words (N) is much larger than the size of a word (K), this becomes nearly constant time, which is why it's often approximated as O(1).

**2. Deletion (Removal of a Key-Value Pair):**
- **Time Complexity (Average):** O(1)
  - Example: Removing a key-value pair by its string key.
  - Explanation: Deletion in a hash map involves locating the key's position, which is determined by the hash code calculation. Similar to insertion, the hash code calculation complexity is O(K), but it's approximated as O(1) when N is significantly larger than K.

**3. Lookup (Retrieval of a Value by Key):**
- **Time Complexity (Average):** O(1)
  - Example: Retrieving the value associated with a string key.
  - Explanation: Hash maps use the key's hash code to quickly locate the corresponding value. The hash code calculation complexity is O(K), but it's treated as O(1) when N is much larger than K.

**4. Search (Checking if a Key Exists):**
- **Time Complexity (Average):** O(1)
  - Example: Determining if a string key exists in the hash map.
  - Explanation: Searching for a key's existence involves the same hash code calculation as lookup. With N >> K, it's considered O(1).

**5. Resizing:**
- **Time Complexity:** O(N)
  - Example: When the hash map needs to be resized due to increasing N.
  - Explanation: Resizing involves copying all key-value pairs into a new, larger array, which is a linear operation in terms of N.

**6. Iteration (Traversing All Key-Value Pairs):**
- **Time Complexity:** O(N)
  - Example: Iterating through all key-value pairs in the hash map.
  - Explanation: Since you must visit each pair once, the complexity is linear with respect to the number of key-value pairs, N.

**7. Memory Overhead (Space Efficiency):**
- Hash maps have a memory overhead due to data structures used for hashing, which is often small but can affect memory usage.

**8. Load Factor:**
- The load factor, N/K (N is the number of key-value pairs, K is the number of buckets or array size), helps manage collisions. A lower load factor generally reduces collisions and maintains efficient performance.

    **We Ensure N/B is < 0.7 -> Good hashing.. this basically means if 100 entries are coming we should atleast have 130 boxes/buckets**
    **when n increase .. we can increase b to bring LF down - WHEN WE INCREASE BUCKETS WE HAVE TO REHASH for everything**

**Good hash function + load factor<0.7 -> safe to say O(1)**

**Conclusion:**
- The complexities of hash map operations depend on factors like the size of the key, the quality of the hash function, and the relationship between N and K. In practice, hash map operations are often considered O(1) or nearly constant time when N >> K. Proper design and management of hash maps are crucial for ensuring their efficient performance.
