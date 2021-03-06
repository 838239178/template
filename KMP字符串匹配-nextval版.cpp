/*返回模式串在主串的所有下标（存放在数组中）*/
vector<int> KMP(string pattern, string text)
{
//make next
	int n = pattern.size();
	vector<int> next(n + 1, 0);
	for (int i = 1;i < n;i++)
	{
		int j = i;
		while (j > 0)
		{
			j = next[j];
			if (pattern[i] == pattern[j])
			{
				next[i + 1] = j + 1;
				break;
			}
		}
	}
	//make nextval
	vector<int> nextval(n+1, 0);
	nextval[0] = -1;
	for(int i = 1; i<n; i++)
	{
		if(pattern[i] == pattern[next[i]])
		{
			nextval[i] = nextval[next[i]];
		}
		else
		{
			nextval[i] = next[i];
		}
	}
	//kmp
	vector<int> positions;
	int m = text.size();
	for (int i = 0, j = 0;i < m;i++) //移动主串
	{
		if (j < n && (j==-1 || text[i] == pattern[j])) j++;  //如果相同，移动模式串和主串
		else
		{//如果不同就移动到最大公共前后缀处
			while (j > 0)
			{
				j = next[j];
				if (j==-1 || text[i] == pattern[j])
				{//移动到的位置和主串当前位置相同就从这里的下一位开始新一轮比较
					j++;
					break;
				}
			}
		}
		if (j == n)
			positions.push_back(i - j + 1); //下标
	}
	return positions;
}
