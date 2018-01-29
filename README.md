## Numpy-like C++ Tensor Class for Matrix Algebra

```
  // Initilize 2 x 3 matrix
  float data_a[] = {1,2,3,4,5,6};
  Tensor2D A = Tensor2D(2,3, data_a);
  
  // Copy matrix
  Tensor2D B = A.copy();
  
  // Elementwise add
  Tensor2D C = A + B;
	
  // Elementwise multiply
  Tensor2D D = C * 2;
	
  // Matrix multiply
  Tensor2D F = Tensor2D::matmul(A,B);
```
