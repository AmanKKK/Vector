using namespace std;

// ��������� ��������� capacity
enum class ResizeStrategy {
	ADDITIVE,
	MULTIPLICATIVE,
};

// ��� �������� � �������
// ����� ����� ������� �� ������
typedef double ValueType;

class MyVector
{
private:

	ValueType* m_data = nullptr; // ��������� �� ������ _data;
	size_t m_size;	// ����� �������;
	ResizeStrategy m_method; //����� ��������� ����� �������;
	float m_coefficient;
	size_t m_capacity;

public:


	/*MyVector(size_t size = 0, ResizeStrategy option = ResizeStrategy::MULTIPLICATIVE, const float coef = 1.5f)
	{
		
		m_size = size;
		m_capacity = m_size;
		m_method = option;
		m_coefficient = coef;
		m_data = new ValueType[m_size];
	
	
	}//+// ����������� (��� ����������)(�� ���������). */
	MyVector(size_t size=0,/* ValueType value,*/ ResizeStrategy option=ResizeStrategy::MULTIPLICATIVE,const float coef = 1.5f) {
		m_size = size;
		m_capacity = m_size;
		m_method = option;
		m_coefficient = coef;
		m_data = new ValueType[m_size]();
	}

	MyVector(const MyVector& copy);//+ ����������� ����������� 
	MyVector& operator=(const MyVector& copy);//+ ���������� ��������� 

	~MyVector();

	// ��� ��������� � ����������� ����������� � �������� ��� �����������

	size_t capacity() const;//++
	size_t size() const; //++
	float loadFactor();

	// ������ � ��������, 
	// ������ �������� �� O(1)
	const ValueType& operator[](const size_t index) const; //+++

	// �������� � �����,
	// ������ �������� �� amort(O(1))
	void pushBack(const ValueType& value);
	// ��������,
	// ������ �������� �� O(n)
	void insert(const size_t i, const ValueType& value);	// ������ ��� ������ ��������
	void insert(const size_t i, const MyVector& value);		// ������ ��� �������

	// ������� � �����,
	// ������ �������� �� amort(O(1))
	void popBack();
	void ForpopBack();
	// �������
	// ������ �������� �� O(n)
	void erase(const size_t i);
	void erase(const size_t i, const size_t len);			// ������� len ��������� ������� � i

	// ����� �������,
	// ������ �������� �� O(n)
	// ���� isBegin == true, ����� ������ ������� ��������, ������� value, ����� ����������
	// ���� �������� �������� ���, ������� -1
	 const long long int find(const ValueType& value, bool isBegin);

	// ��������������� ������ (������������� ������ capacity)
	void reserve(const size_t capacity);

	// �������� ������
	// ���� ����� ������ ������ ��������, �� ����� �������� ���������� ���������� ����������
	// ���� ������ - �������� ������
	void resize(const size_t size, const ValueType);

	// ������� �������, ��� ��������� capacity
	void clear();

	void PrintData(); //��������� ��� ��������� ����������� �������;
};