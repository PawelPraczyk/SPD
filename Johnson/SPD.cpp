#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

class Job
{
public:
	int Index;
	int MachineId;
	int Time;

	Job(int index, int machineID, int time)
	{
		Index = index;
		MachineId = machineID;
		Time = time;
	}
};
int getCmax(vector<Job>m1, vector<Job>m2)
{
	int a = 0, b = 0, cmax = 0, disparity = 0;
	int i = 1;
	b = m2[0].Time;
	for (i; i < m1.size(); i++)
	{
		a = a + m1[i].Time;
		if (a > b)
		{
			if (m1[i].Time < m2[i - 1].Time)
			{
				disparity = disparity + (m2[i - 1].Time - m1[i].Time);
			}
		}

		else
		{
			if (i != 1)
				b = b + m2[i - 1].Time;
		}

	}
	if (b > a)
	{
		cmax = cmax + m1[0].Time + m2[i - 1].Time;
		cmax = cmax + disparity + b;
	}

	else
	{
		cmax = cmax + disparity + m2[i - 1].Time;
		for (int i = 0; i < m1.size(); i++)
			cmax = cmax + m1[i].Time;
	}



	return cmax;
}

void Minimum(vector<Job> jobs)
{
	vector<Job>M1, M2, M3, virtl, temporary, help;
	int minimum = 999999;
	int a, i = 0;
	bool flag = false;
	virtl = jobs;
	for (int i = 0; i < jobs.size(); i++)
		if (jobs[i].MachineId == 3)
		{
			flag = true;
		}



	if (flag == true)
	{
		virtl.clear();
		for (int i = 0; i < jobs.size(); i++)
		{
			if (jobs[i].MachineId == 1)
				M1.push_back(jobs[i]);
			else if (jobs[i].MachineId == 2)
				M2.push_back(jobs[i]);
			else if (jobs[i].MachineId == 3)
				M3.push_back(jobs[i]);
		}

		for (int i = 0; i < M3.size(); i++)
		{
			M1[i].Time = M1[i].Time + M3[i].Time;
			M2[i].Time = M2[i].Time + M3[i].Time;
			virtl.push_back(M1[i]);
			virtl.push_back(M2[i]);
		}

		M1.clear();
		M2.clear();

	}

	help = virtl;
	//		temporary = virtl;



	while (!virtl.empty())
	{
		a = 0;
		for (i = 0; i< virtl.size(); i++)
		{
			if (virtl[i].Time < minimum)
			{
				minimum = virtl[i].Time;
			}

		}
		while (!(virtl[a].Time == minimum))
			a++;
		temporary.push_back(virtl[a]);
		virtl.erase(virtl.begin() + a);
		if (temporary[0].MachineId == 1)
		{
			M1.push_back(temporary[0]);
		}
		else if (temporary[0].MachineId == 2)
		{
			M2.insert(M2.begin(), temporary[0]);
		}
		for (int j = 0; j < virtl.size(); j++)
		{
			if (virtl[j].Index == temporary[0].Index)
			{
				virtl.erase(virtl.begin() + j);
			}
		}
		minimum = 99999;
		temporary.clear();

	}


	while (!M2.empty()) {
		M1.push_back(M2[0]);
		M2.erase(M2.begin());
	}


	temporary = M1;
	M1.clear();
	M2.clear();
	for (int a = 0; a< temporary.size(); a++)
		for (int b = 0; b < help.size(); b++)
		{
			if (temporary[a].Index == help[b].Index && help[b].MachineId == 1)
				M1.push_back(help[b]);
			else if (temporary[a].Index == help[b].Index && help[b].MachineId == 2)
				M2.push_back(help[b]);
		}
	for (int i = 0; i < M1.size(); i++)
	{
		cout << M1[i].Index << " ";
	}
	int cmax = getCmax(M1, M2);
	cout << "Cmax= " << cmax << endl;
}



int main()
{
	vector<Job>jobs;
	Job job1(1, 1, 11);
	Job job2(1, 2, 4);
	Job job3(2, 1, 12);
	Job job4(2, 2, 3);
	Job job5(3, 1, 4);
	Job job6(3, 2, 13);
	Job job7(4, 1, 2);
	Job job8(4, 2, 1);
	Job job9(1, 3, 6);
	Job job10(2, 3, 3);
	Job job11(3, 3, 7);
	Job job12(4, 3, 9);
	jobs.push_back(job1);
	jobs.push_back(job2);
	jobs.push_back(job3);
	jobs.push_back(job4);
	jobs.push_back(job5);
	jobs.push_back(job6);
	jobs.push_back(job7);
	jobs.push_back(job8);
	jobs.push_back(job9);
	jobs.push_back(job10);
	jobs.push_back(job11);
	jobs.push_back(job12);
	Minimum(jobs);

}