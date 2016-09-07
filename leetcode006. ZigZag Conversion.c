/* simple simulation algorithm
 * we cann`t make sure the size of the string, 
 * so it had better to storage in vector.
 * show[] to buffer the new order of the string 
 */
class Solution {
public:
    string convert(string s, int numRows) {
     string result;
     vector<char> show[numRows];
     for(int index=0;index<s.size();)   //divide into two parts
     {
         for(int i=0;i<numRows;i++)     //simple row full storage
         {
             show[i].push_back(s[index++]);
             if(index==s.size())break;
         }
         for(int i=1;i<=numRows-2;i++)  //middle row only only one char storaged
         {
             for(int j=numRows-1;j>=0;j--)
             {
                 if(i+j==numRows-1)show[j].push_back(s[index++]);
                 if(index==s.size())break;
             }
             if(index==s.size())break;
         }
     }
     for(int i=0;i<numRows;i++)
     {
         for(int j=0;j<show[i].size();j++)result+=show[i][j];
     }
     return result;
    }
};
