1. Selection sort :
/*
    !ALGORITHM
    *Step 1 − Set MIN to location 0
    *Step 2 − Search the minimum element in the list
    *Step 3 − Swap with value at location MIN
    *Step 4 − Increment MIN to point to next element
    *Step 5 − Repeat until list is sorted

    !PSUDO-CODE
    ?Step 1: FOR i = 1 TO n-1 REPEAT:
    ?Step 2: min <- arr[i]
    ?step 3: POS <- i
    ?step 4: FOR j = i+1 TO n-1 REPEAT:
                *IF arr[j] < min THEN
                    *min <- arr[j]
                    *POS <- j
                ![end of if]
            ![end of loop]
    ?step 5: SWAP arr[i] AND arr[POS]
            ![end of loop]
    ?step 6: END
*/

2. Insertion Sort :
/*
    !ALGOITHM
    *Step 1 − If it is the first element, it is already sorted. return 1;
    *Step 2 − Pick next element
    *Step 3 − Compare with all elements in the sorted sub-list
    *Step 4 − Shift all the elements in the sorted sub-list that is greater than the value to be sorted
    *Step 5 − Insert the value
    *Step 6 − Repeat until list is sorted

    !PSUDO-CODE
    ?INSERTION-SORT(A)
    ?FOR i = 1 to n
   	    *key ← A [i]
    	*j ← i – 1
  	    ?WHILE j > = 0 and A[j] > key
   		*A[j+1] ← A[j]
   		*j ← j – 1
   	    ?END WHILE 
   	    *A[j+1] = key
    ?END FOR LOOP
    ?END
*/

3. Quick Sort :
/*
    !PARTITION ALGO.
    *Step 1 − Choose the left-most index value has pivot
    *Step 2 − Take two variables to point left and right of the list excluding pivot
    *Step 3 − left points to the low index
    *Step 4 − right points to the high index
    *Step 5 − WHILE value at left is less than pivot, increament left by one
    *Step 6 − WHILE value at right is greater than pivot, decrement right by one
    *Step 7 − IF both step 5 and step 6 does not match swap values at left and right
    *Step 8 − IF left > right, swap value of left with pivot.

    !QUICK SORT ALGO.
    *Step 1 − Make the left-most index value pivot
    *Step 2 − partition the array using pivot value
    *Step 3 − quicksort left partition recursively
    *Step 4 − quicksort right partition recursively

    !PARTITION PSUDO-CODE
    ?FUNCTION PARTIION(A[], left, right)
        *PIVOT = A[left]
        *i = left + 1
        *j = right
    ?WHILE i < j do
        *WHILE A[i] < PIVOT do
            *i++
        *END WHILE

        *WHILE A[j] > PIVOT do
            *j--
		*END WHILE

        *IF i < j THEN
            *SWAP A[i] and A[j]
        *END IF
    ?END WHILE
        *SWAP A[j] and A[left]
        *RETURN j
	?END FUNCTION


    !QUICK SORT PSUDO-CODE
    ?FUNCTION QUICKSORT(A[], left, right) 
    ?WHILE LEFT < RIGHT    
        *mid = partitionFunc(A[], left, right)
        *QUICKSORT(A[], left, mid-1)
        *QUICKSORT(A[], mid+1,right)    
    ?END WHILE		
    ?END FUNCTION
*/