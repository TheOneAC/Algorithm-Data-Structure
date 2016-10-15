/*  O(lgn)
 * to adust the full heap, it must be called n/2 times
 * the complete complexity is O(nlgn)
 *  max heap adjust
typedef struct node{
	T value;
	int l;
	int r;
}Ttpe;
*/
template <typename T>
void max_heap(vector<T>&he, int index){
	int  l = he[i]->left;
	int  r = he[i]->right;
	int large  = index;
	if( l <= he.size() && he[l] > he[index])
		large = l;
	if( r <= he.size() && he[r] > he[index])
		large = r;
	if( large != index)
	{
		swap(he[index], he[large]);
		max_heap(he, large);
	}
}
// min heap
template <typename T>
void min_heap(vector<T>&he, int index){
	int  l = he[i]->left;
	int  r = he[i]->right;
	int min  = index;
	if( l <= he.size() && he[l] < he[index])
		min = l;
	if( r <= he.size() && he[r] > he[index])
		min = r;
	if( min != index)
	{
		swap(he[index], he[min]);
		max_heap(he, min);
	}
}
// iterative
void min_heap(vector<T>&he, int index){
	while(index < he.size()/2){ 
	// all the node range larger than size/2 is leaf , when the node storage in sieres
		int  l = he[i]->left;
		int  r = he[i]->right;
		int min  = index;
		if( l <= he.size() && he[l] < he[index])
			min = l;
		if( r <= he.size() && he[r] > he[index])
			min = r;
		if( min != index)
		{
			swap(he[index], he[min]);
			index = min;
		}
	}
	
}
/* adjust an array to a heap
 * build a heap by adjust
 * 
 ********build heap by this way , complexity is O(n)**************
 * so it is linear time complexity to build heap
 */
for( int index = he.szie()/2, index>= 0; index--){
	max_heap(he, i)
}
/*
 * heap sort
 */
void  heap_sort(vector<T>&he){ // count from 1???
	for(int i = he.size(), i>0, i-- ){
		swap(he[i],he[0]);
		he.erase(he.end()-1);
		max_heap(he,0);//call adjust
	}
}
/*
 * priority queue
 */
 extract the root of heap
 swap(root ,tail)
 size --
 heap adjust down

