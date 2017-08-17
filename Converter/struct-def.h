//struct student (Student) holds the information that the binary file will have.
typedef struct student {
	unsigned char firstLen;
	char firstName[256];
	unsigned char lastLen;
	char lastName[256];
	unsigned int id;
	float gpa;
} Student;