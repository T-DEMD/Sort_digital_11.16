#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
using namespace std;

// Глава 11, упр. 16 (стр. 460). complete.

double str_to_double(string s)
{
	istringstream is{ s };
	double d;
	is >> d;
	if (!is)
	{
		cerr;
	}
	return d;
}

int main()
{
	string file_name_1;
	string file_name_2;
	cout << "Enter file name for open: ";
	cin >> file_name_1;

	ifstream ifs(file_name_1);
	if (!ifs)
	{
		cerr;
	}
	cout << "Enter file name for record: ";
	cin >> file_name_2;

	vector<string>vs;

	string digit = "";
	for (char ch; ifs.get(ch);)
	{
		if (isspace(ch) && digit!="")
		{
			vs.push_back(digit);
			digit = "";
		}
		if (isalpha(ch))
		{
			digit += ch;
		}
		if (isdigit(ch))
		{
			digit += ch;
		}
	}
	vs.push_back(digit);

	ifs.close();

	ofstream ost(file_name_2);
	if (!ost)
	{
		cerr;
	}

	string s;
	double d = 0;
	vector<double> vd;
	for (int i = 0; i < vs.size(); i++)
	{
		s = vs[i];
		char c;
		d = str_to_double(s);
		for (int i = 0; i < s.size(); i++)
		{
			c = s[i];
			if (isalpha(c))
			{
				d = 0.01;
			}
		}
		if (d>0.01 || d<0.01)
		{
			vd.push_back(d);
		}
	}

	sort(vd.begin(), vd.end());

	int iter = 0;
	for (int i = 0; i < vd.size(); i++)
	{
		for (int y = i+1; y < vd.size(); y++)
		{
			if (vd[i]==vd[y])
			{
				i++;
				iter += 1;
			}
		}
		ost << vd[i] << "\t" << iter << endl;
		iter = 0;
	}

	return 0;
}