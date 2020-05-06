typedef struct HTNode{
    int weight;
    int parent;
    int lchild;
    int rchild;
    HTNode() { weight = parent = lchild = rchild = -1; }
}HTNode;

void SelectTwoMin(int upbound, vector<HTNode>& HT, int& s1, int& s2);
void creatHuffman(vector<HTNode>& HT, int n);

int lengthCount(vector<HTNode>& HT, int i)
{
    int cnt = 0;
    while (HT[i].parent != -1)
    {
        i = HT[i].parent;
        cnt++;
    }
    return cnt;
}
void SelectTwoMin(int upbound, vector<HTNode>& HT, int& s1, int& s2)
{
    int x1 = -1, x2 = -1;
    long long m1 = 1e10;
    long long m2 = 1e10;
    for (int i = 0; i < upbound; i++)
    {
        if (HT[i].parent == -1 && HT[i].weight < m1)
        {
            if (x1 != -1) {
                x2 = x1;
                m2 = m1;
            }
            m1 = HT[i].weight;
            x1 = i;
        }
        else if (HT[i].parent == -1 && HT[i].weight < m2)
        {
            m2 = HT[i].weight;
            x2 = i;
        }
    }
    s1 = x1;
    s2 = x2;
}
void creatHuffman(vector<HTNode>& HT, int n)
{
    int s1, s2;
    for (int i = 0; i < n-1; i++)
    {
        SelectTwoMin(n+i,HT, s1, s2);
        HT[n + i].lchild = s1;
        HT[n + i].rchild = s2;
        HT[n + i].weight = HT[s1].weight + HT[s2].weight;
        HT[s1].parent = HT[s2].parent = n + i;
    }
}
