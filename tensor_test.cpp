
#include "tensor.hpp"


int main(){
	//float data_a[] = {1,2,3,4,5,6};
	//Tensor A = Tensor(2,3, data_a);
  Tensor A = Tensor::randn(4,5);
	std::cout << "A:" << std::endl << A.toString() << std::endl;

	//float data_b[] = {1,2,3,4,5,6};
	//Tensor B = Tensor(3,2, data_b);
	Tensor B = A.transpose();

	//std::cout << "A:" << std::endl << A.toString() << std::endl;
	//Tensor B = ;
	std::cout << "B:" << std::endl << B.toString() << std::endl;

	Tensor C = A + A;
	std::cout << "C = A + A:" << std::endl << C.toString() << std::endl;

	Tensor D = C * 2;
	std::cout << "D = C * 2:" << std::endl << D.toString() << std::endl;

	Tensor E = B * B;
	std::cout << "E = B * B:" << std::endl << E.toString() << std::endl;


	std::cout << "E(0,0): " << std::to_string(E(0,0)) << std::endl;
	std::cout << "E(1,0): " << std::to_string(E(1,0)) << std::endl;
	std::cout << "E(1,1): " << std::to_string(E(0,1)) << std::endl;
	std::cout << "E(1,1): " << std::to_string(E(1,1)) << std::endl;

	E(0,0) = 2;
	std::cout << "E(0,0): " << std::to_string(E(0,0)) << std::endl;

	Tensor F = Tensor::matmul(A,B);
	std::cout << "A:" << std::endl << A.toString() << std::endl;
	std::cout << "B:" << std::endl << B.toString() << std::endl;
	std::cout << "F:" << std::endl << F.toString() << std::endl;
}
	
