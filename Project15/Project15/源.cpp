#include <stdio.h>
#include <malloc.h>

#define ljx  777
#define MAX(a,b) (a)>(b)?(a):(b)


int file_write(int argc, char* argv[])
{
	FILE* file = NULL;
	fopen_s(&file, argv[1], "rb");
	if (argc != 3)
		return -1;
	if (file == NULL)
		return -2;
	long file_size;
	fseek(file, 0, SEEK_END);
	file_size = ftell(file);
	fseek(file, 0, SEEK_SET);
	int file_pos = ftell(file);
	printf("file_pos==%d", file_pos);
	char* buffer = (char*)malloc(file_size);
	if (buffer == NULL)
		return -3;

	fread(buffer, 1, file_size, file);
	fclose(file);
	file = NULL;
	fopen_s(&file, argv[2], "wb");
	if (file == NULL)
		return -2;
	fwrite(buffer, 1, file_size, file);
	fclose(file);
}
void test() {
	char a[3][3] = {
		{'a','b','c'},
		{'d','e','f'},
		{'g','h','i'},
	};
	int row = sizeof(a) / sizeof(a[0]);
	int col = sizeof(a[0]) / sizeof(a[0][0]);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("cur_char=%c\n", a[i][j]);
		}
	}
}

void generate_matrix(char abc[4][13])
{
    int index = 0;
    int row = 4;
    int col = 13;

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            if (index < 26)
            {
                abc[i][j] = 'A' + index;
            }
            else if (index >= 26)
            {
                abc[i][j] = 'a' + index - 26;
            }
            index++;
        }

    }
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            printf("cur_char==%c  ", abc[i][j]);
        }
        printf("\n");
    }

}

void change_matrix(char a[4][13])
{
    int row = sizeof(a) / sizeof(a[0]);
    int col = sizeof(a[0]) / sizeof(a[0][0]);
	printf(" sizeof(a)=%d\n", sizeof(a));
	printf(" sizeof(a[0])=%d\n", sizeof(a[0]));
	printf(" sizeof(a[0][0])=%d\n", sizeof(a[0][0]));
	printf("row=%d col=%d\n", row, col);


    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] > 'Z')
                a[i][j] -= 32;
            else
                a[i][j] += 32;

        }
    }




}


int main(int argc, char* argv[])
{	
	//int a = 2;
	//int b = a + ljx;
	//int c = MAX(b, a);
	//printf("a=%d b=%d c=%d", a, b, c);
	char abc[4][13];

	generate_matrix(abc);
	change_matrix(abc);






	return 0;


}