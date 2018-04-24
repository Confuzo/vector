template <typename T> class vector
{
public:
	typedef T value_type;
	typedef T* pointer

	vector();
	~vector();
private:
	pointer m_data;
	pointer m_size;
	pointer m_capacity;

	/*
		.reserve()
			0) ver se o tamanho alocado comporta os novos elementos
			1) alocar nova memoria c/ o dobro da original (*temp)
			2) copiar m.data p/ temp
			3) apagar m_data
			4) m_data = temp;
			5) m_size *= 2;
	*/
};