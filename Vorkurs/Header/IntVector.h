typedef struct {
	size_t capacity;
	size_t size;
	int vector;
} IntVector;

IntVector *IntVector_new(size_t capacity);

Void IntVector_delete(IntVector *vector);

int IntVector_push_back(IntVector *vector, int val);

int IntVector_get(IntVector *vector, size_t index);

void IntVector_set(IntVector *vector, size_t index, int value);

size_t IntVector_size(IntVector *vector);
