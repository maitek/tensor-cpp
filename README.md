## Numpy-like C++ Tensor Class for Matrix Algebra

```
  #include "tensor.hpp"
  
  // Initilize 2 x 3 matrix
  float data_a[] = {1,2,3,4,5,6};
  Tensor A = Tensor(2,3, data_a);
  
  1 2 3
  4 5 6
 
  // Transpose matrix
  Tensor B = A.transpose();
  
  1 4
  2 5
  3 6
  
  // Elementwise add
  Tensor C = A + A;
  
  2 4 6
  8 10 12
	
  // Elementwise multiply
  Tensor D = B * B;
  
  1 16
  4 25
  9 36
	
  // Matrix multiply
  Tensor F = Tensor::matmul(A,B);
  
  14 32
  32 77
  
  // Read element at postion (0,0)
  float a = A(0,0); // 1
  
  // Write element at postion (0,0)
  B(0,0) = 10;
  
  10 4
  2 5
  3 6
 
  
  
  
```
