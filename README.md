## Numpy-like C++ Tensor Class for Matrix Algebra

```
  // Initilize 2 x 3 matrix
  float data_a[] = {1,2,3,4,5,6};
  Tensor2D A = Tensor2D(2,3, data_a);
  
  1 2 3
  4 5 6
 
  // Transpose matrix
  Tensor2D B = A.transpose();
  
  1 4
  2 5
  3 6
  
  // Elementwise add
  Tensor2D C = A + A;
  
  2 4 6
  8 10 12
	
  // Elementwise multiply
  Tensor2D D = B * B;
  
  1 16
  4 25
  9 36
	
  // Matrix multiply
  Tensor2D F = Tensor2D::matmul(A,B);
  
  14 32
  32 77
  
  // Read element at postion (0,0)
  float a = A(0,0); // 5
  
  // Write element at postion (0,0)
  B(0,0) = 10;
  
  10 4
  2 5
  3 6
 
  
  
  
```
