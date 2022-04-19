
/**
 * 21
 * 
 * {8, 2, 10, 12, 7, 0, 10, 8}
 *  0. 1.  2. 3.  4. 5.  6  7
 * 
 *       20
 *     (0,7)
 *     20       16
 *   (0, 3)   (4,7)
 * 
 * 8        20      7      16
 * (0, 1) (2, 3)   (4, 5) (6, 7)
 * 
 * 
 *   n + n/2 + n/4 ..
 *    n(1 + 1/2 + 1)
 * 
 * nlogn
 * 
 *  n
 *  n/2 + n/2
 * 
 * n/4 n/  +   n/4
 * 
 * n/8 n/
  * 
 * 
 * */

int dnc(int i, int j, vector<int> &h){
	if(i == j){
		return h[i];
	}
	
	int mid = (i+j)/2;
	int ans = INT_MIN;
	ans = max(ans, dnc(i, mid, h));
    ans = max(ans, dnc(mid+1, j, h));
	
	int b = mid, e = mid+1;
	
	int minh = min(h[b], h[e]);
	ans = max(ans, minh * (e - b + 1));
	
	
	while( b > i && e < j ){
		if(h[b-1] >= h[e + 1]){
			--b;
			minh = min(h[b], minh);
		} else {
			e++;
			minh = min(h[e], minh);	
		}
		ans = max(minh * (e-b+1), ans);	
	}
	
	while(b > i){
		--b;
		minh = min(h[b], minh);
		ans = max(minh * (e-b+1), ans);		
	}
	
	while(e > j){
		++e;
		minh = min(h[e], minh);
		ans = max(minh * (e-b+1), ans);	
	}
	
	return ans;
}

int getLargestArea(vector<int> &heights) {
    // add your logic here
	return dnc(0, heights.size()-1, heights);
	
}

