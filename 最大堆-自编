#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <iomanip>
#include <algorithm>
using namespace std;

void makeHeap(vector<int>&);
void pushHeap(vector<int>&,int);
int popHeap(vector<int>&);	
void adjust_down(vector<int>&, int);		//从指定点向下调整，比最大子小就交换
void adjust_up(vector<int>&, int);			//从指定点向上调整，比根大就交换

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	vector<int> maxHp = { 1000,58,44,31,35,56 };
	makeHeap(maxHp);
	pushHeap(maxHp, 59);
	cout << popHeap(maxHp) << endl;
	return 0;
}
void makeHeap(vector<int>& hp)
{
	//从后往前向下调整
	for (int i = (hp.size() - 1) / 2; i >= 1; i--)
		adjust_down(hp, i);
}
void pushHeap(vector<int>& hp, int x)
{
	hp.push_back(x);
	adjust_up(hp, hp.size() - 1);
}
int popHeap(vector<int>& hp)
{
	//把top和最后交换，再删除最后一个，再从top向下调整
	int top = hp[1];
	swap(hp[1], hp[hp.size() - 1]);
	hp.pop_back();
	adjust_down(hp, 1);
	return top;
}
void adjust_down(vector<int>& hp, int par)
{
	int child;
	for (int i = par; i * 2 < hp.size(); i = child)
	{
		child = i * 2;
		if (child+1 < hp.size() && hp[child] < hp[child + 1]) child++;
		if (hp[child] > hp[i])
			swap(hp[child], hp[i]);
		else
			break;
	}
}
void adjust_up(vector<int>& hp, int n)
{
	int parent;
	for (int i = n; i/2 >= 1; i = parent) {
		parent = i / 2;
		if (hp[parent] < hp[i])
			swap(hp[parent], hp[i]);
		else
			break;
	}
}
