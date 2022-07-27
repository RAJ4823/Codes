1. ADT for Queue
/*
    *Instances : Queue is a collection of a elements in which insertion is done by one end called rear and deletion done by other one end called front.
     
    *Operation :
    !1) Enqueue() : Elements can be inserted into the queue by this Operation. Before performing this Operation we should check wether queue is full or not.

    !2) Dequeue() : Elemetns can be removed from queue using this Operation. Before performing this Operation we shoukd check wether queue is empty or not.

*/

2. ENQUEUE (inertion)
/*
    !Enqueue(Q,front, rear, ELEMENT, size)
    ?Q      : Queue
    ?front  : Pointing frontmost element in queue.
    ?rear   : Pointing last element in queue.
    ?size   : Size of Queue
    ?ELEMENT: Element which will be inserted.

    *Step 1 - Check if the Queue full or not.
    *Step 2 - IF Queue is full goto step 5
    *Step 3 - IF Queue is not full, increments rear by 1.
    *Step 4 - Add element into the Queue at which rear is pointing.
    *Step 5 - EXIT.


    !ALGORITHM
    ?STEP 1 - START
    ?Step 2 - IF REAR == SIZE - 1
        *PRINT "QUEUE IS OVERFLOW"
        *GO TO STEP 5
    ?Step 3 - IF FRONT = -1 and REAR = -1
        *SET FRONT <- 0 & REAR <- 0
        ?ELSE
        *SET REAR <- REAR + 1
    ?Step 4 - Q[REAR] = ELEMENT
    ?Step 5 - EXIT
*/

3. DEQUEUE (deletion)
/*
    !Dequeue(Q, front)
    ?Q      : Queue
    ?front  : Pointing frontmost element in queue.
    ?rear   : Pointing last element in queue.
    ?size   : Size of Queue
    ?ELEMENT: Element which will be inserted.

    *Step 1 - Check if the Queue full or not.
    *Step 2 - IF Queue is full goto step 5
    *Step 3 - IF Queue is not full, increments rear by 1.
    *Step 4 - Add element into the Queue at which rear is pointing.
    *Step 5 - EXIT.

    !ALGORITHM
    ?Step 1 - START
    ?Step 2 - IF FRONT == -1 or FRONT > REAR
        *PRINT "QUEUE IS UNDERFLOW"
        *GOTO STEP 6
    ?Step 3 - VAL <- QUEUE[FRONT]
    ?Step 4 - FRONT <- FRONT + 1
    ?Step 5 - PRINT "VAL"
    ?Step 6 - EXIT
*/

4. Circular Queue
/*
!A> Enqueue
    *First, we will check whether the Queue is full or not.
    *Initially the front and rear are set to -1. 
    *When we insert the first element in a Queue, front and rear both are set to 0.
    *When we insert a new element, the rear gets incremented.

    !ALGORITHM
    ?Step 1 - START
    ?Step 2 - IF (REAR+1)%SIZE == FRONT
        *PRINT "OVERFLOW"
        *GOTO STEP 5
    ?Step 3 - IF FRONT = -1 and REAR = -1
        *FRONT <- 0 
        *REAR <- 0
        ?ELSE
        *REAR <- (REAR + 1) % SIZE
    ?Step 4 - Q[REAR] <- ELEMENT
    ?Step 5 - EXIT

!B> Dequeue
    *First, we will check whether the Queue is empty or not. If the queue is empty, we cannot perform the dequeue operation.
    *When the element is deleted, the value of front gets decremented by 1.
    *If there is only one element left which is to be deleted, then the front and rear are reset to -1.

    ?Step 1 - START
    ?Step 2 - IF FRONT == -1
        *PRINT "UNDERFLOW "
        *GOTO STEP 6
    ?Step 3 - VAL <- Q[FRONT]
    ?Step 4 - IF FRONT == REAR
        *FRONT <- (-1)
        *REAR  <- (-1)
        ?ELSE
        *FRONT <- (FRONT + 1) % SIZE
    ?Step 5 - PRINT "DELETED ELEMENT = VAL"
    ?Step 6 - EXIT
*/