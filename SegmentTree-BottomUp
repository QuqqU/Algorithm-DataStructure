class SegmentTree { // base 0
public:
	int index;
	int initValue;
	vector<ll> node;

	SegmentTree(int n) : index(1), initValue(0) {
		while(index < n) index <<= 1;
		node.resize(index * 4, initValue);
	}  

	ll query(int nl, int nr) {
		ll rlt = initValue;
		nl += index, nr += index;
		while(nl <= nr) {
			if(nl & 1) rlt += node[nl++];
			if(!(nr & 1)) rlt += node[nr--];
			nl >>= 1, nr >>= 1;
		}		
		return rlt;
	}

	void update(int idx, int dif) {
		int n = index + idx;
		node[n] = dif;
		n >>= 1;
		while(n) {
			node[n] = node[n * 2] + node[n * 2 + 1];
			n >>= 1;
		}
	}
};
