Algo Insert ( A, N, item, size, pos)

if ( N == 0 ) then
    A[0] = item
    N <- 1
    Display "Element is inserted at 1st index"
else 
    if ( pos > N + 1 or pos >= size + 1)
        Display "Invalid pos"
    else
        for (i = N; i >= pos; i--)
            A[i] = A[i - 1]
        A[pos - 1] = item
        N <- N + 1            
Stop & Exit



