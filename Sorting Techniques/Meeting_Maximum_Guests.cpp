//Consider a big party where a log register for guest’s entry and exit times is maintained. 
//Find the time at which there are maximum guests in the party. Note that entries in register are not in any order.
//which means arrival and departure arrays are not sorted. This problem is very similar to the platform problem 
//in greedy algorithm.
/*
An Efficient Solution is to use sorting n O(nLogn) time. The idea is to consider all events 
(all arrivals and exits) in sorted order. Once we have all events in sorted order, we can trace 
the number of guests at any time keeping track of guests that have arrived, but not exited.
The point is that it does not matter WHICH guest arrives or leaves(meaning the guest as an entity is not important which means
that we need not create a struct for preserving the arrival and departure of a particular guest). We just need to count
the number of maximum guests at the party at a time.
*/
// Program to find maximum guest at any time in a party
#include<iostream>
#include<algorithm>
using namespace std;

void findMaxGuests(int arrl[], int exit[], int n)
{
// Sort arrival and exit arrays
sort(arrl, arrl+n);
sort(exit, exit+n);
// guests_in indicates number of guests at a time
int guests_in = 1, max_guests = 1;//we assume the first guest has arrived
int i = 1, j = 0;//since first guest has arrived we check for arrival time of second guest and departure of the first
//departing guest who might not be the first arriving guest.
/*Note that at any index=k arr[k] <= dep[k] because a guest has to arrive before he leaves and obviously for every
guest arrival<departure. */
// Similar to merge in merge sort to process
// all events in sorted order
while (i < n && j < n)
{
	// If next event in sorted order is arrival,
	// increment count of guests
	if (arrl[i] <= exit[j])
	{
		guests_in++;
		i++; //increment index of arrival array
	}
	else // If event is exit, decrement count
	{ // of guests.
		guests_in--;
		j++;
	}
	max_guests=max(max_guests,guests_in);
}

cout << "Maximum Number of Guests = " << max_guests;
}
//Time Complexity: O(N*logN)
//Space Complexity: O(n+n) written in this way to emphasize the fact that merge process take O(m+n) space.
// Driver program to test above function
int main()
{
	int arrl[] = {1, 2, 10, 5, 5};
	int exit[] = {4, 5, 12, 9, 12};
	int n = sizeof(arrl)/sizeof(arrl[0]);
	findMaxGuests(arrl, exit, n);
	return 0;
}

