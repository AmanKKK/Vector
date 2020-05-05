using namespace std;

// стратегия изменения capacity
enum class ResizeStrategy {
	ADDITIVE,
	MULTIPLICATIVE,
};

// тип значений в векторе
// потом будет заменен на шаблон
typedef double ValueType;

class MyVector
{
private:

	ValueType* m_data = nullptr; // Указатель на массив _data;
	size_t m_size;	// Длина массива;
	ResizeStrategy m_method; //метод изменения длины массива;
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
	
	
	}//+// Конструктор (без параметров)(по умолчанию). */
	MyVector(size_t size=0,/* ValueType value,*/ ResizeStrategy option=ResizeStrategy::MULTIPLICATIVE,const float coef = 1.5f) {
		m_size = size;
		m_capacity = m_size;
		m_method = option;
		m_coefficient = coef;
		m_data = new ValueType[m_size]();
	}

	MyVector(const MyVector& copy);//+ конструктор копирования 
	MyVector& operator=(const MyVector& copy);//+ перегрузка оператора 

	~MyVector();

	// для умненьких — реализовать конструктор и оператор для перемещения

	size_t capacity() const;//++
	size_t size() const; //++
	float loadFactor();

	// доступ к элементу, 
	// должен работать за O(1)
	const ValueType& operator[](const size_t index) const; //+++

	// добавить в конец,
	// должен работать за amort(O(1))
	void pushBack(const ValueType& value);
	// вставить,
	// должен работать за O(n)
	void insert(const size_t i, const ValueType& value);	// версия для одного значения
	void insert(const size_t i, const MyVector& value);		// версия для вектора

	// удалить с конца,
	// должен работать за amort(O(1))
	void popBack();
	void ForpopBack();
	// удалить
	// должен работать за O(n)
	void erase(const size_t i);
	void erase(const size_t i, const size_t len);			// удалить len элементов начиная с i

	// найти элемент,
	// должен работать за O(n)
	// если isBegin == true, найти индекс первого элемента, равного value, иначе последнего
	// если искомого элемента нет, вернуть -1
	 const long long int find(const ValueType& value, bool isBegin);

	// зарезервировать память (принудительно задать capacity)
	void reserve(const size_t capacity);

	// изменить размер
	// если новый размер больше текущего, то новые элементы забиваются дефолтными значениями
	// если меньше - обрезаем вектор
	void resize(const size_t size, const ValueType);

	// очистка вектора, без изменения capacity
	void clear();

	void PrintData(); //необходим для получения содержимого вектора;
};