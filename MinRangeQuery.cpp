/*
	Range query DS
	Common usecases : Min/Max/Sum in a range

	- Segment tree devides the entire range(root node) into subranges(each of equal size) and stores the result as node values
	- Result is calculated in a bottom up fashion starting from indivisable ranges
	- Results are stored in an array where each index represents level order position(assuming complete tree) of the node(a given range)

	build(idx, low, high) Time O(n)
	- Use left and right population at each level

	query(idx, low, high, rangeLow, rangeHigh) Time O(log n)
	- No overlap(don't use the result) - Partial overlap(use left and right results) - Complete overlap(use the result as it is) 

	update(idx, low, high, id, val) Time O(log n)
	- Update required index and following nodes going upwards	
*/

class SegTree {
	vector<int> seg;
	int n;
	void build(int idx, int low, int high, vector<int> &arr) {
		if(low == high) {
			seg[idx] = arr[low];
			return;
		}
		else {
			int mid = (low + high) / 2;
			build(2 * idx + 1, low, mid, arr);
			build(2 * idx + 2, mid + 1, high, arr);
			// build logic
			seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
		}
	}

	int query(int idx, int low, int high, int rangeLow, int rangeHigh) {
		// no overlap
		if(high < rangeLow or low > rangeHigh) {			
			// no overlap result
			return INT_MAX;
		}
		// complete overlap
		else if(low >= rangeLow and high <= rangeHigh) {
			return seg[idx];
		}
		// partial overlap
		else {
			int mid = (low + high) / 2;
			int leftResult = query(2 * idx + 1, low, mid, rangeLow, rangeHigh);
			int rightResult = query(2 * idx + 2, mid + 1, high, rangeLow, rangeHigh);
			// query logic
			return min(leftResult, rightResult);
		}
	}

	void update(int idx, int low, int high, int id, int val) {
		if(low == high) {
			seg[idx] = val;
			return;
		}
		int mid = (low + high) / 2;
		if(id <= mid) update(2 * idx + 1, low, mid, id, val);		
		else update(2 * idx + 2, mid + 1, high, id, val);		
		// updation logic
		seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
	}


	public:
	SegTree(int n) : n(n) {
		seg.resize(4 * n);
	}
	void build(vector<int> &arr) {
		build(0, 0, n - 1, arr);
	}
	int query(int rangeLow, int rangeHigh) {
		return query(0, 0, n - 1, rangeLow, rangeHigh);
	}
	void update(int id, int val) {
		update(0, 0, n - 1, id, val);
	}
};


