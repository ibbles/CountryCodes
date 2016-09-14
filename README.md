# CountryCodes

## Problem description

Every now and then some of my peers and I come up with random programming
challenges. This time the task was to write the fastest country code finder.
That is, given a list of country codes and a collection of phone numbers,
determine which country each phone number belongs to.

The country code is always the first few digits of the phone number. This is a
type of string matching problem where we want to find the country code that is
equal to the first few digits of the phone number.

The list of country codes used can be found at http://country.io/phone.json.


## Strategies

A few observations on the problem. Both the country codes and the phone numbers
are short. There are many string searching algorithms, but the ones I know about
are designed for finding a search string somewhere in a long text. I this case
we know where the sought string should be, at the very start. And we have many
strings to search for. We also have lots of phone numbers in which to search for
the country code.

An important observation is that the the set of country codes is constant
throughout the application's lifetime. This means that whatever work we can do
at startup to speed up the queries is worth it since the cost of the initial
work will be amortized by the large number of queries. Within reason of course.

### Linear search
There are a number of ways to approach this. Arguably, the simplest way is to
keep all the country codes as a list of strings and for each given phone number
loop over the country codes until a match is found. This works, but is probably
not very fast. It does `O(c*d*p)` digit comparisons where `c` is the number of
country codes, `d` is the average number of digits in a country code and `p` is
the number of phone numbers tested.

### Binary search
Whenever we see a linear search through a collection of sortable elements we
should consider sorting the data and replace the linear search with a binary
one. This reduces the number of digit comparisons from `O(c*d*p)` to
`O(log(c)*d*p)`. This is better, when testing a given phone number a whole slew
of country codes is not even looked at anymore. The `d*p` part may seem scary,
but remember that `d` is small and we do need to look at every digit of a country
code in order to accept or reject a potential match. I have not been able to
find a way around that.

### Hash table
While `log(k)` isn't too bad, we can do better still. A common way to do
constant time lookups is to use hashing. We insert each country code into a hash
table and for every given phone number we first test if the single digit prefix
substring can be found in the hash, then we test the leading two digits, and
then three and so on until we find a country code or the leading substring is
longer than the longest country code. This algorithm is `O(d*p)` digit
comparisons.

### Trie
I have not been able to find or come up with something better than `O(d*p)`, but
I have found an alternative data structure that gives the same `O`. A
[Trie](https://en.wikipedia.org/wiki/Trie), also called a prefix tree, is a tree
used to store data where the location in the tree, i.e., path from the root to
the containing node, defines the key that the data it associated with. An
example is in order.

Assume that we are given the following country codes:

 - "BD": "880"
 - "BE": "32"
 - "BF": "226"
 - "BG": "359"
 - "BH": "8"


This is the resulting trie:

![](/images/trie_ex.png "")

A few things to note. First, the root node contains "^", which is used to denote
the start of a string. Secondly, data may appear not only in the leave nodes,
but in internal nodes as well. Third, some nodes doesn't contain any data. They
exist only to define the path to the data contained in the node's children.
Lastly, to find the country code of a number we walk down the trie as dictated
by the first few digits of the number and stop as soon as we find a non-empty
node.

### A note on caches

Caches are all the rage these days. The ever widening processor-memory
performance gap is making memory accesses more and more expensive in terms of
CPU cycles. This has made cache-friendly access patterns more important than
ever. I will discuss the memory access patterns for each implementation strategy
later in this text.

However, in addition to the access patterns, the size of the working set must be
taken into account as well. The input file, http://country.io/phone.json, is 3.3
KB and it is reasonable to believe that storing the data in memory will use a
comparable amount of space. The CPU I'll be testing on has 16 KB of L1 data
cache per core. This means that we can put the entire data set into L1 cache and
still have plenty of room left for whatever acceleration structure we choose.


## Assumptions



## Implementing a trie




[//]: # (Comment.)
