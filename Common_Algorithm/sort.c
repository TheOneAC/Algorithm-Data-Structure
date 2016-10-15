//pesecode
 count_sort(A,B,k){
 	for i =0 to k
 		c[i] = 0;
 	for i = 0 to A.length// hash rage
 		c[A[i]]++;
 	for i = 1 to k
 		c[i] = c[i-1]+ c[i];
 	for j = A.length to 0 // keep static
 		B[c[A[j]]] = A[j];
 		c[A[j]]--;
 }