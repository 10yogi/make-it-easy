/**
 * 
 * 
 * 
 * 
 * */

int getLargestArea(vector<int> &heights) {
    // add your logic here
	
	stack<int> st;
	int mxa = 0;
	
	for(int i =0; i<heights.size(); ++i){
		
		while(st.size() > 0 && heights[st.top()] > heights[i] ){
			int h = heights[st.top()];
			st.pop();
			
			int rsi = i;
			int lsi = st.size()>0 ? st.top(): -1;
			
			mxa = max(mxa, (rsi - lsi -1) * h);
		}
		
		st.push(i);		
	}
	
	while(st.size() > 0){
		int rsi = heights.size();
		
		int h = heights[st.top()];
		st.pop();
		
		int lsi = st.size()>0 ? st.top(): -1;
		
		mxa = max(mxa, (rsi - lsi -1) * h);
		
		
	}
	
	return mxa;
	
}
