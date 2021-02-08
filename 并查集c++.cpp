class Set
{
	int root[MAXSIZE];
public:
	int GetRoot(int c) {
		if (root[c] < 0)
			return c;
		else
			return root[c] = GetRoot(root[c]);
	}
	void Union(int a, int b) {
		int Ra = GetRoot(a);
		int Rb = GetRoot(b);
		if (abs(root[Ra]) > abs(root[Rb])) {
			root[Ra] += root[Rb];
			root[Rb] = Ra;
		}
		else {
			root[Rb] += root[Ra];
			root[Ra] = Rb;
		}
	}
	bool IsSameUnion(int a, int b)	{
		int Ra = GetRoot(a);
		int Rb = GetRoot(b);
		if (Ra == Rb) {
			if (Ra == -1)
				return false;
			else
				return true;
		}
		else
			return (Ra == b || Rb == a);
	}
	void Init(int N) {
		for (int i = 0; i <= N; i++) {
			root[i] = -1;
		}
	}
};
