// Edit Distance.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define length(a) sizeof(a)
using namespace std;
int min_3s(int a, int b, int c);
int main()
{
	ifstream input;
	ofstream output;
	input.open("input.txt");
	output.open("output.txt", ios::trunc);
	char s1[100];
	char s2[100];
	input.getline(s1, sizeof(s1));
	input.getline(s2, sizeof(s2));
	int m = strlen(s1);
	int n = strlen(s2);
	cout << "you want to change the string \n S1 = " << s1 << " to ";
	cout << "the string \n S2 =" << s2 << endl;
	int **d = new int*[m + 1];
	for (int i = 0; i <= m; i++)
		d[i] = new int[n + 1];
	for (int i = 0; i <= m; i++)
		d[i][0] = i;
	for (int j = 0; j <= n; j++)
		d[0][j] = j;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = min_3s(d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1), d[i - 1][j] + 1, d[i][j - 1] + 1);
			//cout << d[i][j] << ' '; // view the result for debug
		}
		cout << endl;
	}
	cout << "we get the final result d[" << m << "][" << n << "] = " << d[m][n] << endl;
	output << d[m][n] << endl;
	output.close();
	input.close();
	getchar();
	getchar();
	return 0;
}
int min_3s(int a, int b, int c) {
	int temp = (a > b ? b : a);
	temp = (temp > c ? c : temp);
	return temp;
}


