#include<bits/stdc++.h>
using namespace std;

void heapify(vector<int> &heap, int curr, int size)
{
    int largest = curr;
    int l = 2*curr + 1;
    int r = 2*curr + 2;

    if(heap[largest]<heap[l] && l<size)
    largest = l;

    if(heap[largest]<heap[r] && r<size)
    largest = r;

    if(largest != curr)
    {
        int temp = heap[largest];
        heap[largest] = heap[curr];
        heap[curr] = temp;

        heapify(heap,largest,size);
    }
}

void heapsort(vector<int> &heap)
{
    for (int i = heap.size()/2 - 1; i >= 0 ; i--)
    heapify(heap,i,heap.size());

    for (int i = heap.size() - 1; i > 0 ; i--)
    {
        int temp = heap[i];
        heap[i] = heap[0];
        heap[0] = temp;

        heapify(heap,0,i);
    }
    
    
}
int main()
{
    int n;
    cin>>n;
    vector<int>heap(n);

    for (int i = 0; i < n; i++)
    {
        cin>>heap.at(i);
    }
    heapsort(heap);
    for (int i = 0; i < n; i++)
    {
        cout<<heap.at(i)<<endl;
    }
    
    
    return 0;
}