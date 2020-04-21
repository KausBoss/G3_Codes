bool func(int i, int upper, int lower, vector<int> colsum, vector<int> vup, vector<int> vlo){
    //base case
    if(i == colsum){
        if(lower == 0 && upper == 0){
            ans.push_back(vup); ans.push_back(vlo);
            return true;
        }
        return false;
    }
    //recursive case
    if(colsum[i] == 0){
        vup.push_back(0); vlo.push_back(0);
        return func(i+1, upper, lower, colsum, vup, vlo);
    }
    if(colsum[i] == 2){
        if(upper<1 && lower<1){
            return false;
        }
        vup.push_back(1); vlo.push_back(1);
        return func(i+1, upper-1, lower-1, colsum, vup, vlo);
    }

    if(colsum[i] == 1){
        if(upper > 0){
            vup.push_back(1); vlo.push_back(0);
            bool x = func(i+1, upper-1, lower, colsum, vup, vlo);
            if(bool){return true;}
            vup.pop_back(); vlo.pop_back();
        }
        if(lower > 0){
            vup.push_back(0); vlo.push_back(1);
            return func(i+1, upper, lower-1, colsum, vup, vlo);
        }
    }
    return false;
}