/*
 * O(n)
 * template
 */ 
template <typename T>
vector<T> findmaxsubarray(vector<T> datalist)
{
    vector<T> subArray;
    T sum = datalist.at(0);
    T tempSum = 0;
    int index = 0;
    int start = 0, end = 0;
 
    for (index = 0; index < datalist.size(); index++)
    {
        tempSum += datalist.at(index);
 
        if (tempSum < 0)
        {
            tempSum = datalist.at(index);
            start = index;
            end = start;
            subArray.clear();
        }//end if
 
        if (tempSum > sum)
        {
            sum = tempSum;
            end = index;
        }//end if
    }//end loop
 
    for (int i = start; i <= end; i++)
        subArray.push_back(datalist.at(i));
 
    return subArray;
}//end finction: Finding subarray.
