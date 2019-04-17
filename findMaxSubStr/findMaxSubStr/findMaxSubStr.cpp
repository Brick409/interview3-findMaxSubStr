// findMaxSubStr.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
#define maxsize 100

typedef struct str  
{
	char str[maxsize + 1];
	int length;  //字符串长度
}Str;

/* 求字符串之最长无重复子串 */

/*
想到无重复，可以想到可以使用hash，当新的字符来了，有冲突，就说明前面是有重复的。
算法思想：两次循环得到所有的子串，用hash判断是否重复。
*/
/* 查找该ele字符是否在字符串数组中 */
bool strHasEle(char * str, char ele)
{
	int len = strlen(str);

	for (int i=0;i<len;i++)
	{
		if (str[i]==ele)
		{
			return true;
		}
	}

	return false;
}
/* 求字符串之最长无重复子串 */
/*
str：原字符串
dst：最大子串
return 最大子串长度
*/
int lengthOfLongestSubstring(char *str, char *dst)
{
	if (str == NULL)
	{
		return -1;
	}
	
	int lenth = strlen(str);
	int tmpfrom = 0;  //临时变量
	int from = 0;     //当前子串起始位置
	int to = 1;      //当前子串结束位置
	int subLen = 1;     //子串长度
	int maxLen = 1; //最大子串长度
	int k = 0;
	//字符串个数为1的情况
	if (lenth==1)
	{
		dst[0] = str[0];
		return lenth;
	}

	dst[k++] = str[0];

	while (to<lenth)
	{
		if (strHasEle (dst, str[to]))
		{
			subLen = to - from;
			tmpfrom = from;
			from = to;
			to++;
			if (subLen >maxLen)
			{
				k = 0;
				maxLen = subLen;

				for (int j=tmpfrom;j<to;)
				{
					dst[k++] = str[j++];
				}
			}
		}
		else
		{
			dst[k++] = str[to++];
			subLen++;
		}
	}

	return maxLen;
}


int main()
{
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	int maxSublen = 0;

	cin >> str1;

	
	maxSublen = lengthOfLongestSubstring(str1, str2);

	cout << "无重复最大子串长度为：" << maxSublen << endl;
	
	for (int i=0; i < maxSublen; i++)
	{
		cout << str2[i];
	}
	cout<< endl;

    std::cout << "Hello World!\n"; 

	system("pause");
	
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
