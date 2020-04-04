vl findNearestIndexLeft(const vl& arr){
    ll N = arr.size();
    vl res(N, 0);
    stack<ll> st;
    rep(i, N){
        while(!st.empty() && arr[st.top()] > arr[i]){
            st.pop();
        }
        if(st.empty()){
            res[i] = i;
        }
        else{
            res[i] = st.top();
        }
        st.push(i);
    }
    return res;
}
