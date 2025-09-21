
import java.util.ArrayList;

// Node class to be used in hash map implementation
class MapNode<K,V> {
K key;
V value;
MapNode<K,V> next; // linked list node with data of key and value pair and next;
MapNode(K key, V value){
	this.key = key;
	this.value = value;
}
}

public class HashMap<K,V>{
ArrayList<MapNode<K,V>> buckets;
int count;
int numBucket;
HashMap(){
	buckets = new ArrayList<>();
	numBucket = 5;
	for(int i = 0; i< numBucket; i++) {
		buckets.add(null);
	}
}

private int HashCode(K key) {
	int hc = key.hashCode();
	int bucketIndex = hc % numBucket;
	return bucketIndex;
}


public void insert(K key, V value) {
	int BucketIndex = HashCode(key);
	// get the linked list at the bucketIndex // linked lists are already
	// initialized in all the index with null
	MapNode<K,V> head = buckets.get(BucketIndex);

	while (head != null) {
		// If we already have the key we just need to check if key is already present
		// and just update the value and return;
		if (head.key.equals(key)) {
			head.value = value;
			return;
		}

		head = head.next;

	}
	head = buckets.get(BucketIndex);

	// if we dont found the key we have to mkae a new node and attach it to the prev
	// head and update the array list index with new head.
	MapNode<K, V> newNode = new MapNode<>(key, value);
	newNode.next = head;
	buckets.set(BucketIndex, newNode);
	count++;
	
	double loadFactor = loadfactor();
	if(loadFactor>= 0.7) {
		rehash();
	}
	
}
public double loadfactor() {
	return (1.0 * count)/numBucket;
}
private void rehash() {
	
	ArrayList<MapNode<K, V>> temp = buckets;
	buckets = new ArrayList<>();
	for(int i = 0; i < 2*numBucket; i++) {
		buckets.add(null);
	}
	count = 0;
	numBucket = numBucket*2;
	for(int i = 0 ; i < temp.size(); i++) {
		MapNode<K, V> head = temp.get(i);
		while(head != null) {
			K key = head.key;
			V value = head.value;
			insert(key,value);
			
			head = head.next;
			
		}
	}
	
}


public V getValue(K key) {
	int BucketIndex = HashCode(key);

	MapNode<K, V> head = buckets.get(BucketIndex);

	while (head != null) {
		
		if (head.key.equals(key)) {
			
			return head.value;
		}

		head = head.next;

	}return null;
}
public V removeKey(K key) {
	int BucketIndex = HashCode(key);

	MapNode<K, V> head = buckets.get(BucketIndex);
if(head.key.equals(key)) {
	buckets.set(BucketIndex, head.next);
	count --;
	return head.value;
}
	while (head.next != null) {
		
		if (head.next.key.equals(key)) {
			head.next = head.next.next;
			count--;
			return head.next.value;
		}

		head = head.next;

	}
	return null;
}
}
