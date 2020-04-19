# weird-series-task

Create an algorithm and the corresponding program (in C ) to:

Input to program: From the  keyboard, the real numbers X(|X|<1) and E(0<E<1) are entered;

Using a recursive function, an array A is formed  with elements:
 A0 = 1,
 A1  = –X2/2!,
 A2  = X4/4!,
     	.   .   . 
      
up to the number of elements L of array A either satisfies the condition: 
|A[L] – A[L – 1]| <= E  or (if this condition is not satisfied) L = 15;

Output of program: The number  of the elements  of the array A and the elements itself  are printed to the file F with indexes.
