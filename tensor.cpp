#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

class Tensor2D {

  public:
  	Tensor2D(unsigned int rows, unsigned int cols, float* data = nullptr);
  	
  	Tensor2D copy();
  	unsigned int cols();
  	unsigned int rows();
  	Tensor2D& transpose();
  	std::string toString();

  	// Static methods
  	static Tensor2D matmul(const Tensor2D &A, const Tensor2D &B);

  	// Operators
  	Tensor2D operator+(const Tensor2D &other);
  	Tensor2D operator+(const float c);
  	Tensor2D operator-(const Tensor2D &other);
  	Tensor2D operator-(const float c);
  	Tensor2D operator*(const Tensor2D &other);
  	Tensor2D operator*(const float c);
  	//Tensor2D operator/(const Tensor2D &other); 
  	//Tensor2D operator/(const float c);
  	float operator[](unsigned int index);
  	float& operator()(unsigned int x, unsigned int y) const;

  private:
  	// Internal input check
  	static void checkEqualSize(const Tensor2D &A, const Tensor2D &B);
  	static void checkMatMulPossible(const Tensor2D &A, const Tensor2D &B);
  	static void checkInBounds(const Tensor2D &A, unsigned int x, unsigned int y);
    
    float *m_data;
    unsigned int m_rows;
    unsigned int m_cols;

};

Tensor2D::Tensor2D(unsigned int rows, unsigned int cols, float* data){
	m_data = new float[rows*cols]();
	if(data){
		std::memcpy(m_data,data,rows*cols*sizeof(float));
	}
	m_cols = cols;
	m_rows = rows;
}

unsigned int Tensor2D::rows(){
	return m_rows;
}

unsigned int Tensor2D::cols(){
	return m_cols;
}

void Tensor2D::checkInBounds(const Tensor2D &A, unsigned int x, unsigned int y){
	if(x >= A.m_rows || y >= A.m_cols)
	{
		std::cout << "Error: Index out of bounds."<< std::endl;
		throw 0;
	}
}

void Tensor2D::checkEqualSize(const Tensor2D &A, const Tensor2D &B){
	if(A.m_rows != B.m_rows || A.m_cols != B.m_cols)
	{
		std::cout << "Error: " << "Tensors must have the same size" << std::endl;
		throw 0;
	}
}

void Tensor2D::checkMatMulPossible(const Tensor2D &A, const Tensor2D &B){
	if(A.m_cols != B.m_rows)
	{
		std::cout << "MatMult size error: A.cols() != B.rows()" << std::endl;
		throw 0;
	}
}

Tensor2D Tensor2D::copy(){
	Tensor2D copy = Tensor2D(m_rows,m_cols,m_data);
	return copy;
}

Tensor2D& Tensor2D::transpose(){
	// TODO
	return *this;
}

/*
	Static methods
*/

Tensor2D Tensor2D::matmul(const Tensor2D &A, const Tensor2D &B){
	checkMatMulPossible(A,B);
	unsigned int N = A.m_rows;
	unsigned int K = A.m_cols;
	unsigned int M = B.m_cols;

	Tensor2D C = Tensor2D(N,M);
	for(int k = 0; k < K; k++){
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				C(i,j) += A(i,k)*B(k,j);
			}
		}
	}
	return C;
}

/*
	Operators
*/
float Tensor2D::operator[](unsigned int index){
	return m_data[index];
}

float& Tensor2D::operator()(unsigned int x, unsigned int y) const {
	checkInBounds(*this,x,y);
	return m_data[x*m_cols+y];
}


Tensor2D Tensor2D::operator+(const Tensor2D &other){
	checkEqualSize(*this,other);
	Tensor2D result = this->copy();
	for(int i = 0; i < m_rows*m_cols; i++){
		result.m_data[i] += other.m_data[i];
	}
	return result;
}

Tensor2D Tensor2D::operator+(const float c){
	Tensor2D result = this->copy();
	for(int i = 0; i < m_rows*m_cols; i++){
		result.m_data[i] += c;
	}
	return result;
}

Tensor2D Tensor2D::operator-(const Tensor2D &other){
	checkEqualSize(*this,other);
	Tensor2D result = this->copy();
	for(int i = 0; i < m_rows*m_cols; i++){
		result.m_data[i] -= other.m_data[i];
	}
	return result;
}

Tensor2D Tensor2D::operator-(const float c){
	Tensor2D result = this->copy();
	for(int i = 0; i < m_rows*m_cols; i++){
		result.m_data[i] -= c;
	}
	return result;
}


Tensor2D Tensor2D::operator*(const Tensor2D &other){
	checkEqualSize(*this,other);
	Tensor2D result = this->copy();
	for(int i = 0; i < m_rows*m_cols; i++){
		result.m_data[i] *= other.m_data[i];
	}
	return result;
}

Tensor2D Tensor2D::operator*(const float c){
	Tensor2D result = this->copy();
	for(int i = 0; i < m_rows*m_cols; i++){
		result.m_data[i] *= c;
	}
	return result;
}

std::string Tensor2D::toString(){
	std::stringstream ss;

	for(int i = 0; i < m_rows; i++){
		for(int j = 0; j < m_cols; j++){
			ss << std::setprecision(2) << m_data[i*m_cols+j] << " ";
		}
		ss << std::endl;
	}
	return ss.str();
}

int main(){
	float data_a[] = {1,2,3,4,5,6};
	Tensor2D A = Tensor2D(2,3, data_a);
	std::cout << "A:" << std::endl << A.toString() << std::endl;

	float data_b[] = {1,2,3,4,5,6};
	Tensor2D B = Tensor2D(3,2, data_b);
	std::cout << "B:" << std::endl << B.toString() << std::endl;

	Tensor2D C = A + A;
	std::cout << "C = A + A:" << std::endl << C.toString() << std::endl;

	Tensor2D D = C * 2;
	std::cout << "D = C * 2:" << std::endl << D.toString() << std::endl;

	Tensor2D E = B * B;
	std::cout << "E = B * B:" << std::endl << E.toString() << std::endl;


	std::cout << "E(0,0): " << std::to_string(E(0,0)) << std::endl;
	std::cout << "E(1,0): " << std::to_string(E(1,0)) << std::endl;
	std::cout << "E(1,1): " << std::to_string(E(0,1)) << std::endl;
	std::cout << "E(1,1): " << std::to_string(E(1,1)) << std::endl;

	E(0,0) = 2;
	std::cout << "E(0,0): " << std::to_string(E(0,0)) << std::endl;

	Tensor2D F = Tensor2D::matmul(A,B);
	std::cout << "A:" << std::endl << A.toString() << std::endl;
	std::cout << "B:" << std::endl << B.toString() << std::endl;
	std::cout << "F:" << std::endl << F.toString() << std::endl;
}
	
