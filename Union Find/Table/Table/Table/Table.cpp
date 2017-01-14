const int size = 100;

class Table {
private :
	int* sets;
public:
	Table() {
		sets = new int[size];
		for (int i = 0;i < size;i++) {
			sets[i] = -1;
		}
	}
	void Union(int s1, int s2, int s3) {
		for (int i = 0;i < size;i++) {
			if (sets[i] == s1 || sets[i] == s2) {
				sets[i] = s3;
			}
		}
	}

	int Find(int val) {
		return sets[val];
	}

	void Insert(int val, int set) {
		sets[val] = set;
	}

};