#include "stdafx.h"

static bool get_element_more_than_half(int* elements, int element_count, int* result)
{
	if(0 == elements || 2 >= element_count || 0 == result)
		return false;

	int idx_mid = element_count / 2;
	int element_mid = elements[idx_mid];		// x

	int idx_first = idx_mid;  // position of the first appearance of x;

	int idx_low = 0;		// low bound of binary search
	int idx_high = idx_mid;	// high bound of binary search
	while(idx_low < idx_high)
	{
		int idx_tmp = (idx_low + idx_high) / 2;
		if (elements[idx_tmp] == element_mid)
		{
			idx_high = idx_first = idx_tmp;
		}
		else if(elements[idx_tmp] < element_mid)
		{
			idx_low = idx_tmp + 1;
		}
	}

	printf("first position : %d\r\n", idx_first);

	if (elements[idx_first + element_count / 2] == element_mid)
	{
		*result = element_mid;
		return true;
	}

	return false;
}

static int test_data0[] = {1,1,1};
static int test_data1[] = {1,2,2};
static int test_data2[] = {1,1,2};
static int test_data3[] = {1,1,2,2};
static int test_data4[] = {1,1,1,2};
static int test_data5[] = {1,2,2,2};

static int test_data6[] = {1,2,3,4,4,4,4,5};
static int test_data7[] = {1,2,3,4,4,4,4,4};
static int test_data8[] = {1,2,3,4,4,4,4,4,5};
static int test_data9[] = {4,4,4,4,4,4,4,4,5};

#define ARRAYSIZE(x) (sizeof(x)/sizeof(x[0]))
#define TEST_DATA_CASE(x) { x, ARRAYSIZE(x) },

struct  
{
	int* data;
	int  size;
}test_datas[] = {
	TEST_DATA_CASE(test_data0)
	TEST_DATA_CASE(test_data1)
	TEST_DATA_CASE(test_data2)
	TEST_DATA_CASE(test_data3)
	TEST_DATA_CASE(test_data4)
	TEST_DATA_CASE(test_data5)
	TEST_DATA_CASE(test_data6)
	TEST_DATA_CASE(test_data7)
	TEST_DATA_CASE(test_data8)
	TEST_DATA_CASE(test_data9)
};

int _tmain_ms_1(int argc, _TCHAR* argv[])
{
	for (int i = 0; i < ARRAYSIZE(test_datas); ++i)
	{
		printf("test data : ");
		for (int j = 0; j < test_datas[i].size; ++j)
		{
			printf(" %d", test_datas[i].data[j]);
		}
		printf("\r\n");
		
		int result;
		if(get_element_more_than_half(test_datas[i].data, test_datas[i].size, &result))
		{
			printf("result : %d\r\n\r\n", result);
		}
		else
		{
			printf("no one appearance more than half times\r\n\r\n");
		}
	}
		
	getchar();
	return 0;
}

